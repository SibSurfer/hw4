#include "AST.h"
#include "ASTBuilder.h"
#include "LangLexer.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace antlr4;
using namespace mysym;
using ::testing::AllOf;
using ::testing::ElementsAre;
using ::testing::Field;
using ::testing::IsEmpty;
using ::testing::Pointer;
using ::testing::WhenDynamicCastTo;

namespace {

class ASTBuilderTest : public ::testing::Test {
protected:
  ASTBuilderTest() : lexer(&inputStream), tokens(&lexer), parser(&tokens) {}

  void setSource(std::string sourceCode) {
    inputStream.load(std::move(sourceCode));
  }

  void buildAST() {
    tree::ParseTree *tree = parser.function();
    ASSERT_EQ(0ULL, lexer.getNumberOfSyntaxErrors());
    ASSERT_EQ(0ULL, parser.getNumberOfSyntaxErrors());
    tree::ParseTreeWalker::DEFAULT.walk(builder.get(), tree);
    ast = builder->getFunction();
  }

  void failTest() {
    tree::ParseTree *tree = parser.function();
    if (lexer.getNumberOfSyntaxErrors())
      return;
    if (parser.getNumberOfSyntaxErrors())
      return;
    tree::ParseTreeWalker::DEFAULT.walk(builder.get(), tree);
    if (builder->hasErrors())
      return;
    FAIL() << "lexing, parsing and AST building finished successfully";
  }

  ANTLRInputStream inputStream;
  LangLexer lexer;
  CommonTokenStream tokens;
  LangParser parser;
  std::shared_ptr<IASTBuilder> builder = IASTBuilder::create();
  std::shared_ptr<Function> ast;
};

} // namespace

TEST_F(ASTBuilderTest, Parameters_None) {
  setSource(R"(
f(): int {
  return 1
}
)");
  buildAST();
  std::vector<std::string> parameters;
  for (auto &parameter : ast->parameters)
    parameters.push_back(parameter.toString());
  EXPECT_THAT(parameters, IsEmpty());
}

TEST_F(ASTBuilderTest, Parameters_SingleInt) {
  setSource(R"(
f(int x): int {
  return 1
}
)");
  buildAST();
  std::vector<std::string> parameters;
  for (auto &parameter : ast->parameters)
    parameters.push_back(parameter.toString());
  EXPECT_THAT(parameters, ElementsAre("int x"));
}

TEST_F(ASTBuilderTest, Parameters_SingleBool) {
  setSource(R"(
f(bool b): int {
  return 1
}
)");
  buildAST();
  std::vector<std::string> parameters;
  for (auto &parameter : ast->parameters)
    parameters.push_back(parameter.toString());
  EXPECT_THAT(parameters, ElementsAre("bool b"));
}

TEST_F(ASTBuilderTest, Parameters_Many) {
  setSource(R"(
f(int a, bool b, int c): int {
  return 1
}
)");
  buildAST();
  std::vector<std::string> parameters;
  for (auto &parameter : ast->parameters)
    parameters.push_back(parameter.toString());
  EXPECT_THAT(parameters, ElementsAre("int a", "bool b", "int c"));
}

TEST_F(ASTBuilderTest, Parameters_Redeclared) {
  setSource(R"(
f(int a, bool b, int a): int {
  return 1
}
)");
  buildAST();
  EXPECT_TRUE(builder->hasErrors());
}

TEST_F(ASTBuilderTest, Parameters_RedeclaredDifferentType) {
  setSource(R"(
f(int a, bool b, bool a): int {
  return 1
}
)");
  buildAST();
  EXPECT_TRUE(builder->hasErrors());
}

TEST_F(ASTBuilderTest, ReturnType_Bool) {
  setSource(R"(
f(): bool {
  return true
}
)");
  buildAST();
  EXPECT_EQ(T_BOOL, ast->returnType);
}

TEST_F(ASTBuilderTest, ReturnType_Int) {
  setSource(R"(
f(): int {
  return 1
}
)");
  buildAST();
  EXPECT_EQ(T_INT, ast->returnType);
}

TEST_F(ASTBuilderTest, ReturnValue_ConstantIntZero) {
  setSource(R"(
f(): int {
  return 0
}
)");
  buildAST();
  EXPECT_THAT(ast->returnValue.get(), WhenDynamicCastTo<IntConstant *>(
                                          Field(&IntConstant::value, 0LL)));
}

TEST_F(ASTBuilderTest, ReturnValue_ConstantIntPositive) {
  setSource(R"(
f(): int {
  return 1
}
)");
  buildAST();
  EXPECT_THAT(ast->returnValue.get(), WhenDynamicCastTo<IntConstant *>(
                                          Field(&IntConstant::value, 1LL)));
}

