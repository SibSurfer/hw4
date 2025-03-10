#include "ASTBuilder.h"
#include "AST.h"
#include "fmt/format.h"
#include <optional>

using namespace antlr4;
using namespace mysym;

namespace {

class ASTBuilderImpl : public IASTBuilder {
public:
  ASTBuilderImpl() : function(std::make_shared<Function>()) {}
  ~ASTBuilderImpl() override = default;

  void enterFunction(LangParser::FunctionContext *ctx) override;

  void enterParamdecl(LangParser::ParamdeclContext *ctx) override;

  void exitBody(LangParser::BodyContext *ctx) override;

  void exitReturnstmt(LangParser::ReturnstmtContext *ctx) override;

  void exitIfstmt(LangParser::IfstmtContext *ctx) override;

  void exitAssign(LangParser::AssignContext *ctx) override;

  void exitBinoplorexpr(LangParser::BinoplorexprContext *ctx) override;

  void exitBinoplandexpr(LangParser::BinoplandexprContext *ctx) override;

  void exitIntcompareexpr(LangParser::IntcompareexprContext *ctx) override;

  void exitUnopnegateexpr(LangParser::UnopnegateexprContext *ctx) override;

  void enterBoolliteral(LangParser::BoolliteralContext *ctx) override;

  void exitBinopintexpr(LangParser::BinopintexprContext *ctx) override;

  void enterIntliteral(LangParser::IntliteralContext *ctx) override;

  void enterVarrefexpr(LangParser::VarrefexprContext *ctx) override;

  std::shared_ptr<Function> getFunction() override { return function; }

  bool hasErrors() const override { return errorCount > 0; }

private:
  void reportError(tree::ParseTree *node, std::string details);

  std::optional<int64_t> parseInt(tree::TerminalNode *node);

  void pushExpr(std::shared_ptr<Expression> expression) {
    expressionStack.emplace_back(std::move(expression));
  }
  std::shared_ptr<Expression> popExpr() {
    std::shared_ptr<Expression> result = std::move(expressionStack.back());
    expressionStack.pop_back();
    return result;
  }
  void pushErrorExpr(Type type) {
    pushExpr(std::make_shared<ErrorExpression>(type));
  }

  void pushStmt(std::shared_ptr<Statement> statement) {
    statementStack.emplace_back(std::move(statement));
  }
  std::shared_ptr<Statement> popStmt() {
    std::shared_ptr<Statement> result = std::move(statementStack.back());
    statementStack.pop_back();
    return result;
  }
  void pushErrorStmt() { pushStmt(std::make_shared<ErrorStatement>()); }

  void checkExpressionStackForBinop();

private:
  std::shared_ptr<Function> function;
  std::vector<std::shared_ptr<Expression>> expressionStack;
  std::vector<std::shared_ptr<Statement>> statementStack;
  std::unordered_map<std::string, size_t> parameters;
  size_t errorCount = 0;
};

} // namespace

static Type getType(LangParser::TypeContext *ctx) {
  return ctx->BOOL() ? T_BOOL : T_INT;
}

void ASTBuilderImpl::enterFunction(LangParser::FunctionContext *ctx) {
  function->returnType = getType(ctx->type());
}

void ASTBuilderImpl::enterParamdecl(LangParser::ParamdeclContext *ctx) {
  auto &parameter = function->parameters.emplace_back(Parameter{
      .name = ctx->NAME()->getText(),
      .type = getType(ctx->type()),
  });
  size_t index = function->parameters.size() - 1;
  auto [_, New] = parameters.emplace(parameter.name, index);
  if (!New) {
    reportError(ctx, fmt::format("parameter {} redeclared", parameter.name));
  }
}

void ASTBuilderImpl::exitBody(LangParser::BodyContext *ctx) {
  size_t bodySize = ctx->statement().size();
  if (statementStack.size() != bodySize) {
    throw std::runtime_error(
        fmt::format("expected function body of {} statements, but found {} "
                    "statements in the statement stack",
                    bodySize, statementStack.size()));
  }
  for (size_t i = 0; i < bodySize; ++i) {
    function->body.push_back(popStmt());
  }
  std::reverse(function->body.begin(), function->body.end());
}

