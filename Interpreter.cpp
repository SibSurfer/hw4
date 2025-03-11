#include "Interpreter.h"
#include "AST.h"
#include "cereal/archives/json.hpp"
#include <cassert>

using namespace mysym;

static std::shared_ptr<Expressions>
processExpr(std::shared_ptr<const Expression> expression,
         const SymbolicMemory &memory) {
  if (auto *varRef = dynamic_cast<const VarRef *>(expression.get()))
    return memory.get(varRef->identifier);
  if (auto *intConst = dynamic_cast<const IntConstant *>(expression.get()))
    return std::make_shared<IntConst>(intConst->value);
  if (auto *boolConst = dynamic_cast<const BoolConstant *>(expression.get()))
    return std::make_shared<BoolConst>(boolConst->value);
  if (auto *unop = dynamic_cast<const UnOp *>(expression.get())) {
    assert(unop->kind == UO_Neg);
    auto subExpr =
        std::dynamic_pointer_cast<BoolExpression>(processExpr(unop->subExpr, memory));
    assert(subExpr);
    return std::make_shared<BoolNeg>(std::move(subExpr));
  }
  if (auto *binop = dynamic_cast<const BinOp *>(expression.get())) {
    auto lhs = processExpr(binop->lhs, memory);
    auto rhs = processExpr(binop->rhs, memory);
    switch (binop->kind) {
    case BO_Add: {
      return std::make_shared<IntAdd>(
          std::dynamic_pointer_cast<IntExpression>(lhs),
          std::dynamic_pointer_cast<IntExpression>(rhs));
    }
    case BO_Sub: {
      return std::make_shared<IntSub>(
          std::dynamic_pointer_cast<IntExpression>(lhs),
          std::dynamic_pointer_cast<IntExpression>(rhs));
    }
    case BO_Lt: {
      return std::make_shared<IntLess>(
          std::dynamic_pointer_cast<IntExpression>(lhs),
          std::dynamic_pointer_cast<IntExpression>(rhs));
    }
    case BO_Gt: {
      return std::make_shared<IntGreater>(
          std::dynamic_pointer_cast<IntExpression>(lhs),
          std::dynamic_pointer_cast<IntExpression>(rhs));
    }
    case BO_LAnd: {
      return std::make_shared<BoolAnd>(
          std::dynamic_pointer_cast<BoolExpression>(lhs),
          std::dynamic_pointer_cast<BoolExpression>(rhs));
    }
    case BO_LOr: {
      return std::make_shared<BoolOr>(
          std::dynamic_pointer_cast<BoolExpression>(lhs),
          std::dynamic_pointer_cast<BoolExpression>(rhs));
    }
    default: {
      throw std::runtime_error("wrong expression");
    }
    }
  }
  throw std::runtime_error("wrong expression");
}

void SymbolicExecutionResult::save(cereal::JSONOutputArchive &out) const {
  out(cereal::make_nvp("values", memory),
      cereal::make_nvp("pc", *pc),
      cereal::make_nvp("result", *result));
}

namespace {

struct State {
  std::shared_ptr<Function> function;
  SymbolicMemory memory;
  std::vector<std::shared_ptr<BoolExpression>> pc;

  std::vector<std::shared_ptr<Statement>> statementStack;

  void addAll(const std::vector<std::shared_ptr<Statement>> &statements);

  State(std::shared_ptr<Function> function);
};

class Interpreter {
public:
  Interpreter(std::shared_ptr<Function> function);

  void execute();

  std::vector<SymbolicExecutionResult> takeResults() { return std::move(results); }

private:
  void step(std::shared_ptr<State> state);

private:
  std::shared_ptr<Function> function;
  std::vector<SymbolicExecutionResult> results;
  std::vector<std::shared_ptr<State>> forks;
};

} 

State::State(std::shared_ptr<Function> function)
    : function(function), memory(function) {
  addAll(function->body);
}

void State::addAll(const std::vector<std::shared_ptr<Statement>> &statements) {
  for (int i = statements.size() - 1; i >= 0; --i)
    statementStack.emplace_back(statements[i]);
}

Interpreter::Interpreter(std::shared_ptr<Function> function)
    : function(function) {}

void Interpreter::execute() {
  forks.emplace_back(std::make_shared<State>(function));
  while (!forks.empty()) {
    std::shared_ptr<State> fork = std::move(forks.back());
    forks.pop_back();
    while (!fork->statementStack.empty()) {
      step(fork);
    }
    auto result = ::processExpr(function->returnValue, fork->memory);
    results.emplace_back(SymbolicExecutionResult{
        .memory = fork->memory,
        .pc = conjunction(fork->pc),
        .result = std::move(result),
    });
  }
}

void Interpreter::step(std::shared_ptr<State> state) {
  auto stmt = std::move(state->statementStack.back());
  state->statementStack.pop_back();
  if (auto *assignment = dynamic_cast<const Assignment *>(stmt.get())) {
    auto value = processExpr(assignment->value, state->memory);
    state->memory.set(assignment->var, std::move(value));
    return;
  }
  if (auto *ifstmt = dynamic_cast<const IfStmt *>(stmt.get())) {
    auto condition = std::dynamic_pointer_cast<BoolExpression>(
        processExpr(ifstmt->condition, state->memory));
    assert(condition);
    auto fork = std::make_shared<State>(*state);
    state->pc.push_back(condition);
    state->addAll(ifstmt->thenBlock);
    fork->pc.push_back(std::make_shared<BoolNeg>(condition));
    fork->addAll(ifstmt->elseBlock);
    forks.emplace_back(std::move(fork));
    return;
  }
  throw std::runtime_error("failed to interpret invalid statement");
}

std::vector<SymbolicExecutionResult>
mysym::execute(std::shared_ptr<Function> function) {
  Interpreter interpreter(std::move(function));
  interpreter.execute();
  return interpreter.takeResults();
}