TEST_F(ASTBuilderTest, ReturnValue_ConstantIntTooLong) {
  // 10^50
  setSource(R"(
f(): int {
  return 100000000000000000000000000000000000000000000000000
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, ReturnValue_ConstantBoolTrue) {
  setSource(R"(
f(): bool {
  return true
}
)");
  buildAST();
  EXPECT_THAT(ast->returnValue.get(),
              WhenDynamicCastTo<BoolConstant *>(
                  Field("value", &BoolConstant::value, true)));
}

TEST_F(ASTBuilderTest, ReturnValue_ConstantBoolFalse) {
  setSource(R"(
f(): bool {
  return false
}
)");
  buildAST();
  EXPECT_THAT(ast->returnValue.get(),
              WhenDynamicCastTo<BoolConstant *>(
                  Field("value", &BoolConstant::value, false)));
}

TEST_F(ASTBuilderTest, ReturnValue_VariableInt) {
  setSource(R"(
f(int x): int {
  return x
}
)");
  buildAST();
  EXPECT_THAT(ast->returnValue.get(),
              WhenDynamicCastTo<VarRef *>(
                  AllOf(Field("identifier", &VarRef::identifier, "x"),
                        Field("type", &VarRef::type, T_INT))));
}

TEST_F(ASTBuilderTest, ReturnValue_VariableBool) {
  setSource(R"(
f(bool b): int {
  return b
}
)");
  buildAST();
  EXPECT_THAT(ast->returnValue.get(),
              WhenDynamicCastTo<VarRef *>(
                  AllOf(Field("identifier", &VarRef::identifier, "b"),
                        Field("type", &VarRef::type, T_BOOL))));
}

TEST_F(ASTBuilderTest, ReturnValue_MissingVariable) {
  setSource(R"(
f(): int {
  return missing
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, ReturnValue_TypeMismatch_Constant) {
  setSource(R"(
f(): int {
  return true
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, ReturnValue_TypeMismatch_Variable) {
  setSource(R"(
f(bool b): int {
  return b
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, ReturnValue_UnopNegateConstantBool) {
  setSource(R"(
f(): bool {
  return !true
}
)");
  buildAST();
  EXPECT_THAT(ast->returnValue.get(),
              WhenDynamicCastTo<const UnOp *>(AllOf(
                  Field("kind", &UnOp::kind, UO_Neg),
                  Field("subExpr", &UnOp::subExpr,
                        Pointer(WhenDynamicCastTo<const BoolConstant *>(
                            Field("value", &BoolConstant::value, true)))))));
}

TEST_F(ASTBuilderTest, ReturnValue_UnopNegateVariableBool) {
  setSource(R"(
f(bool b): bool {
  return !b
}
)");
  buildAST();
  EXPECT_THAT(ast->returnValue.get(),
              WhenDynamicCastTo<const UnOp *>(
                  AllOf(Field("kind", &UnOp::kind, UO_Neg),
                        Field("subExpr", &UnOp::subExpr,
                              Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                                  "identifier", &VarRef::identifier, "b")))))));
}

TEST_F(ASTBuilderTest, ReturnValue_UnopNegateDouble) {
  setSource(R"(
f(): bool {
  return !!false
}
)");
  buildAST();
  EXPECT_THAT(
      ast->returnValue.get(),
      WhenDynamicCastTo<const UnOp *>(AllOf(
          Field("kind", &UnOp::kind, UO_Neg),
          Field("subExpr", &UnOp::subExpr,
                Pointer(WhenDynamicCastTo<const UnOp *>(AllOf(
                    Field("kind", &UnOp::kind, UO_Neg),
                    Field("subExpr", &UnOp::subExpr,
                          Pointer(WhenDynamicCastTo<const BoolConstant *>(Field(
                              "value", &BoolConstant::value, false)))))))))));
}

TEST_F(ASTBuilderTest, ReturnValue_UnopNegateWrongTypeConstant) {
  setSource(R"(
f(): int {
  return !1
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, ReturnValue_UnopNegateWrongTypeVariable) {
  setSource(R"(
f(int n): bool {
  return !n
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, ReturnValue_BinopPlus) {
  setSource(R"(
f(int a): int {
  return a + 1
}
)");
  buildAST();
  EXPECT_THAT(ast->returnValue.get(),
              WhenDynamicCastTo<const BinOp *>(
                  AllOf(Field("kind", &BinOp::kind, BO_Add),
                        Field("lhs", &BinOp::lhs,
                              Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                                  "identifier", &VarRef::identifier, "a")))),
                        Field("rhs", &BinOp::rhs,
                              Pointer(WhenDynamicCastTo<const IntConstant *>(
                                  Field("value", &IntConstant::value, 1)))))));
}

TEST_F(ASTBuilderTest, ReturnValue_BinopMinus) {
  setSource(R"(
f(int a, int b): int {
  return b - a
}
)");
  buildAST();
  EXPECT_THAT(ast->returnValue.get(),
              WhenDynamicCastTo<const BinOp *>(AllOf(
                  Field("kind", &BinOp::kind, BO_Sub),
                  Field("lhs", &BinOp::lhs,
                        Pointer(WhenDynamicCastTo<const VarRef *>(
                            Field("identifier", &VarRef::identifier, "b")))),
                  Field("rhs", &BinOp::rhs,
                        Pointer(WhenDynamicCastTo<const VarRef *>(
                            Field("identifier", &VarRef::identifier, "a")))))));
}

TEST_F(ASTBuilderTest, ReturnValue_BinopRightAssociativity) {
  setSource(R"(
f(int a, int b, int c): int {
  return a + b - c
}
)");
  buildAST();
  EXPECT_THAT(
      ast->returnValue.get(),
      WhenDynamicCastTo<const BinOp *>(AllOf(
          Field("kind", &BinOp::kind, BO_Add),
          Field("lhs", &BinOp::lhs,
                Pointer(WhenDynamicCastTo<const VarRef *>(
                    Field("identifier", &VarRef::identifier, "a")))),
          Field("rhs", &BinOp::rhs,
                Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                    Field("kind", &BinOp::kind, BO_Sub),
                    Field("lhs", &BinOp::lhs,
                          Pointer(WhenDynamicCastTo<const VarRef *>(
                              Field("identifier", &VarRef::identifier, "b")))),
                    Field("rhs", &BinOp::rhs,
                          Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                              "identifier", &VarRef::identifier, "c")))))))))));
}

