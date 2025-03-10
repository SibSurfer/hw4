
// Generated from Lang.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "LangListener.h"


/**
 * This class provides an empty implementation of LangListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  LangBaseListener : public LangListener {
public:

  virtual void enterFunction(LangParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(LangParser::FunctionContext * /*ctx*/) override { }

  virtual void enterParameters(LangParser::ParametersContext * /*ctx*/) override { }
  virtual void exitParameters(LangParser::ParametersContext * /*ctx*/) override { }

  virtual void enterParamdecl(LangParser::ParamdeclContext * /*ctx*/) override { }
  virtual void exitParamdecl(LangParser::ParamdeclContext * /*ctx*/) override { }

  virtual void enterBody(LangParser::BodyContext * /*ctx*/) override { }
  virtual void exitBody(LangParser::BodyContext * /*ctx*/) override { }

  virtual void enterReturnstmt(LangParser::ReturnstmtContext * /*ctx*/) override { }
  virtual void exitReturnstmt(LangParser::ReturnstmtContext * /*ctx*/) override { }

  virtual void enterStatement(LangParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(LangParser::StatementContext * /*ctx*/) override { }

  virtual void enterIfstmt(LangParser::IfstmtContext * /*ctx*/) override { }
  virtual void exitIfstmt(LangParser::IfstmtContext * /*ctx*/) override { }

  virtual void enterThenbody(LangParser::ThenbodyContext * /*ctx*/) override { }
  virtual void exitThenbody(LangParser::ThenbodyContext * /*ctx*/) override { }

  virtual void enterElsebody(LangParser::ElsebodyContext * /*ctx*/) override { }
  virtual void exitElsebody(LangParser::ElsebodyContext * /*ctx*/) override { }

  virtual void enterAssign(LangParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(LangParser::AssignContext * /*ctx*/) override { }

  virtual void enterExpression(LangParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(LangParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterBoolexpr5(LangParser::Boolexpr5Context * /*ctx*/) override { }
  virtual void exitBoolexpr5(LangParser::Boolexpr5Context * /*ctx*/) override { }

  virtual void enterBinoplorexpr(LangParser::BinoplorexprContext * /*ctx*/) override { }
  virtual void exitBinoplorexpr(LangParser::BinoplorexprContext * /*ctx*/) override { }

  virtual void enterBoolexpr4(LangParser::Boolexpr4Context * /*ctx*/) override { }
  virtual void exitBoolexpr4(LangParser::Boolexpr4Context * /*ctx*/) override { }

  virtual void enterBinoplandexpr(LangParser::BinoplandexprContext * /*ctx*/) override { }
  virtual void exitBinoplandexpr(LangParser::BinoplandexprContext * /*ctx*/) override { }

  virtual void enterBoolexpr3(LangParser::Boolexpr3Context * /*ctx*/) override { }
  virtual void exitBoolexpr3(LangParser::Boolexpr3Context * /*ctx*/) override { }

  virtual void enterIntcompareexpr(LangParser::IntcompareexprContext * /*ctx*/) override { }
  virtual void exitIntcompareexpr(LangParser::IntcompareexprContext * /*ctx*/) override { }

  virtual void enterBoolexpr2(LangParser::Boolexpr2Context * /*ctx*/) override { }
  virtual void exitBoolexpr2(LangParser::Boolexpr2Context * /*ctx*/) override { }

  virtual void enterUnopnegateexpr(LangParser::UnopnegateexprContext * /*ctx*/) override { }
  virtual void exitUnopnegateexpr(LangParser::UnopnegateexprContext * /*ctx*/) override { }

  virtual void enterBoolexpr1(LangParser::Boolexpr1Context * /*ctx*/) override { }
  virtual void exitBoolexpr1(LangParser::Boolexpr1Context * /*ctx*/) override { }

  virtual void enterBoolliteral(LangParser::BoolliteralContext * /*ctx*/) override { }
  virtual void exitBoolliteral(LangParser::BoolliteralContext * /*ctx*/) override { }

  virtual void enterIntexpr(LangParser::IntexprContext * /*ctx*/) override { }
  virtual void exitIntexpr(LangParser::IntexprContext * /*ctx*/) override { }

  virtual void enterBinopintexpr(LangParser::BinopintexprContext * /*ctx*/) override { }
  virtual void exitBinopintexpr(LangParser::BinopintexprContext * /*ctx*/) override { }

  virtual void enterAtomintexpr(LangParser::AtomintexprContext * /*ctx*/) override { }
  virtual void exitAtomintexpr(LangParser::AtomintexprContext * /*ctx*/) override { }

  virtual void enterIntliteral(LangParser::IntliteralContext * /*ctx*/) override { }
  virtual void exitIntliteral(LangParser::IntliteralContext * /*ctx*/) override { }

  virtual void enterVarrefexpr(LangParser::VarrefexprContext * /*ctx*/) override { }
  virtual void exitVarrefexpr(LangParser::VarrefexprContext * /*ctx*/) override { }

  virtual void enterType(LangParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(LangParser::TypeContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