void ASTBuilderImpl::exitReturnstmt(LangParser::ReturnstmtContext *ctx) {
  if (expressionStack.empty()) {
    throw std::runtime_error(
        "expression stack is empty at the return statement");
  }
  function->returnValue = popExpr();
  if (function->returnValue->type != function->returnType) {
    reportError(ctx, fmt::format("return value of type {} does not match with "
                                 "expected return type {}",
                                 toString(function->returnValue->type),
                                 toString(function->returnType)));
  }
  if (!expressionStack.empty()) {
    throw std::runtime_error(
        "unexpected leftover expressions in the stack after return statement");
  }
}

void ASTBuilderImpl::exitIfstmt(LangParser::IfstmtContext *ctx) {
  size_t thenBodySize = ctx->thenbody()->statement().size();
  size_t elseBodySize = ctx->elsebody()->statement().size();
  if (statementStack.size() < thenBodySize + elseBodySize) {
    throw std::runtime_error(
        fmt::format("statement stack size is not enough to assemble an IfStmt, "
                    "expected at least {}",
                    thenBodySize + elseBodySize));
  }
  if (expressionStack.empty()) {
    throw std::runtime_error(
        "expected a condition expression in the expression stack for IfStmt, "
        "but expression stack is empty");
  }
  auto condition = popExpr();
  std::vector<std::shared_ptr<Statement>> thenBody;
  std::vector<std::shared_ptr<Statement>> elseBody;
  for (size_t i = 0; i < elseBodySize; ++i)
    elseBody.emplace_back(popStmt());
  std::reverse(elseBody.begin(), elseBody.end());
  for (size_t i = 0; i < thenBodySize; ++i)
    thenBody.emplace_back(popStmt());
  std::reverse(thenBody.begin(), thenBody.end());
  if (condition->type != T_BOOL) {
    reportError(
        ctx,
        fmt::format("expected bool for if condition expression, but found {}",
                    toString(condition->type)));
    return pushErrorStmt();
  }
  auto ifstmt = std::make_shared<IfStmt>(
      std::move(condition), std::move(thenBody), std::move(elseBody));
  pushStmt(std::move(ifstmt));
}

void ASTBuilderImpl::exitAssign(LangParser::AssignContext *ctx) {
  if (expressionStack.empty()) {
    throw std::runtime_error("expression stack is empty at assign");
  }
  auto rhs = popExpr();
  std::string varName = ctx->NAME()->getText();
  auto it = parameters.find(varName);
  if (it == parameters.end()) {
    reportError(ctx, fmt::format("unresolved reference to {} in assignment lhs",
                                 varName));
    return pushErrorStmt();
  }
  size_t parameterIndex = it->second;
  Type parameterType = function->parameters[parameterIndex].type;
  if (parameterType != rhs->type) {
    reportError(ctx,
                fmt::format("expected type {} of assignment rhs, found {}",
                            toString(parameterType), toString(parameterType)));
    return pushErrorStmt();
  }
  auto assignment =
      std::make_shared<Assignment>(std::move(varName), std::move(rhs));
  pushStmt(assignment);
}

#define BINOP(tokenName, binopKind, argType, retType)                          \
  if (ctx->tokenName()) {                                                      \
    auto rhs = popExpr();                                                      \
    auto lhs = popExpr();                                                      \
    if (lhs->type != argType) {                                                \
      reportError(                                                             \
          ctx,                                                                 \
          fmt::format(                                                         \
              "expected {} type for lhs of {} binary operator, found {}",      \
              toString(argType), toString(binopKind), toString(lhs->type)));   \
      return pushErrorExpr(retType);                                           \
    }                                                                          \
    if (rhs->type != argType) {                                                \
      reportError(                                                             \
          ctx,                                                                 \
          fmt::format(                                                         \
              "expected {} type for rhs of {} binary operator, found {}",      \
              toString(argType), toString(binopKind), toString(rhs->type)));   \
      return pushErrorExpr(retType);                                           \
    }                                                                          \
    pushExpr(std::make_shared<BinOp>(binopKind, std::move(lhs),                \
                                     std::move(rhs), retType));                \
    return;                                                                    \
  }