TEST_F(ASTBuilderTest, ReturnValue_BinopPlusWrongArgTypeOfVar) {
  setSource(R"(
f(int a, bool b): int {
  return a + b
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, ReturnValue_BinopPlusWrongArgTypeOfConst) {
  setSource(R"(
f(int a): int {
  return a + true
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, ReturnValue_BinopPlusReturnTypeMismatch) {
  setSource(R"(
f(int a): bool {
  return a + a
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, ReturnValue_BinopPlusWrongArgTypeMismatchNegation) {
  setSource(R"(
f(int a, bool b): int {
  return a + !b
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLess) {
  setSource(R"(
f(int x): bool {
  return x < 3
}
)");
  buildAST();
  EXPECT_THAT(ast->returnValue.get(),
              WhenDynamicCastTo<const BinOp *>(
                  AllOf(Field("kind", &BinOp::kind, BO_Lt),
                        Field("lhs", &BinOp::lhs,
                              Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                                  "identifier", &VarRef::identifier, "x")))),
                        Field("rhs", &BinOp::rhs,
                              Pointer(WhenDynamicCastTo<const IntConstant *>(
                                  Field("value", &IntConstant::value, 3)))))));
}

TEST_F(ASTBuilderTest, ReturnValue_BinopGt) {
  setSource(R"(
f(int x, int y): bool {
  return x > y
}
)");
  buildAST();
  EXPECT_THAT(ast->returnValue.get(),
              WhenDynamicCastTo<const BinOp *>(AllOf(
                  Field("kind", &BinOp::kind, BO_Gt),
                  Field("lhs", &BinOp::lhs,
                        Pointer(WhenDynamicCastTo<const VarRef *>(
                            Field("identifier", &VarRef::identifier, "x")))),
                  Field("rhs", &BinOp::rhs,
                        Pointer(WhenDynamicCastTo<const VarRef *>(
                            Field("identifier", &VarRef::identifier, "y")))))));
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLtWrongRhsType) {
  setSource(R"(
f(int x, int y): bool {
  return x < true
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLtWrongLhsType) {
  setSource(R"(
f(int x, int y): bool {
  return false < y
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLtWrongTypeBothSides) {
  setSource(R"(
f(bool b): bool {
  return false < b
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, ReturnValue_BinopGtWrongLhsType) {
  setSource(R"(
f(int x, bool y): bool {
  return y > x
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, ReturnValue_BinopGtWrongRhsType) {
  setSource(R"(
f(int x): bool {
  return x > true
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, ReturnValue_BinopGtWrongTypeBothSides) {
  setSource(R"(
f(bool p, bool q): bool {
  return q > p
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLtReturnTypeMismatch) {
  setSource(R"(
f(int x, int y): int {
  return x < y
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLessLHSIsAdd) {
  setSource(R"(
f(int x, int y): bool {
  return x + y < 3
}
)");
  buildAST();
  EXPECT_THAT(
      ast->returnValue.get(),
      WhenDynamicCastTo<const BinOp *>(AllOf(
          Field("kind", &BinOp::kind, BO_Lt),
          Field("lhs", &BinOp::lhs,
                Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                    Field("kind", &BinOp::kind, BO_Add),
                    Field("lhs", &BinOp::lhs,
                          Pointer(WhenDynamicCastTo<const VarRef *>(
                              Field("identifier", &VarRef::identifier, "x")))),
                    Field("rhs", &BinOp::rhs,
                          Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                              "identifier", &VarRef::identifier, "y")))))))),
          Field("rhs", &BinOp::rhs,
                Pointer(WhenDynamicCastTo<const IntConstant *>(
                    Field("value", &IntConstant::value, 3)))))));
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLessRHSIsSub) {
  setSource(R"(
f(int x, int y): bool {
  return x < y - 7
}
)");
  buildAST();
  EXPECT_THAT(
      ast->returnValue.get(),
      WhenDynamicCastTo<const BinOp *>(AllOf(
          Field("kind", &BinOp::kind, BO_Lt),
          Field("lhs", &BinOp::lhs,
                Pointer(WhenDynamicCastTo<const VarRef *>(
                    Field("identifier", &VarRef::identifier, "x")))),
          Field("rhs", &BinOp::rhs,
                Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                    Field("kind", &BinOp::kind, BO_Sub),
                    Field("lhs", &BinOp::lhs,
                          Pointer(WhenDynamicCastTo<const VarRef *>(
                              Field("identifier", &VarRef::identifier, "y")))),
                    Field("rhs", &BinOp::rhs,
                          Pointer(WhenDynamicCastTo<const IntConstant *>(
                              Field("value", &IntConstant::value, 7)))))))))));
}

TEST_F(ASTBuilderTest, ReturnValue_BinopGtRHSBothSidesAddOrSub) {
  setSource(R"(
f(int x, int y): bool {
  return x + 4 > y + x - 7
}
)");
  buildAST();
  EXPECT_THAT(
      ast->returnValue.get(),
      WhenDynamicCastTo<const BinOp *>(AllOf(
          Field("kind", &BinOp::kind, BO_Gt),
          Field("lhs", &BinOp::lhs,
                Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                    Field("kind", &BinOp::kind, BO_Add),
                    Field("lhs", &BinOp::lhs,
                          Pointer(WhenDynamicCastTo<const VarRef *>(
                              Field("identifier", &VarRef::identifier, "x")))),
                    Field("rhs", &BinOp::rhs,
                          Pointer(WhenDynamicCastTo<const IntConstant *>(
                              Field("value", &IntConstant::value, 4)))))))),
          Field(
              "rhs", &BinOp::rhs,
              Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                  Field("kind", &BinOp::kind, BO_Add),
                  Field("lhs", &BinOp::lhs,
                        Pointer(WhenDynamicCastTo<const VarRef *>(
                            Field("identifier", &VarRef::identifier, "y")))),
                  Field(
                      "rhs", &BinOp::rhs,
                      Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                          Field("kind", &BinOp::kind, BO_Sub),
                          Field("lhs", &BinOp::lhs,
                                Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                                    "identifier", &VarRef::identifier, "x")))),
                          Field("rhs", &BinOp::rhs,
                                Pointer(WhenDynamicCastTo<const IntConstant *>(
                                    Field("value", &IntConstant::value,
                                          7)))))))))))))));
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLAndVarVar) {
  setSource(R"(
f(bool x, bool y): bool {
  return x & y
}
)");
  buildAST();
  EXPECT_THAT(ast->returnValue.get(),
              WhenDynamicCastTo<const BinOp *>(AllOf(
                  Field("kind", &BinOp::kind, BO_LAnd),
                  Field("lhs", &BinOp::lhs,
                        Pointer(WhenDynamicCastTo<const VarRef *>(
                            Field("identifier", &VarRef::identifier, "x")))),
                  Field("rhs", &BinOp::rhs,
                        Pointer(WhenDynamicCastTo<const VarRef *>(
                            Field("identifier", &VarRef::identifier, "y")))))));
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLAndVarConst) {
  setSource(R"(
f(bool x): bool {
  return x & true
}
)");
  buildAST();
  EXPECT_THAT(ast->returnValue.get(),
              WhenDynamicCastTo<const BinOp *>(AllOf(
                  Field("kind", &BinOp::kind, BO_LAnd),
                  Field("lhs", &BinOp::lhs,
                        Pointer(WhenDynamicCastTo<const VarRef *>(
                            Field("identifier", &VarRef::identifier, "x")))),
                  Field("rhs", &BinOp::rhs,
                        Pointer(WhenDynamicCastTo<const BoolConstant *>(
                            Field("value", &BoolConstant::value, true)))))));
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLAndRightAssociativity) {
  setSource(R"(
f(bool x, bool y): bool {
  return x & true & y
}
)");
  buildAST();
  EXPECT_THAT(
      ast->returnValue.get(),
      WhenDynamicCastTo<const BinOp *>(AllOf(
          Field("kind", &BinOp::kind, BO_LAnd),
          Field("lhs", &BinOp::lhs,
                Pointer(WhenDynamicCastTo<const VarRef *>(
                    Field("identifier", &VarRef::identifier, "x")))),
          Field("rhs", &BinOp::rhs,
                Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                    Field("kind", &BinOp::kind, BO_LAnd),
                    Field("lhs", &BinOp::lhs,
                          Pointer(WhenDynamicCastTo<const BoolConstant *>(
                              Field("value", &BoolConstant::value, true)))),
                    Field("rhs", &BinOp::rhs,
                          Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                              "identifier", &VarRef::identifier, "y")))))))))));
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLAndAfterUnaryNegation) {
  setSource(R"(
f(bool x, bool y): bool {
  return !x & !y
}
)");
  buildAST();
  EXPECT_THAT(
      ast->returnValue.get(),
      WhenDynamicCastTo<const BinOp *>(AllOf(
          Field("kind", &BinOp::kind, BO_LAnd),
          Field("lhs", &BinOp::lhs,
                Pointer(WhenDynamicCastTo<const UnOp *>(AllOf(
                    Field("kind", &UnOp::kind, UO_Neg),
                    Field("subExpr", &UnOp::subExpr,
                          Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                              "identifier", &VarRef::identifier, "x")))))))),
          Field("rhs", &BinOp::rhs,
                Pointer(WhenDynamicCastTo<const UnOp *>(AllOf(
                    Field("kind", &UnOp::kind, UO_Neg),
                    Field("subExpr", &UnOp::subExpr,
                          Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                              "identifier", &VarRef::identifier, "y")))))))))));
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLAndAfterIntCompare) {
  setSource(R"(
f(int x, int y): bool {
  return x < 3 & y > 0
}
)");
  buildAST();
  EXPECT_THAT(
      ast->returnValue.get(),
      WhenDynamicCastTo<const BinOp *>(AllOf(
          Field("kind", &BinOp::kind, BO_LAnd),
          Field("lhs", &BinOp::lhs,
                Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                    Field("kind", &BinOp::kind, BO_Lt),
                    Field("lhs", &BinOp::lhs,
                          Pointer(WhenDynamicCastTo<const VarRef *>(
                              Field("identifier", &VarRef::identifier, "x")))),
                    Field("rhs", &BinOp::rhs,
                          Pointer(WhenDynamicCastTo<const IntConstant *>(
                              Field("value", &IntConstant::value, 3)))))))),
          Field("rhs", &BinOp::rhs,
                Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                    Field("kind", &BinOp::kind, BO_Gt),
                    Field("lhs", &BinOp::lhs,
                          Pointer(WhenDynamicCastTo<const VarRef *>(
                              Field("identifier", &VarRef::identifier, "y")))),
                    Field("rhs", &BinOp::rhs,
                          Pointer(WhenDynamicCastTo<const IntConstant *>(
                              Field("value", &IntConstant::value, 0)))))))))));
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLAndAfterIntCompareWithAdd) {
  setSource(R"(
f(bool b, int y, int z): bool {
  return b & y < z + 6
}
)");
  buildAST();
  EXPECT_THAT(
      ast->returnValue.get(),
      WhenDynamicCastTo<const BinOp *>(AllOf(
          Field("kind", &BinOp::kind, BO_LAnd),
          Field("lhs", &BinOp::lhs,
                Pointer(WhenDynamicCastTo<const VarRef *>(
                    Field("identifier", &VarRef::identifier, "b")))),
          Field(
              "rhs", &BinOp::rhs,
              Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                  Field("kind", &BinOp::kind, BO_Lt),
                  Field("lhs", &BinOp::lhs,
                        Pointer(WhenDynamicCastTo<const VarRef *>(
                            Field("identifier", &VarRef::identifier, "y")))),
                  Field(
                      "rhs", &BinOp::rhs,
                      Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                          Field("kind", &BinOp::kind, BO_Add),
                          Field("lhs", &BinOp::lhs,
                                Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                                    "identifier", &VarRef::identifier, "z")))),
                          Field("rhs", &BinOp::rhs,
                                Pointer(WhenDynamicCastTo<const IntConstant *>(
                                    Field("value", &IntConstant::value,
                                          6)))))))))))))));
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLAndRhsWrongType) {
  setSource(R"(
f(bool b, int y): bool {
  return b & y
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLAndLhsWrongType) {
  setSource(R"(
f(bool b, int y): bool {
  return y & b
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLAndWrongReturnType) {
  setSource(R"(
f(bool p, bool q): int {
  return p & q
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLOrVarVar) {
  setSource(R"(
f(bool x, bool y): bool {
  return x | y
}
)");
  buildAST();
  EXPECT_THAT(ast->returnValue.get(),
              WhenDynamicCastTo<const BinOp *>(AllOf(
                  Field("kind", &BinOp::kind, BO_LOr),
                  Field("lhs", &BinOp::lhs,
                        Pointer(WhenDynamicCastTo<const VarRef *>(
                            Field("identifier", &VarRef::identifier, "x")))),
                  Field("rhs", &BinOp::rhs,
                        Pointer(WhenDynamicCastTo<const VarRef *>(
                            Field("identifier", &VarRef::identifier, "y")))))));
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLOrVarConst) {
  setSource(R"(
f(bool x): bool {
  return true | x
}
)");
  buildAST();
  EXPECT_THAT(ast->returnValue.get(),
              WhenDynamicCastTo<const BinOp *>(
                  AllOf(Field("kind", &BinOp::kind, BO_LOr),
                        Field("lhs", &BinOp::lhs,
                              Pointer(WhenDynamicCastTo<const BoolConstant *>(
                                  Field("value", &BoolConstant::value, true)))),
                        Field("rhs", &BinOp::rhs,
                              Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                                  "identifier", &VarRef::identifier, "x")))))));
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLOrRightAssociativity) {
  setSource(R"(
f(bool x, bool y, bool z): bool {
  return x | y | z
}
)");
  buildAST();
  EXPECT_THAT(
      ast->returnValue.get(),
      WhenDynamicCastTo<const BinOp *>(AllOf(
          Field("kind", &BinOp::kind, BO_LOr),
          Field("lhs", &BinOp::lhs,
                Pointer(WhenDynamicCastTo<const VarRef *>(
                    Field("identifier", &VarRef::identifier, "x")))),
          Field("rhs", &BinOp::rhs,
                Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                    Field("kind", &BinOp::kind, BO_LOr),
                    Field("lhs", &BinOp::lhs,
                          Pointer(WhenDynamicCastTo<const VarRef *>(
                              Field("identifier", &VarRef::identifier, "y")))),
                    Field("rhs", &BinOp::rhs,
                          Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                              "identifier", &VarRef::identifier, "z")))))))))));
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLOrAfterUnaryNegation) {
  setSource(R"(
f(bool x, bool y): bool {
  return !x | !y
}
)");
  buildAST();
  EXPECT_THAT(
      ast->returnValue.get(),
      WhenDynamicCastTo<const BinOp *>(AllOf(
          Field("kind", &BinOp::kind, BO_LOr),
          Field("lhs", &BinOp::lhs,
                Pointer(WhenDynamicCastTo<const UnOp *>(AllOf(
                    Field("kind", &UnOp::kind, UO_Neg),
                    Field("subExpr", &UnOp::subExpr,
                          Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                              "identifier", &VarRef::identifier, "x")))))))),
          Field("rhs", &BinOp::rhs,
                Pointer(WhenDynamicCastTo<const UnOp *>(AllOf(
                    Field("kind", &UnOp::kind, UO_Neg),
                    Field("subExpr", &UnOp::subExpr,
                          Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                              "identifier", &VarRef::identifier, "y")))))))))));
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLOrAfterIntCompare) {
  setSource(R"(
f(int x, int y): bool {
  return y > 10 | x < 6
}
)");
  buildAST();
  EXPECT_THAT(
      ast->returnValue.get(),
      WhenDynamicCastTo<const BinOp *>(AllOf(
          Field("kind", &BinOp::kind, BO_LOr),
          Field("lhs", &BinOp::lhs,
                Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                    Field("kind", &BinOp::kind, BO_Gt),
                    Field("lhs", &BinOp::lhs,
                          Pointer(WhenDynamicCastTo<const VarRef *>(
                              Field("identifier", &VarRef::identifier, "y")))),
                    Field("rhs", &BinOp::rhs,
                          Pointer(WhenDynamicCastTo<const IntConstant *>(
                              Field("value", &IntConstant::value, 10)))))))),
          Field("rhs", &BinOp::rhs,
                Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                    Field("kind", &BinOp::kind, BO_Lt),
                    Field("lhs", &BinOp::lhs,
                          Pointer(WhenDynamicCastTo<const VarRef *>(
                              Field("identifier", &VarRef::identifier, "x")))),
                    Field("rhs", &BinOp::rhs,
                          Pointer(WhenDynamicCastTo<const IntConstant *>(
                              Field("value", &IntConstant::value, 6)))))))))));
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLOrAfterIntCompareWithAdd) {
  setSource(R"(
f(int y, int z): bool {
  return false | y - 3 > z
}
)");
  buildAST();
  EXPECT_THAT(
      ast->returnValue.get(),
      WhenDynamicCastTo<const BinOp *>(AllOf(
          Field("kind", &BinOp::kind, BO_LOr),
          Field("lhs", &BinOp::lhs,
                Pointer(WhenDynamicCastTo<const BoolConstant *>(
                    Field("value", &BoolConstant::value, false)))),
          Field(
              "rhs", &BinOp::rhs,
              Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                  Field("kind", &BinOp::kind, BO_Gt),
                  Field(
                      "lhs", &BinOp::lhs,
                      Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                          Field("kind", &BinOp::kind, BO_Sub),
                          Field("lhs", &BinOp::lhs,
                                Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                                    "identifier", &VarRef::identifier, "y")))),
                          Field(
                              "rhs", &BinOp::rhs,
                              Pointer(WhenDynamicCastTo<const IntConstant *>(
                                  Field("value", &IntConstant::value, 3)))))))),
                  Field("rhs", &BinOp::rhs,
                        Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                            "identifier", &VarRef::identifier, "z")))))))))));
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLOrAfterLAndAndNeg) {
  setSource(R"(
f(bool x, bool y, bool p, bool q): bool {
  return x & y | p & !q
}
)");
  buildAST();
  EXPECT_THAT(
      ast->returnValue.get(),
      WhenDynamicCastTo<const BinOp *>(AllOf(
          Field("kind", &BinOp::kind, BO_LOr),
          Field("lhs", &BinOp::lhs,
                Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                    Field("kind", &BinOp::kind, BO_LAnd),
                    Field("lhs", &BinOp::lhs,
                          Pointer(WhenDynamicCastTo<const VarRef *>(
                              Field("identifier", &VarRef::identifier, "x")))),
                    Field("rhs", &BinOp::rhs,
                          Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                              "identifier", &VarRef::identifier, "y")))))))),
          Field("rhs", &BinOp::rhs,
                Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                    Field("kind", &BinOp::kind, BO_LAnd),
                    Field("lhs", &BinOp::lhs,
                          Pointer(WhenDynamicCastTo<const VarRef *>(
                              Field("identifier", &VarRef::identifier, "p")))),
                    Field("rhs", &BinOp::rhs,
                          Pointer(WhenDynamicCastTo<const UnOp *>(AllOf(
                              Field("kind", &UnOp::kind, UO_Neg),
                              Field("subExpr", &UnOp::subExpr,
                                    Pointer(WhenDynamicCastTo<const VarRef *>(
                                        Field("identifier", &VarRef::identifier,
                                              "q")))))))))))))));
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLOrRhsWrongType) {
  setSource(R"(
f(bool b, int y): bool {
  return b | y
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLOrLhsWrongType) {
  setSource(R"(
f(bool b, int y): bool {
  return y | b
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, ReturnValue_BinopLOrWrongReturnType) {
  setSource(R"(
f(bool p, bool q): int {
  return p | q
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, Stmt_AssignToBoolConst) {
  setSource(R"(
f(bool x): bool {
  x = true
  return x
}
)");
  buildAST();
  EXPECT_THAT(ast->body,
              ElementsAre(Pointer(WhenDynamicCastTo<const Assignment *>(AllOf(
                  Field("var", &Assignment::var, "x"),
                  Field("value", &Assignment::value,
                        Pointer(WhenDynamicCastTo<const BoolConstant *>(
                            Field("value", &BoolConstant::value, true)))))))));
}

TEST_F(ASTBuilderTest, Stmt_AssignToIntConst) {
  setSource(R"(
f(int c): int {
  c = 10
  return c
}
)");
  buildAST();
  EXPECT_THAT(ast->body,
              ElementsAre(Pointer(WhenDynamicCastTo<const Assignment *>(AllOf(
                  Field("var", &Assignment::var, "c"),
                  Field("value", &Assignment::value,
                        Pointer(WhenDynamicCastTo<const IntConstant *>(
                            Field("value", &IntConstant::value, 10)))))))));
}

TEST_F(ASTBuilderTest, Stmt_AssignToComplexIntExpr) {
  setSource(R"(
f(int c, int d): int {
  c = 10 - d
  return c
}
)");
  buildAST();
  EXPECT_THAT(
      ast->body,
      ElementsAre(Pointer(WhenDynamicCastTo<const Assignment *>(AllOf(
          Field("var", &Assignment::var, "c"),
          Field(
              "value", &Assignment::value,
              Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                  Field("kind", &BinOp::kind, BO_Sub),
                  Field("lhs", &BinOp::lhs,
                        Pointer(WhenDynamicCastTo<const IntConstant *>(
                            Field("value", &IntConstant::value, 10)))),
                  Field("rhs", &BinOp::rhs,
                        Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                            "identifier", &VarRef::identifier, "d")))))))))))));
}

