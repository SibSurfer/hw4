#pragma once

#include <memory>
#include <string>
#include <vector>

namespace mysym {

enum Type {
  T_BOOL,
  T_INT,
};

std::string toString(Type type);

struct Parameter {
  std::string name;
  Type type;

  std::string toString() const;
};

struct Expression {
  Type type;

  Expression(Type type) : type(type) {}
  virtual ~Expression() = default;
};

struct ErrorExpression final : Expression {
  ErrorExpression(Type type) : Expression(type) {}
};

struct VarRef final : Expression {
  std::string identifier;

  VarRef(std::string identifier, Type type)
      : identifier(identifier), Expression(type) {}
};

struct IntConstant final : Expression {
  int64_t value;

  IntConstant(int64_t value) : value(value), Expression(T_INT) {}
};

struct BoolConstant final : Expression {
  bool value;

  BoolConstant(bool value) : value(value), Expression(T_BOOL) {}
};

enum UnOpKind {
  UO_Neg,
};

struct UnOp final : Expression {
  UnOpKind kind;
  std::shared_ptr<Expression> subExpr;

  UnOp(UnOpKind kind, std::shared_ptr<Expression> subExpr, Type type)
      : Expression(type), kind(kind), subExpr(std::move(subExpr)) {}
};

enum BinOpKind {
  BO_Add,
  BO_Sub,
  BO_Lt,
  BO_Gt,
  BO_LAnd,
  BO_LOr,
};

std::string toString(BinOpKind kind);

struct BinOp final : Expression {
  BinOpKind kind;
  std::shared_ptr<Expression> lhs;
  std::shared_ptr<Expression> rhs;

  BinOp(BinOpKind kind, std::shared_ptr<Expression> lhs,
        std::shared_ptr<Expression> rhs, Type type)
      : Expression(type), kind(kind), lhs(std::move(lhs)), rhs(std::move(rhs)) {
  }
};

struct Statement {
  virtual ~Statement() = default;
};

struct ErrorStatement final : Statement {};

struct Assignment final : Statement {
  std::string var;
  std::shared_ptr<Expression> value;

  Assignment(std::string var, std::shared_ptr<Expression> value)
      : var(std::move(var)), value(std::move(value)) {}
};

struct IfStmt final : Statement {
  std::shared_ptr<Expression> condition;
  std::vector<std::shared_ptr<Statement>> thenBlock;
  std::vector<std::shared_ptr<Statement>> elseBlock;

  IfStmt(std::shared_ptr<Expression> condition,
         std::vector<std::shared_ptr<Statement>> thenBlock,
         std::vector<std::shared_ptr<Statement>> elseBlock)
      : condition(condition), thenBlock(thenBlock), elseBlock(elseBlock) {}
};

struct Function {
  std::vector<Parameter> parameters;
  std::vector<std::shared_ptr<Statement>> body;
  Type returnType;
  std::shared_ptr<Expression> returnValue;
};

} // namespace mysym
