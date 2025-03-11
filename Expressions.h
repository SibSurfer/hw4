#pragma once

#include <memory>
#include <string>
#include <vector>

namespace cereal {
class JSONOutputArchive;
}

namespace mysym {

class IExpressionsVisitor {
public:
  virtual void visitBoolConst(const class BoolConst &expr) {}
  virtual void visitBoolSymbol(const class BoolSymbol &expr) {}
  virtual void visitBoolNeg(const class BoolNeg &expr) {}
  virtual void visitBoolAnd(const class BoolAnd &expr) {}
  virtual void visitBoolOr(const class BoolOr &expr) {}
  virtual void visitIntLess(const class IntLess &expr) {}
  virtual void visitIntGreater(const class IntGreater &expr) {}
  virtual void visitIntConst(const class IntConst &expr) {}
  virtual void visitIntSymbol(const class IntSymbol &expr) {}
  virtual void visitIntAdd(const class IntAdd &expr) {}
  virtual void visitIntSub(const class IntSub &expr) {}
};

struct Expressions {
  virtual ~Expressions() = default;
  virtual void accept(IExpressionsVisitor &visitor) const = 0;  
  std::string save_minimal(const cereal::JSONOutputArchive &out) const;
};

struct BoolExpression : Expressions {};
struct IntExpression : Expressions {};

#define DEFINE_ACCEPT(CLASS, METHOD) \
  void accept(IExpressionsVisitor &visitor) const override { visitor.METHOD(*this); }


struct BoolConst final : BoolExpression {
  bool value;
  explicit BoolConst(bool value) : value(value) {}
  DEFINE_ACCEPT(BoolConst, visitBoolConst)
};

struct BoolSymbol final : BoolExpression {
  std::string identifier;
  explicit BoolSymbol(const std::string &identifier) : identifier(identifier) {}
  DEFINE_ACCEPT(BoolSymbol, visitBoolSymbol)
};

struct BoolNeg final : BoolExpression {
  std::shared_ptr<BoolExpression> subExpr;
  explicit BoolNeg(std::shared_ptr<BoolExpression> subExpr) 
      : subExpr(std::move(subExpr)) {}
  DEFINE_ACCEPT(BoolNeg, visitBoolNeg)
};

struct BoolAnd final : BoolExpression {
  std::shared_ptr<BoolExpression> lhs, rhs;
  BoolAnd(std::shared_ptr<BoolExpression> lhs, std::shared_ptr<BoolExpression> rhs) 
      : lhs(std::move(lhs)), rhs(std::move(rhs)) {}
  DEFINE_ACCEPT(BoolAnd, visitBoolAnd)
};

struct BoolOr final : BoolExpression {
  std::shared_ptr<BoolExpression> lhs, rhs;
  BoolOr(std::shared_ptr<BoolExpression> lhs, std::shared_ptr<BoolExpression> rhs) 
      : lhs(std::move(lhs)), rhs(std::move(rhs)) {}
  DEFINE_ACCEPT(BoolOr, visitBoolOr)
};

struct IntLess final : BoolExpression {
  std::shared_ptr<IntExpression> lhs, rhs;
  IntLess(std::shared_ptr<IntExpression> lhs, std::shared_ptr<IntExpression> rhs) 
      : lhs(std::move(lhs)), rhs(std::move(rhs)) {}
  DEFINE_ACCEPT(IntLess, visitIntLess)
};

struct IntGreater final : BoolExpression {
  std::shared_ptr<IntExpression> lhs, rhs;
  IntGreater(std::shared_ptr<IntExpression> lhs, std::shared_ptr<IntExpression> rhs) 
      : lhs(std::move(lhs)), rhs(std::move(rhs)) {}
  DEFINE_ACCEPT(IntGreater, visitIntGreater)
};

struct IntConst final : IntExpression {
  int64_t value;
  explicit IntConst(int64_t value) : value(value) {}
  DEFINE_ACCEPT(IntConst, visitIntConst)
};

struct IntSymbol final : IntExpression {
  std::string identifier;
  explicit IntSymbol(const std::string &identifier) : identifier(identifier) {}
  DEFINE_ACCEPT(IntSymbol, visitIntSymbol)
};

struct IntAdd final : IntExpression {
  std::shared_ptr<IntExpression> lhs, rhs;
  IntAdd(std::shared_ptr<IntExpression> lhs, std::shared_ptr<IntExpression> rhs) 
      : lhs(std::move(lhs)), rhs(std::move(rhs)) {}
  DEFINE_ACCEPT(IntAdd, visitIntAdd)
};

struct IntSub final : IntExpression {
  std::shared_ptr<IntExpression> lhs, rhs;
  IntSub(std::shared_ptr<IntExpression> lhs, std::shared_ptr<IntExpression> rhs) 
      : lhs(std::move(lhs)), rhs(std::move(rhs)) {}
  DEFINE_ACCEPT(IntSub, visitIntSub)
};

#undef DEFINE_ACCEPT  

std::shared_ptr<BoolExpression> conjunction(const std::vector<std::shared_ptr<BoolExpression>> &expressions);
std::string render(const Expressions &expr);

} 