TEST_F(ASTBuilderTest, Stmt_AssignToComplexBoolExpr) {
  setSource(R"(
f(bool x, bool y, int p, int q): bool {
  y = true & !x | p < q
  return true
}
)");
  buildAST();
  EXPECT_THAT(
      ast->body,
      ElementsAre(Pointer(WhenDynamicCastTo<const Assignment *>(AllOf(
          Field("var", &Assignment::var, "y"),
          Field(
              "value", &Assignment::value,
              Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                  Field("kind", &BinOp::kind, BO_LOr),
                  Field(
                      "lhs", &BinOp::lhs,
                      Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                          Field("kind", &BinOp::kind, BO_LAnd),
                          Field(
                              "lhs", &BinOp::lhs,
                              Pointer(WhenDynamicCastTo<const BoolConstant *>(
                                  Field("value", &BoolConstant::value, true)))),
                          Field("rhs", &BinOp::rhs,
                                Pointer(WhenDynamicCastTo<const UnOp *>(AllOf(
                                    Field("kind", &UnOp::kind, UO_Neg),
                                    Field("subExpr", &UnOp::subExpr,
                                          Pointer(WhenDynamicCastTo<
                                                  const VarRef *>(Field(
                                              "identifier", &VarRef::identifier,
                                              "x")))))))))))),
                  Field(
                      "rhs", &BinOp::rhs,
                      Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                          Field("kind", &BinOp::kind, BO_Lt),
                          Field("lhs", &BinOp::lhs,
                                Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                                    "identifier", &VarRef::identifier, "p")))),
                          Field("rhs", &BinOp::rhs,
                                Pointer(WhenDynamicCastTo<const VarRef *>(
                                    Field("identifier", &VarRef::identifier,
                                          "q")))))))))))))))));
}

