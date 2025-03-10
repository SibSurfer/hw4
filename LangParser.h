
// Generated from Lang.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  LangParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, TRUE = 11, FALSE = 12, BOOL = 13, INT = 14, 
    NUMBER = 15, BINOP_ADD = 16, BINOP_SUB = 17, BINOP_LT = 18, BINOP_GT = 19, 
    BINOP_LAND = 20, BINOP_LOR = 21, UNOP_NEGATION = 22, NAME = 23, WHITESPACE = 24
  };

  enum {
    RuleFunction = 0, RuleParameters = 1, RuleParamdecl = 2, RuleBody = 3, 
    RuleReturnstmt = 4, RuleStatement = 5, RuleIfstmt = 6, RuleThenbody = 7, 
    RuleElsebody = 8, RuleAssign = 9, RuleExpression = 10, RuleBoolexpr5 = 11, 
    RuleBinoplorexpr = 12, RuleBoolexpr4 = 13, RuleBinoplandexpr = 14, RuleBoolexpr3 = 15, 
    RuleIntcompareexpr = 16, RuleBoolexpr2 = 17, RuleUnopnegateexpr = 18, 
    RuleBoolexpr1 = 19, RuleBoolliteral = 20, RuleIntexpr = 21, RuleBinopintexpr = 22, 
    RuleAtomintexpr = 23, RuleIntliteral = 24, RuleVarrefexpr = 25, RuleType = 26
  };

  explicit LangParser(antlr4::TokenStream *input);

  LangParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~LangParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class FunctionContext;
  class ParametersContext;
  class ParamdeclContext;
  class BodyContext;
  class ReturnstmtContext;
  class StatementContext;
  class IfstmtContext;
  class ThenbodyContext;
  class ElsebodyContext;
  class AssignContext;
  class ExpressionContext;
  class Boolexpr5Context;
  class BinoplorexprContext;
  class Boolexpr4Context;
  class BinoplandexprContext;
  class Boolexpr3Context;
  class IntcompareexprContext;
  class Boolexpr2Context;
  class UnopnegateexprContext;
  class Boolexpr1Context;
  class BoolliteralContext;
  class IntexprContext;
  class BinopintexprContext;
  class AtomintexprContext;
  class IntliteralContext;
  class VarrefexprContext;
  class TypeContext; 

  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    ParametersContext *parameters();
    TypeContext *type();
    BodyContext *body();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionContext* function();

  class  ParametersContext : public antlr4::ParserRuleContext {
  public:
    ParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParamdeclContext *> paramdecl();
    ParamdeclContext* paramdecl(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParametersContext* parameters();

  class  ParamdeclContext : public antlr4::ParserRuleContext {
  public:
    ParamdeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *NAME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParamdeclContext* paramdecl();

  class  BodyContext : public antlr4::ParserRuleContext {
  public:
    BodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ReturnstmtContext *returnstmt();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BodyContext* body();

  class  ReturnstmtContext : public antlr4::ParserRuleContext {
  public:
    ReturnstmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ReturnstmtContext* returnstmt();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IfstmtContext *ifstmt();
    AssignContext *assign();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementContext* statement();

  class  IfstmtContext : public antlr4::ParserRuleContext {
  public:
    IfstmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Boolexpr5Context *boolexpr5();
    ThenbodyContext *thenbody();
    ElsebodyContext *elsebody();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IfstmtContext* ifstmt();

  class  ThenbodyContext : public antlr4::ParserRuleContext {
  public:
    ThenbodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ThenbodyContext* thenbody();

  class  ElsebodyContext : public antlr4::ParserRuleContext {
  public:
    ElsebodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ElsebodyContext* elsebody();

  class  AssignContext : public antlr4::ParserRuleContext {
  public:
    AssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AssignContext* assign();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntexprContext *intexpr();
    Boolexpr5Context *boolexpr5();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();

  class  Boolexpr5Context : public antlr4::ParserRuleContext {
  public:
    Boolexpr5Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Boolexpr4Context *boolexpr4();
    BinoplorexprContext *binoplorexpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Boolexpr5Context* boolexpr5();

  class  BinoplorexprContext : public antlr4::ParserRuleContext {
  public:
    BinoplorexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Boolexpr4Context *boolexpr4();
    antlr4::tree::TerminalNode *BINOP_LOR();
    Boolexpr5Context *boolexpr5();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BinoplorexprContext* binoplorexpr();

  class  Boolexpr4Context : public antlr4::ParserRuleContext {
  public:
    Boolexpr4Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Boolexpr3Context *boolexpr3();
    BinoplandexprContext *binoplandexpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Boolexpr4Context* boolexpr4();

  class  BinoplandexprContext : public antlr4::ParserRuleContext {
  public:
    BinoplandexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Boolexpr3Context *boolexpr3();
    antlr4::tree::TerminalNode *BINOP_LAND();
    Boolexpr4Context *boolexpr4();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BinoplandexprContext* binoplandexpr();

  class  Boolexpr3Context : public antlr4::ParserRuleContext {
  public:
    Boolexpr3Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Boolexpr2Context *boolexpr2();
    IntcompareexprContext *intcompareexpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Boolexpr3Context* boolexpr3();

  class  IntcompareexprContext : public antlr4::ParserRuleContext {
  public:
    IntcompareexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IntexprContext *> intexpr();
    IntexprContext* intexpr(size_t i);
    antlr4::tree::TerminalNode *BINOP_LT();
    antlr4::tree::TerminalNode *BINOP_GT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IntcompareexprContext* intcompareexpr();

  class  Boolexpr2Context : public antlr4::ParserRuleContext {
  public:
    Boolexpr2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Boolexpr1Context *boolexpr1();
    UnopnegateexprContext *unopnegateexpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Boolexpr2Context* boolexpr2();

  class  UnopnegateexprContext : public antlr4::ParserRuleContext {
  public:
    UnopnegateexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNOP_NEGATION();
    Boolexpr2Context *boolexpr2();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UnopnegateexprContext* unopnegateexpr();

  class  Boolexpr1Context : public antlr4::ParserRuleContext {
  public:
    Boolexpr1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BoolliteralContext *boolliteral();
    VarrefexprContext *varrefexpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Boolexpr1Context* boolexpr1();

  class  BoolliteralContext : public antlr4::ParserRuleContext {
  public:
    BoolliteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BoolliteralContext* boolliteral();

  class  IntexprContext : public antlr4::ParserRuleContext {
  public:
    IntexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomintexprContext *atomintexpr();
    BinopintexprContext *binopintexpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IntexprContext* intexpr();

  class  BinopintexprContext : public antlr4::ParserRuleContext {
  public:
    BinopintexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomintexprContext *atomintexpr();
    IntexprContext *intexpr();
    antlr4::tree::TerminalNode *BINOP_ADD();
    antlr4::tree::TerminalNode *BINOP_SUB();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BinopintexprContext* binopintexpr();

  class  AtomintexprContext : public antlr4::ParserRuleContext {
  public:
    AtomintexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntliteralContext *intliteral();
    VarrefexprContext *varrefexpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AtomintexprContext* atomintexpr();

  class  IntliteralContext : public antlr4::ParserRuleContext {
  public:
    IntliteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IntliteralContext* intliteral();

  class  VarrefexprContext : public antlr4::ParserRuleContext {
  public:
    VarrefexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VarrefexprContext* varrefexpr();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOOL();
    antlr4::tree::TerminalNode *INT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TypeContext* type();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

