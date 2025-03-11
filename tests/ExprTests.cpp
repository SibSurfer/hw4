#include "Expressions.h"
#include "gtest/gtest.h"

using namespace mysym;

TEST(SymExprRender, True) {
  auto expr = std::make_shared<BoolConst>(true);
  EXPECT_EQ("true", render(*expr));
}

TEST(SymExprRender, False) {
  auto expr = std::make_shared<BoolConst>(false);
  EXPECT_EQ("false", render(*expr));
}

TEST(SymExprRender, BoolSymbol) {
  auto expr = std::make_shared<BoolSymbol>("b");
  EXPECT_EQ("b", render(*expr));
}

TEST(SymExprRender, BoolNegOfTrue) {
  auto expr = std::make_shared<BoolNeg>(std::make_shared<BoolConst>(true));
  EXPECT_EQ("!true", render(*expr));
}

TEST(SymExprRender, BoolNegOfFalse) {
  auto expr = std::make_shared<BoolNeg>(std::make_shared<BoolConst>(false));
  EXPECT_EQ("!false", render(*expr));
}

TEST(SymExprRender, BoolNegOfSymbol) {
  auto expr = std::make_shared<BoolNeg>(std::make_shared<BoolSymbol>("b"));
  EXPECT_EQ("!b", render(*expr));
}

TEST(SymExprRender, BoolAnd) {
  auto expr = std::make_shared<BoolAnd>(std::make_shared<BoolSymbol>("p"),
                                        std::make_shared<BoolSymbol>("q"));
  EXPECT_EQ("(p & q)", render(*expr));
}

TEST(SymExprRender, BoolAndAfterNeq) {
  auto expr = std::make_shared<BoolAnd>(
      std::make_shared<BoolNeg>(std::make_shared<BoolSymbol>("b")),
      std::make_shared<BoolSymbol>("q"));
  EXPECT_EQ("(!b & q)", render(*expr));
}

TEST(SymExprRender, BoolOr) {
  auto expr = std::make_shared<BoolOr>(std::make_shared<BoolSymbol>("p"),
                                       std::make_shared<BoolSymbol>("q"));
  EXPECT_EQ("(p | q)", render(*expr));
}

TEST(SymExprRender, BoolOrAfterNeg) {
  auto expr = std::make_shared<BoolOr>(
      std::make_shared<BoolSymbol>("p"),
      std::make_shared<BoolNeg>(std::make_shared<BoolSymbol>("d")));
  EXPECT_EQ("(p | !d)", render(*expr));
}

TEST(SymExprRender, BoolOrAfterAnd) {
  auto expr = std::make_shared<BoolOr>(
      std::make_shared<BoolSymbol>("p"),
      std::make_shared<BoolAnd>(std::make_shared<BoolSymbol>("a"),
                                std::make_shared<BoolSymbol>("b")));
  EXPECT_EQ("(p | (a & b))", render(*expr));
}

TEST(SymExprRender, BoolAndAfterOr) {
  auto expr = std::make_shared<BoolAnd>(
      std::make_shared<BoolOr>(std::make_shared<BoolConst>(true),
                               std::make_shared<BoolSymbol>("f")),
      std::make_shared<BoolOr>(
          std::make_shared<BoolSymbol>("g"),
          std::make_shared<BoolNeg>(std::make_shared<BoolSymbol>("h"))));
  EXPECT_EQ("((true | f) & (g | !h))", render(*expr));
}

TEST(SymExprRender, IntConst) {
  auto expr = std::make_shared<IntConst>(10);
  EXPECT_EQ("10", render(*expr));
}

TEST(SymExprRender, IntSymbol) {
  auto expr = std::make_shared<IntSymbol>("z");
  EXPECT_EQ("z", render(*expr));
}

TEST(SymExprRender, IntAdd) {
  auto expr = std::make_shared<IntAdd>(std::make_shared<IntSymbol>("a"),
                                       std::make_shared<IntConst>(1));
  EXPECT_EQ("(a + 1)", render(*expr));
}

TEST(SymExprRender, IntSub) {
  auto expr = std::make_shared<IntSub>(std::make_shared<IntSymbol>("a"),
                                       std::make_shared<IntConst>(1));
  EXPECT_EQ("(a - 1)", render(*expr));
}

TEST(SymExprRender, IntAddNested) {
  auto expr = std::make_shared<IntAdd>(
      std::make_shared<IntSymbol>("a"),
      std::make_shared<IntAdd>(std::make_shared<IntSymbol>("t"),
                               std::make_shared<IntConst>(5)));
  EXPECT_EQ("(a + (t + 5))", render(*expr));
}

TEST(SymExprRender, IntLess) {
  auto expr = std::make_shared<IntLess>(std::make_shared<IntSymbol>("a"),
                                        std::make_shared<IntSymbol>("b"));
  EXPECT_EQ("(a < b)", render(*expr));
}

TEST(SymExprRender, IntGreater) {
  auto expr = std::make_shared<IntGreater>(std::make_shared<IntSymbol>("a"),
                                           std::make_shared<IntSymbol>("b"));
  EXPECT_EQ("(a > b)", render(*expr));
}

TEST(SymExprRender, BoolAndAfterIntCmp) {
  auto expr = std::make_shared<BoolAnd>(
      std::make_shared<IntLess>(std::make_shared<IntSymbol>("a"),
                                std::make_shared<IntSymbol>("b")),
      std::make_shared<IntGreater>(std::make_shared<IntSymbol>("z"),
                                   std::make_shared<IntConst>(10)));
  EXPECT_EQ("((a < b) & (z > 10))", render(*expr));
}