TEST_F(ASTBuilderTest, Stmt_Assign_Multiple) {
  setSource(R"(
f(int a, bool b): int {
  a = 10
  b = false
  a = a + 1
  return 0
}
)");
  buildAST();
  EXPECT_THAT(
      ast->body,
      ElementsAre(
          Pointer(WhenDynamicCastTo<const Assignment *>(
              AllOf(Field("var", &Assignment::var, "a"),
                    Field("value", &Assignment::value,
                          Pointer(WhenDynamicCastTo<const IntConstant *>(
                              Field("value", &IntConstant::value, 10))))))),
          Pointer(WhenDynamicCastTo<const Assignment *>(
              AllOf(Field("var", &Assignment::var, "b"),
                    Field("value", &Assignment::value,
                          Pointer(WhenDynamicCastTo<const BoolConstant *>(
                              Field("value", &BoolConstant::value, false))))))),
          Pointer(WhenDynamicCastTo<const Assignment *>(AllOf(
              Field("var", &Assignment::var, "a"),
              Field("value", &Assignment::value,
                    Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                        Field("kind", &BinOp::kind, BO_Add),
                        Field("lhs", &BinOp::lhs,
                              Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                                  "identifier", &VarRef::identifier, "a")))),
                        Field("rhs", &BinOp::rhs,
                              Pointer(WhenDynamicCastTo<const IntConstant *>(
                                  Field("value", &IntConstant::value,
                                        1)))))))))))));
}
TEST_F(ASTBuilderTest, Stmt_AssignToNonExistantVar) {
  setSource(R"(
f(): int {
  x = 10 - d
  return 1
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, Stmt_AssignWrongType) {
  setSource(R"(
f(int x): int {
  x = true
  return 1
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, Stmt_AssignWrongType2) {
  setSource(R"(
f(bool x): bool {
  x = 1
  return true
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, Stmt_AssignConstLHS) {
  setSource(R"(
f(int x): int {
  1 = x
  return 1
}
)");
  failTest();
}

TEST_F(ASTBuilderTest, Stmt_IfStmt_Empty) {
  setSource(R"(
f(): bool {
  if (false) {} else {}
  return true
}
)");
  buildAST();
  EXPECT_THAT(ast->body,
              ElementsAre(Pointer(WhenDynamicCastTo<const IfStmt *>(AllOf(
                  Field("condition", &IfStmt::condition,
                        Pointer(WhenDynamicCastTo<const BoolConstant *>(
                            Field("value", &BoolConstant::value, false)))),
                  Field("thenBlock", &IfStmt::thenBlock, IsEmpty()),
                  Field("elseBlock", &IfStmt::elseBlock, IsEmpty()))))));
}

TEST_F(ASTBuilderTest, Stmt_IfStmt_Empty_VarCond) {
  setSource(R"(
f(bool x): bool {
  if (x) {} else {}
  return true
}
)");
  buildAST();
  EXPECT_THAT(ast->body,
              ElementsAre(Pointer(WhenDynamicCastTo<const IfStmt *>(
                  AllOf(Field("condition", &IfStmt::condition,
                              Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                                  "identifier", &VarRef::identifier, "x")))),
                        Field("thenBlock", &IfStmt::thenBlock, IsEmpty()),
                        Field("elseBlock", &IfStmt::elseBlock, IsEmpty()))))));
}

TEST_F(ASTBuilderTest, Stmt_IfStmt_Empty_NegCond) {
  setSource(R"(
f(bool x): bool {
  if (!x) {} else {}
  return true
}
)");
  buildAST();
  EXPECT_THAT(
      ast->body,
      ElementsAre(Pointer(WhenDynamicCastTo<const IfStmt *>(AllOf(
          Field("condition", &IfStmt::condition,
                Pointer(WhenDynamicCastTo<const UnOp *>(AllOf(
                    Field("kind", &UnOp::kind, UO_Neg),
                    Field("subExpr", &UnOp::subExpr,
                          Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                              "identifier", &VarRef::identifier, "x")))))))),
          Field("thenBlock", &IfStmt::thenBlock, IsEmpty()),
          Field("elseBlock", &IfStmt::elseBlock, IsEmpty()))))));
}

