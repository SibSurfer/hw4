
// Generated from Lang.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "LangParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by LangParser.
 */
class  LangListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFunction(LangParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(LangParser::FunctionContext *ctx) = 0;

  virtual void enterParameters(LangParser::ParametersContext *ctx) = 0;
  virtual void exitParameters(LangParser::ParametersContext *ctx) = 0;

  virtual void enterParamdecl(LangParser::ParamdeclContext *ctx) = 0;
  virtual void exitParamdecl(LangParser::ParamdeclContext *ctx) = 0;

  virtual void enterBody(LangParser::BodyContext *ctx) = 0;
  virtual void exitBody(LangParser::BodyContext *ctx) = 0;

  virtual void enterReturnstmt(LangParser::ReturnstmtContext *ctx) = 0;
  virtual void exitReturnstmt(LangParser::ReturnstmtContext *ctx) = 0;

  virtual void enterStatement(LangParser::StatementContext *ctx) = 0;
  virtual void exitStatement(LangParser::StatementContext *ctx) = 0;

  virtual void enterIfstmt(LangParser::IfstmtContext *ctx) = 0;
  virtual void exitIfstmt(LangParser::IfstmtContext *ctx) = 0;

  virtual void enterThenbody(LangParser::ThenbodyContext *ctx) = 0;
  virtual void exitThenbody(LangParser::ThenbodyContext *ctx) = 0;

  virtual void enterElsebody(LangParser::ElsebodyContext *ctx) = 0;
  virtual void exitElsebody(LangParser::ElsebodyContext *ctx) = 0;

  virtual void enterAssign(LangParser::AssignContext *ctx) = 0;
  virtual void exitAssign(LangParser::AssignContext *ctx) = 0;

  virtual void enterExpression(LangParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(LangParser::ExpressionContext *ctx) = 0;

  virtual void enterBoolexpr5(LangParser::Boolexpr5Context *ctx) = 0;
  virtual void exitBoolexpr5(LangParser::Boolexpr5Context *ctx) = 0;

  virtual void enterBinoplorexpr(LangParser::BinoplorexprContext *ctx) = 0;
  virtual void exitBinoplorexpr(LangParser::BinoplorexprContext *ctx) = 0;

  virtual void enterBoolexpr4(LangParser::Boolexpr4Context *ctx) = 0;
  virtual void exitBoolexpr4(LangParser::Boolexpr4Context *ctx) = 0;

  virtual void enterBinoplandexpr(LangParser::BinoplandexprContext *ctx) = 0;
  virtual void exitBinoplandexpr(LangParser::BinoplandexprContext *ctx) = 0;

  virtual void enterBoolexpr3(LangParser::Boolexpr3Context *ctx) = 0;
  virtual void exitBoolexpr3(LangParser::Boolexpr3Context *ctx) = 0;

  virtual void enterIntcompareexpr(LangParser::IntcompareexprContext *ctx) = 0;
  virtual void exitIntcompareexpr(LangParser::IntcompareexprContext *ctx) = 0;

  virtual void enterBoolexpr2(LangParser::Boolexpr2Context *ctx) = 0;
  virtual void exitBoolexpr2(LangParser::Boolexpr2Context *ctx) = 0;

  virtual void enterUnopnegateexpr(LangParser::UnopnegateexprContext *ctx) = 0;
  virtual void exitUnopnegateexpr(LangParser::UnopnegateexprContext *ctx) = 0;

  virtual void enterBoolexpr1(LangParser::Boolexpr1Context *ctx) = 0;
  virtual void exitBoolexpr1(LangParser::Boolexpr1Context *ctx) = 0;

  virtual void enterBoolliteral(LangParser::BoolliteralContext *ctx) = 0;
  virtual void exitBoolliteral(LangParser::BoolliteralContext *ctx) = 0;

  virtual void enterIntexpr(LangParser::IntexprContext *ctx) = 0;
  virtual void exitIntexpr(LangParser::IntexprContext *ctx) = 0;

  virtual void enterBinopintexpr(LangParser::BinopintexprContext *ctx) = 0;
  virtual void exitBinopintexpr(LangParser::BinopintexprContext *ctx) = 0;

  virtual void enterAtomintexpr(LangParser::AtomintexprContext *ctx) = 0;
  virtual void exitAtomintexpr(LangParser::AtomintexprContext *ctx) = 0;

  virtual void enterIntliteral(LangParser::IntliteralContext *ctx) = 0;
  virtual void exitIntliteral(LangParser::IntliteralContext *ctx) = 0;

  virtual void enterVarrefexpr(LangParser::VarrefexprContext *ctx) = 0;
  virtual void exitVarrefexpr(LangParser::VarrefexprContext *ctx) = 0;

  virtual void enterType(LangParser::TypeContext *ctx) = 0;
  virtual void exitType(LangParser::TypeContext *ctx) = 0;


};