void ASTBuilderImpl::exitBinoplorexpr(LangParser::BinoplorexprContext *ctx) {
  checkExpressionStackForBinop();
  BINOP(BINOP_LOR, BO_LOr, T_BOOL, T_BOOL)
  assert(false && "invalid int binop produced by ANTLR");
}

void ASTBuilderImpl::exitBinoplandexpr(LangParser::BinoplandexprContext *ctx) {
  checkExpressionStackForBinop();
  BINOP(BINOP_LAND, BO_LAnd, T_BOOL, T_BOOL)
  assert(false && "invalid int binop produced by ANTLR");
}

void ASTBuilderImpl::exitIntcompareexpr(
    LangParser::IntcompareexprContext *ctx) {
  checkExpressionStackForBinop();
  BINOP(BINOP_LT, BO_Lt, T_INT, T_BOOL)
  BINOP(BINOP_GT, BO_Gt, T_INT, T_BOOL)
  assert(false && "invalid int binop produced by ANTLR");
}

void ASTBuilderImpl::exitUnopnegateexpr(
    LangParser::UnopnegateexprContext *ctx) {
  if (expressionStack.empty()) {
    throw std::runtime_error(
        "an empty expression stack for unary negation operator");
  }
  auto subExpr = popExpr();
  if (subExpr->type != T_BOOL) {
    reportError(ctx,
                fmt::format("expected bool for unary ! operator, but found {}",
                            toString(subExpr->type)));
    return pushErrorExpr(T_BOOL);
  }
  pushExpr(std::make_shared<UnOp>(UO_Neg, std::move(subExpr), T_BOOL));
}

void ASTBuilderImpl::enterBoolliteral(LangParser::BoolliteralContext *ctx) {
  if (auto *number = ctx->FALSE()) {
    pushExpr(std::make_shared<BoolConstant>(false));
    return;
  }
  if (auto *number = ctx->TRUE()) {
    pushExpr(std::make_shared<BoolConstant>(true));
    return;
  }
  assert(false && "invalid bool literal produced by ANTLR");
}

void ASTBuilderImpl::exitBinopintexpr(LangParser::BinopintexprContext *ctx) {
  checkExpressionStackForBinop();
  BINOP(BINOP_ADD, BO_Add, T_INT, T_INT)
  BINOP(BINOP_SUB, BO_Sub, T_INT, T_INT)
  assert(false && "invalid int binop produced by ANTLR");
}

void ASTBuilderImpl::enterIntliteral(LangParser::IntliteralContext *ctx) {
  if (auto value = parseInt(ctx->NUMBER()))
    pushExpr(std::make_shared<IntConstant>(*value));
  else
    pushErrorExpr(T_INT);
}

void ASTBuilderImpl::enterVarrefexpr(LangParser::VarrefexprContext *ctx) {
  std::string name = ctx->getText();
  auto it = parameters.find(name);
  if (it == parameters.end()) {
    reportError(ctx, fmt::format("unresolved reference to {}", name));
    return pushErrorExpr(T_INT);
  }
  pushExpr(std::make_shared<VarRef>(std::move(name),
                                    function->parameters[it->second].type));
}

void ASTBuilderImpl::reportError(tree::ParseTree *, std::string details) {
  ++errorCount;
  std::cerr << fmt::format("semantics error: {}", details) << std::endl;
}

std::optional<int64_t> ASTBuilderImpl::parseInt(tree::TerminalNode *number) {
  int64_t result = 0;
  constexpr int64_t limitBeforeOverflow =
      std::numeric_limits<int64_t>::max() / 10;
  for (char c : number->getText()) {
    if (!std::isdigit(c)) {
      reportError(number, "non-digit char in a number");
      return std::nullopt;
    }
    if (result > limitBeforeOverflow) {
      reportError(number, "number is too large to fit in 64-bit signed word");
      return std::nullopt;
    }
    result = result * 10 + (c - '0');
  }
  return result;
}

void ASTBuilderImpl::checkExpressionStackForBinop() {
  if (expressionStack.size() < 2) {
    throw std::runtime_error(
        "need at least two expressions in the stack for a binary operator");
  }
}

std::shared_ptr<IASTBuilder> IASTBuilder::create() {
  return std::make_shared<ASTBuilderImpl>();
}