TEST_F(ASTBuilderTest, Stmt_IfStmt_Empty_AndCond) {
  setSource(R"(
f(bool x): bool {
  if (x & true) {} else {}
  return true
}
)");
  buildAST();
  EXPECT_THAT(
      ast->body,
      ElementsAre(Pointer(WhenDynamicCastTo<const IfStmt *>(AllOf(
          Field("condition", &IfStmt::condition,
                Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                    Field("kind", &BinOp::kind, BO_LAnd),
                    Field("lhs", &BinOp::lhs,
                          Pointer(WhenDynamicCastTo<const VarRef *>(
                              Field("identifier", &VarRef::identifier, "x")))),
                    Field("rhs", &BinOp::rhs,
                          Pointer(WhenDynamicCastTo<const BoolConstant *>(
                              Field("value", &BoolConstant::value, true)))))))),
          Field("thenBlock", &IfStmt::thenBlock, IsEmpty()),
          Field("elseBlock", &IfStmt::elseBlock, IsEmpty()))))));
}

TEST_F(ASTBuilderTest, Stmt_IfStmt_Empty_OrCond) {
  setSource(R"(
f(bool x, bool y): bool {
  if (y | x) {} else {}
  return true
}
)");
  buildAST();
  EXPECT_THAT(
      ast->body,
      ElementsAre(Pointer(WhenDynamicCastTo<const IfStmt *>(AllOf(
          Field("condition", &IfStmt::condition,
                Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                    Field("kind", &BinOp::kind, BO_LOr),
                    Field("lhs", &BinOp::lhs,
                          Pointer(WhenDynamicCastTo<const VarRef *>(
                              Field("identifier", &VarRef::identifier, "y")))),
                    Field("rhs", &BinOp::rhs,
                          Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                              "identifier", &VarRef::identifier, "x")))))))),
          Field("thenBlock", &IfStmt::thenBlock, IsEmpty()),
          Field("elseBlock", &IfStmt::elseBlock, IsEmpty()))))));
}

TEST_F(ASTBuilderTest, Stmt_IfStmt_Empty_CmpCond) {
  setSource(R"(
f(int a, int b): bool {
  if (a < b) {} else {}
  return true
}
)");
  buildAST();
  EXPECT_THAT(
      ast->body,
      ElementsAre(Pointer(WhenDynamicCastTo<const IfStmt *>(AllOf(
          Field("condition", &IfStmt::condition,
                Pointer(WhenDynamicCastTo<const BinOp *>(AllOf(
                    Field("kind", &BinOp::kind, BO_Lt),
                    Field("lhs", &BinOp::lhs,
                          Pointer(WhenDynamicCastTo<const VarRef *>(
                              Field("identifier", &VarRef::identifier, "a")))),
                    Field("rhs", &BinOp::rhs,
                          Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                              "identifier", &VarRef::identifier, "b")))))))),
          Field("thenBlock", &IfStmt::thenBlock, IsEmpty()),
          Field("elseBlock", &IfStmt::elseBlock, IsEmpty()))))));
}

TEST_F(ASTBuilderTest, Stmt_IfStmt_AssignInThenBlock) {
  setSource(R"(
f(int x): bool {
  if (false) {
    x = 0
  } else {}
  return true
}
)");
  buildAST();
  EXPECT_THAT(
      ast->body,
      ElementsAre(Pointer(WhenDynamicCastTo<const IfStmt *>(AllOf(
          Field("condition", &IfStmt::condition,
                Pointer(WhenDynamicCastTo<const BoolConstant *>(
                    Field("value", &BoolConstant::value, false)))),
          Field("thenBlock", &IfStmt::thenBlock,
                ElementsAre(Pointer(WhenDynamicCastTo<const Assignment *>(AllOf(
                    Field("var", &Assignment::var, "x"),
                    Field("value", &Assignment::value,
                          Pointer(WhenDynamicCastTo<const IntConstant *>(
                              Field("value", &IntConstant::value, 0))))))))),
          Field("elseBlock", &IfStmt::elseBlock, IsEmpty()))))));
}

TEST_F(ASTBuilderTest, Stmt_IfStmt_AssignInElseBlock) {
  setSource(R"(
f(int x): bool {
  if (false) {
  } else {
    x = 1
  }
  return true
}
)");
  buildAST();
  EXPECT_THAT(
      ast->body,
      ElementsAre(Pointer(WhenDynamicCastTo<const IfStmt *>(AllOf(
          Field("condition", &IfStmt::condition,
                Pointer(WhenDynamicCastTo<const BoolConstant *>(
                    Field("value", &BoolConstant::value, false)))),
          Field("thenBlock", &IfStmt::thenBlock, IsEmpty()),
          Field("elseBlock", &IfStmt::elseBlock,
                ElementsAre(Pointer(WhenDynamicCastTo<const Assignment *>(AllOf(
                    Field("var", &Assignment::var, "x"),
                    Field("value", &Assignment::value,
                          Pointer(WhenDynamicCastTo<const IntConstant *>(Field(
                              "value", &IntConstant::value, 1))))))))))))));
}

TEST_F(ASTBuilderTest, Stmt_IfStmt_AssignInBothBlocks) {
  setSource(R"(
f(int x, bool y): bool {
  if (false) {
    y = false
  } else {
    x = 31
  }
  return true
}
)");
  buildAST();
  EXPECT_THAT(
      ast->body,
      ElementsAre(Pointer(WhenDynamicCastTo<const IfStmt *>(AllOf(
          Field("condition", &IfStmt::condition,
                Pointer(WhenDynamicCastTo<const BoolConstant *>(
                    Field("value", &BoolConstant::value, false)))),
          Field("thenBlock", &IfStmt::thenBlock,
                ElementsAre(Pointer(WhenDynamicCastTo<const Assignment *>(AllOf(
                    Field("var", &Assignment::var, "y"),
                    Field("value", &Assignment::value,
                          Pointer(WhenDynamicCastTo<const BoolConstant *>(Field(
                              "value", &BoolConstant::value, false))))))))),
          Field("elseBlock", &IfStmt::elseBlock,
                ElementsAre(Pointer(WhenDynamicCastTo<const Assignment *>(AllOf(
                    Field("var", &Assignment::var, "x"),
                    Field("value", &Assignment::value,
                          Pointer(WhenDynamicCastTo<const IntConstant *>(Field(
                              "value", &IntConstant::value, 31))))))))))))));
}

TEST_F(ASTBuilderTest, Stmt_IfStmt_TwoAssignsNested) {
  setSource(R"(
f(int x, bool y): bool {
  if (false) {
    x = x
    y = !y
  } else {
  }
  return true
}
)");
  buildAST();
  EXPECT_THAT(
      ast->body,
      ElementsAre(Pointer(WhenDynamicCastTo<const IfStmt *>(AllOf(
          Field("condition", &IfStmt::condition,
                Pointer(WhenDynamicCastTo<const BoolConstant *>(
                    Field("value", &BoolConstant::value, false)))),
          Field(
              "thenBlock", &IfStmt::thenBlock,
              ElementsAre(
                  Pointer(WhenDynamicCastTo<const Assignment *>(AllOf(
                      Field("var", &Assignment::var, "x"),
                      Field("value", &Assignment::value,
                            Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                                "identifier", &VarRef::identifier, "x"))))))),
                  Pointer(WhenDynamicCastTo<const Assignment *>(AllOf(
                      Field("var", &Assignment::var, "y"),
                      Field(
                          "value", &Assignment::value,
                          Pointer(WhenDynamicCastTo<const UnOp *>(AllOf(
                              Field("kind", &UnOp::kind, UO_Neg),
                              Field("subExpr", &UnOp::subExpr,
                                    Pointer(WhenDynamicCastTo<const VarRef *>(
                                        Field("identifier", &VarRef::identifier,
                                              "y"))))))))))))),
          Field("elseBlock", &IfStmt::elseBlock, IsEmpty()))))));
}

TEST_F(ASTBuilderTest, Stmt_IfStmt_NestedIf) {
  setSource(R"(
f(int x, bool y): bool {
  if (false) {
    if (true) {} else {}
  } else {
  }
  return true
}
)");
  buildAST();
  EXPECT_THAT(
      ast->body,
      ElementsAre(Pointer(WhenDynamicCastTo<const IfStmt *>(AllOf(
          Field("condition", &IfStmt::condition,
                Pointer(WhenDynamicCastTo<const BoolConstant *>(
                    Field("value", &BoolConstant::value, false)))),
          Field("thenBlock", &IfStmt::thenBlock,
                ElementsAre(Pointer(WhenDynamicCastTo<const IfStmt *>(AllOf(
                    Field("condition", &IfStmt::condition,
                          Pointer(WhenDynamicCastTo<const BoolConstant *>(
                              Field("value", &BoolConstant::value, true)))),
                    Field("thenBlock", &IfStmt::thenBlock, IsEmpty()),
                    Field("elseBlock", &IfStmt::elseBlock, IsEmpty())))))),
          Field("elseBlock", &IfStmt::elseBlock, IsEmpty()))))));
}

TEST_F(ASTBuilderTest, Stmt_BodyAssignThenIf) {
  setSource(R"(
f(int x): bool {
  x = 3
  if (false) {} else {}
  return true
}
)");
  buildAST();
  EXPECT_THAT(
      ast->body,
      ElementsAre(Pointer(WhenDynamicCastTo<const Assignment *>(AllOf(
                      Field("var", &Assignment::var, "x"),
                      Field("value", &Assignment::value,
                            Pointer(WhenDynamicCastTo<const IntConstant *>(
                                Field("value", &IntConstant::value, 3))))))),
                  Pointer(WhenDynamicCastTo<const IfStmt *>(AllOf(
                      Field("condition", &IfStmt::condition,
                            Pointer(WhenDynamicCastTo<const BoolConstant *>(
                                Field("value", &BoolConstant::value, false)))),
                      Field("thenBlock", &IfStmt::thenBlock, IsEmpty()),
                      Field("elseBlock", &IfStmt::elseBlock, IsEmpty()))))));
}

TEST_F(ASTBuilderTest, Stmt_BodyIfThenAssign) {
  setSource(R"(
f(int x): bool {
  if (true) {} else {}
  x = x
  return true
}
)");
  buildAST();
  EXPECT_THAT(
      ast->body,
      ElementsAre(Pointer(WhenDynamicCastTo<const IfStmt *>(AllOf(
                      Field("condition", &IfStmt::condition,
                            Pointer(WhenDynamicCastTo<const BoolConstant *>(
                                Field("value", &BoolConstant::value, true)))),
                      Field("thenBlock", &IfStmt::thenBlock, IsEmpty()),
                      Field("elseBlock", &IfStmt::elseBlock, IsEmpty())))),
                  Pointer(WhenDynamicCastTo<const Assignment *>(AllOf(
                      Field("var", &Assignment::var, "x"),
                      Field("value", &Assignment::value,
                            Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                                "identifier", &VarRef::identifier, "x")))))))));
}

TEST_F(ASTBuilderTest, Stmt_BodyTwoIfs) {
  setSource(R"(
f(bool cond): bool {
  if (true) {} else {}
  if (cond) {} else {}
  return true
}
)");
  buildAST();
  EXPECT_THAT(
      ast->body,
      ElementsAre(Pointer(WhenDynamicCastTo<const IfStmt *>(AllOf(
                      Field("condition", &IfStmt::condition,
                            Pointer(WhenDynamicCastTo<const BoolConstant *>(
                                Field("value", &BoolConstant::value, true)))),
                      Field("thenBlock", &IfStmt::thenBlock, IsEmpty()),
                      Field("elseBlock", &IfStmt::elseBlock, IsEmpty())))),
                  Pointer(WhenDynamicCastTo<const IfStmt *>(AllOf(
                      Field("condition", &IfStmt::condition,
                            Pointer(WhenDynamicCastTo<const VarRef *>(Field(
                                "identifier", &VarRef::identifier, "cond")))),
                      Field("thenBlock", &IfStmt::thenBlock, IsEmpty()),
                      Field("elseBlock", &IfStmt::elseBlock, IsEmpty()))))));
}

TEST_F(ASTBuilderTest, Stmt_IfStmt_WrongConditionType) {
  setSource(R"(
f(): bool {
  if (3) {} else {}
  return true
}
)");
  failTest();
}

