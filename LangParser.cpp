
// Generated from Lang.g4 by ANTLR 4.13.2


#include "LangListener.h"

#include "LangParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct LangParserStaticData final {
  LangParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LangParserStaticData(const LangParserStaticData&) = delete;
  LangParserStaticData(LangParserStaticData&&) = delete;
  LangParserStaticData& operator=(const LangParserStaticData&) = delete;
  LangParserStaticData& operator=(LangParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag langParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<LangParserStaticData> langParserStaticData = nullptr;

void langParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (langParserStaticData != nullptr) {
    return;
  }
#else
  assert(langParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LangParserStaticData>(
    std::vector<std::string>{
      "function", "parameters", "paramdecl", "body", "returnstmt", "statement", 
      "ifstmt", "thenbody", "elsebody", "assign", "expression", "boolexpr5", 
      "binoplorexpr", "boolexpr4", "binoplandexpr", "boolexpr3", "intcompareexpr", 
      "boolexpr2", "unopnegateexpr", "boolexpr1", "boolliteral", "intexpr", 
      "binopintexpr", "atomintexpr", "intliteral", "varrefexpr", "type"
    },
    std::vector<std::string>{
      "", "'('", "')'", "':'", "'{'", "'}'", "','", "'return'", "'if'", 
      "'else'", "'='", "'true'", "'false'", "'bool'", "'int'", "", "'+'", 
      "'-'", "'<'", "'>'", "'&'", "'|'", "'!'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "TRUE", "FALSE", "BOOL", 
      "INT", "NUMBER", "BINOP_ADD", "BINOP_SUB", "BINOP_LT", "BINOP_GT", 
      "BINOP_LAND", "BINOP_LOR", "UNOP_NEGATION", "NAME", "WHITESPACE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,24,181,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,1,0,1,0,1,0,1,0,
  	1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,5,1,69,8,1,10,1,12,1,72,9,1,3,
  	1,74,8,1,1,2,1,2,1,2,1,3,5,3,80,8,3,10,3,12,3,83,9,3,1,3,1,3,1,4,1,4,
  	1,4,1,5,1,5,3,5,92,8,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,7,5,7,107,8,7,10,7,12,7,110,9,7,1,8,5,8,113,8,8,10,8,12,8,116,9,8,
  	1,9,1,9,1,9,1,9,1,10,1,10,3,10,124,8,10,1,11,1,11,3,11,128,8,11,1,12,
  	1,12,1,12,1,12,1,13,1,13,3,13,136,8,13,1,14,1,14,1,14,1,14,1,15,1,15,
  	3,15,144,8,15,1,16,1,16,1,16,1,16,1,17,1,17,3,17,152,8,17,1,18,1,18,1,
  	18,1,19,1,19,3,19,159,8,19,1,20,1,20,1,21,1,21,3,21,165,8,21,1,22,1,22,
  	1,22,1,22,1,23,1,23,3,23,173,8,23,1,24,1,24,1,25,1,25,1,26,1,26,1,26,
  	0,0,27,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,
  	46,48,50,52,0,4,1,0,18,19,1,0,11,12,1,0,16,17,1,0,13,14,167,0,54,1,0,
  	0,0,2,73,1,0,0,0,4,75,1,0,0,0,6,81,1,0,0,0,8,86,1,0,0,0,10,91,1,0,0,0,
  	12,93,1,0,0,0,14,108,1,0,0,0,16,114,1,0,0,0,18,117,1,0,0,0,20,123,1,0,
  	0,0,22,127,1,0,0,0,24,129,1,0,0,0,26,135,1,0,0,0,28,137,1,0,0,0,30,143,
  	1,0,0,0,32,145,1,0,0,0,34,151,1,0,0,0,36,153,1,0,0,0,38,158,1,0,0,0,40,
  	160,1,0,0,0,42,164,1,0,0,0,44,166,1,0,0,0,46,172,1,0,0,0,48,174,1,0,0,
  	0,50,176,1,0,0,0,52,178,1,0,0,0,54,55,5,23,0,0,55,56,5,1,0,0,56,57,3,
  	2,1,0,57,58,5,2,0,0,58,59,5,3,0,0,59,60,3,52,26,0,60,61,5,4,0,0,61,62,
  	3,6,3,0,62,63,5,5,0,0,63,1,1,0,0,0,64,74,1,0,0,0,65,70,3,4,2,0,66,67,
  	5,6,0,0,67,69,3,4,2,0,68,66,1,0,0,0,69,72,1,0,0,0,70,68,1,0,0,0,70,71,
  	1,0,0,0,71,74,1,0,0,0,72,70,1,0,0,0,73,64,1,0,0,0,73,65,1,0,0,0,74,3,
  	1,0,0,0,75,76,3,52,26,0,76,77,5,23,0,0,77,5,1,0,0,0,78,80,3,10,5,0,79,
  	78,1,0,0,0,80,83,1,0,0,0,81,79,1,0,0,0,81,82,1,0,0,0,82,84,1,0,0,0,83,
  	81,1,0,0,0,84,85,3,8,4,0,85,7,1,0,0,0,86,87,5,7,0,0,87,88,3,20,10,0,88,
  	9,1,0,0,0,89,92,3,12,6,0,90,92,3,18,9,0,91,89,1,0,0,0,91,90,1,0,0,0,92,
  	11,1,0,0,0,93,94,5,8,0,0,94,95,5,1,0,0,95,96,3,22,11,0,96,97,5,2,0,0,
  	97,98,5,4,0,0,98,99,3,14,7,0,99,100,5,5,0,0,100,101,5,9,0,0,101,102,5,
  	4,0,0,102,103,3,16,8,0,103,104,5,5,0,0,104,13,1,0,0,0,105,107,3,10,5,
  	0,106,105,1,0,0,0,107,110,1,0,0,0,108,106,1,0,0,0,108,109,1,0,0,0,109,
  	15,1,0,0,0,110,108,1,0,0,0,111,113,3,10,5,0,112,111,1,0,0,0,113,116,1,
  	0,0,0,114,112,1,0,0,0,114,115,1,0,0,0,115,17,1,0,0,0,116,114,1,0,0,0,
  	117,118,5,23,0,0,118,119,5,10,0,0,119,120,3,20,10,0,120,19,1,0,0,0,121,
  	124,3,42,21,0,122,124,3,22,11,0,123,121,1,0,0,0,123,122,1,0,0,0,124,21,
  	1,0,0,0,125,128,3,26,13,0,126,128,3,24,12,0,127,125,1,0,0,0,127,126,1,
  	0,0,0,128,23,1,0,0,0,129,130,3,26,13,0,130,131,5,21,0,0,131,132,3,22,
  	11,0,132,25,1,0,0,0,133,136,3,30,15,0,134,136,3,28,14,0,135,133,1,0,0,
  	0,135,134,1,0,0,0,136,27,1,0,0,0,137,138,3,30,15,0,138,139,5,20,0,0,139,
  	140,3,26,13,0,140,29,1,0,0,0,141,144,3,34,17,0,142,144,3,32,16,0,143,
  	141,1,0,0,0,143,142,1,0,0,0,144,31,1,0,0,0,145,146,3,42,21,0,146,147,
  	7,0,0,0,147,148,3,42,21,0,148,33,1,0,0,0,149,152,3,38,19,0,150,152,3,
  	36,18,0,151,149,1,0,0,0,151,150,1,0,0,0,152,35,1,0,0,0,153,154,5,22,0,
  	0,154,155,3,34,17,0,155,37,1,0,0,0,156,159,3,40,20,0,157,159,3,50,25,
  	0,158,156,1,0,0,0,158,157,1,0,0,0,159,39,1,0,0,0,160,161,7,1,0,0,161,
  	41,1,0,0,0,162,165,3,46,23,0,163,165,3,44,22,0,164,162,1,0,0,0,164,163,
  	1,0,0,0,165,43,1,0,0,0,166,167,3,46,23,0,167,168,7,2,0,0,168,169,3,42,
  	21,0,169,45,1,0,0,0,170,173,3,48,24,0,171,173,3,50,25,0,172,170,1,0,0,
  	0,172,171,1,0,0,0,173,47,1,0,0,0,174,175,5,15,0,0,175,49,1,0,0,0,176,
  	177,5,23,0,0,177,51,1,0,0,0,178,179,7,3,0,0,179,53,1,0,0,0,14,70,73,81,
  	91,108,114,123,127,135,143,151,158,164,172
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  langParserStaticData = std::move(staticData);
}

}

LangParser::LangParser(TokenStream *input) : LangParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

LangParser::LangParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  LangParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *langParserStaticData->atn, langParserStaticData->decisionToDFA, langParserStaticData->sharedContextCache, options);
}

LangParser::~LangParser() {
  delete _interpreter;
}

const atn::ATN& LangParser::getATN() const {
  return *langParserStaticData->atn;
}

std::string LangParser::getGrammarFileName() const {
  return "Lang.g4";
}

const std::vector<std::string>& LangParser::getRuleNames() const {
  return langParserStaticData->ruleNames;
}

const dfa::Vocabulary& LangParser::getVocabulary() const {
  return langParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView LangParser::getSerializedATN() const {
  return langParserStaticData->serializedATN;
}


//----------------- FunctionContext ------------------------------------------------------------------

LangParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LangParser::FunctionContext::NAME() {
  return getToken(LangParser::NAME, 0);
}

LangParser::ParametersContext* LangParser::FunctionContext::parameters() {
  return getRuleContext<LangParser::ParametersContext>(0);
}

LangParser::TypeContext* LangParser::FunctionContext::type() {
  return getRuleContext<LangParser::TypeContext>(0);
}

LangParser::BodyContext* LangParser::FunctionContext::body() {
  return getRuleContext<LangParser::BodyContext>(0);
}


size_t LangParser::FunctionContext::getRuleIndex() const {
  return LangParser::RuleFunction;
}

void LangParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void LangParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}

LangParser::FunctionContext* LangParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 0, LangParser::RuleFunction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    match(LangParser::NAME);
    setState(55);
    match(LangParser::T__0);
    setState(56);
    parameters();
    setState(57);
    match(LangParser::T__1);
    setState(58);
    match(LangParser::T__2);
    setState(59);
    type();
    setState(60);
    match(LangParser::T__3);
    setState(61);
    body();
    setState(62);
    match(LangParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

LangParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LangParser::ParamdeclContext *> LangParser::ParametersContext::paramdecl() {
  return getRuleContexts<LangParser::ParamdeclContext>();
}

LangParser::ParamdeclContext* LangParser::ParametersContext::paramdecl(size_t i) {
  return getRuleContext<LangParser::ParamdeclContext>(i);
}


size_t LangParser::ParametersContext::getRuleIndex() const {
  return LangParser::RuleParameters;
}

void LangParser::ParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameters(this);
}

void LangParser::ParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameters(this);
}

LangParser::ParametersContext* LangParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 2, LangParser::RuleParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(73);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LangParser::T__1: {
        enterOuterAlt(_localctx, 1);

        break;
      }

      case LangParser::BOOL:
      case LangParser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(65);
        paramdecl();
        setState(70);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == LangParser::T__5) {
          setState(66);
          match(LangParser::T__5);
          setState(67);
          paramdecl();
          setState(72);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamdeclContext ------------------------------------------------------------------

LangParser::ParamdeclContext::ParamdeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LangParser::TypeContext* LangParser::ParamdeclContext::type() {
  return getRuleContext<LangParser::TypeContext>(0);
}

tree::TerminalNode* LangParser::ParamdeclContext::NAME() {
  return getToken(LangParser::NAME, 0);
}


size_t LangParser::ParamdeclContext::getRuleIndex() const {
  return LangParser::RuleParamdecl;
}

void LangParser::ParamdeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamdecl(this);
}

void LangParser::ParamdeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamdecl(this);
}

LangParser::ParamdeclContext* LangParser::paramdecl() {
  ParamdeclContext *_localctx = _tracker.createInstance<ParamdeclContext>(_ctx, getState());
  enterRule(_localctx, 4, LangParser::RuleParamdecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(75);
    type();
    setState(76);
    match(LangParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BodyContext ------------------------------------------------------------------

LangParser::BodyContext::BodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LangParser::ReturnstmtContext* LangParser::BodyContext::returnstmt() {
  return getRuleContext<LangParser::ReturnstmtContext>(0);
}

std::vector<LangParser::StatementContext *> LangParser::BodyContext::statement() {
  return getRuleContexts<LangParser::StatementContext>();
}

LangParser::StatementContext* LangParser::BodyContext::statement(size_t i) {
  return getRuleContext<LangParser::StatementContext>(i);
}


size_t LangParser::BodyContext::getRuleIndex() const {
  return LangParser::RuleBody;
}

void LangParser::BodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBody(this);
}

void LangParser::BodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBody(this);
}

LangParser::BodyContext* LangParser::body() {
  BodyContext *_localctx = _tracker.createInstance<BodyContext>(_ctx, getState());
  enterRule(_localctx, 6, LangParser::RuleBody);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(81);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LangParser::T__7

    || _la == LangParser::NAME) {
      setState(78);
      statement();
      setState(83);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(84);
    returnstmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnstmtContext ------------------------------------------------------------------

LangParser::ReturnstmtContext::ReturnstmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LangParser::ExpressionContext* LangParser::ReturnstmtContext::expression() {
  return getRuleContext<LangParser::ExpressionContext>(0);
}


size_t LangParser::ReturnstmtContext::getRuleIndex() const {
  return LangParser::RuleReturnstmt;
}

void LangParser::ReturnstmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnstmt(this);
}

void LangParser::ReturnstmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnstmt(this);
}

LangParser::ReturnstmtContext* LangParser::returnstmt() {
  ReturnstmtContext *_localctx = _tracker.createInstance<ReturnstmtContext>(_ctx, getState());
  enterRule(_localctx, 8, LangParser::RuleReturnstmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(86);
    match(LangParser::T__6);
    setState(87);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

LangParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LangParser::IfstmtContext* LangParser::StatementContext::ifstmt() {
  return getRuleContext<LangParser::IfstmtContext>(0);
}

LangParser::AssignContext* LangParser::StatementContext::assign() {
  return getRuleContext<LangParser::AssignContext>(0);
}


size_t LangParser::StatementContext::getRuleIndex() const {
  return LangParser::RuleStatement;
}

void LangParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void LangParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

LangParser::StatementContext* LangParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 10, LangParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(91);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LangParser::T__7: {
        enterOuterAlt(_localctx, 1);
        setState(89);
        ifstmt();
        break;
      }

      case LangParser::NAME: {
        enterOuterAlt(_localctx, 2);
        setState(90);
        assign();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfstmtContext ------------------------------------------------------------------

LangParser::IfstmtContext::IfstmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LangParser::Boolexpr5Context* LangParser::IfstmtContext::boolexpr5() {
  return getRuleContext<LangParser::Boolexpr5Context>(0);
}

LangParser::ThenbodyContext* LangParser::IfstmtContext::thenbody() {
  return getRuleContext<LangParser::ThenbodyContext>(0);
}

LangParser::ElsebodyContext* LangParser::IfstmtContext::elsebody() {
  return getRuleContext<LangParser::ElsebodyContext>(0);
}


size_t LangParser::IfstmtContext::getRuleIndex() const {
  return LangParser::RuleIfstmt;
}

void LangParser::IfstmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfstmt(this);
}

void LangParser::IfstmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfstmt(this);
}

LangParser::IfstmtContext* LangParser::ifstmt() {
  IfstmtContext *_localctx = _tracker.createInstance<IfstmtContext>(_ctx, getState());
  enterRule(_localctx, 12, LangParser::RuleIfstmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    match(LangParser::T__7);
    setState(94);
    match(LangParser::T__0);
    setState(95);
    boolexpr5();
    setState(96);
    match(LangParser::T__1);
    setState(97);
    match(LangParser::T__3);
    setState(98);
    thenbody();
    setState(99);
    match(LangParser::T__4);
    setState(100);
    match(LangParser::T__8);
    setState(101);
    match(LangParser::T__3);
    setState(102);
    elsebody();
    setState(103);
    match(LangParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThenbodyContext ------------------------------------------------------------------

LangParser::ThenbodyContext::ThenbodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LangParser::StatementContext *> LangParser::ThenbodyContext::statement() {
  return getRuleContexts<LangParser::StatementContext>();
}

LangParser::StatementContext* LangParser::ThenbodyContext::statement(size_t i) {
  return getRuleContext<LangParser::StatementContext>(i);
}


size_t LangParser::ThenbodyContext::getRuleIndex() const {
  return LangParser::RuleThenbody;
}

void LangParser::ThenbodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThenbody(this);
}

void LangParser::ThenbodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThenbody(this);
}

LangParser::ThenbodyContext* LangParser::thenbody() {
  ThenbodyContext *_localctx = _tracker.createInstance<ThenbodyContext>(_ctx, getState());
  enterRule(_localctx, 14, LangParser::RuleThenbody);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LangParser::T__7

    || _la == LangParser::NAME) {
      setState(105);
      statement();
      setState(110);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElsebodyContext ------------------------------------------------------------------

LangParser::ElsebodyContext::ElsebodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LangParser::StatementContext *> LangParser::ElsebodyContext::statement() {
  return getRuleContexts<LangParser::StatementContext>();
}

LangParser::StatementContext* LangParser::ElsebodyContext::statement(size_t i) {
  return getRuleContext<LangParser::StatementContext>(i);
}


size_t LangParser::ElsebodyContext::getRuleIndex() const {
  return LangParser::RuleElsebody;
}

void LangParser::ElsebodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElsebody(this);
}

void LangParser::ElsebodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElsebody(this);
}

LangParser::ElsebodyContext* LangParser::elsebody() {
  ElsebodyContext *_localctx = _tracker.createInstance<ElsebodyContext>(_ctx, getState());
  enterRule(_localctx, 16, LangParser::RuleElsebody);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LangParser::T__7

    || _la == LangParser::NAME) {
      setState(111);
      statement();
      setState(116);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignContext ------------------------------------------------------------------

LangParser::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LangParser::AssignContext::NAME() {
  return getToken(LangParser::NAME, 0);
}

LangParser::ExpressionContext* LangParser::AssignContext::expression() {
  return getRuleContext<LangParser::ExpressionContext>(0);
}


size_t LangParser::AssignContext::getRuleIndex() const {
  return LangParser::RuleAssign;
}

void LangParser::AssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign(this);
}

void LangParser::AssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign(this);
}

LangParser::AssignContext* LangParser::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 18, LangParser::RuleAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(117);
    match(LangParser::NAME);
    setState(118);
    match(LangParser::T__9);
    setState(119);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

LangParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LangParser::IntexprContext* LangParser::ExpressionContext::intexpr() {
  return getRuleContext<LangParser::IntexprContext>(0);
}

LangParser::Boolexpr5Context* LangParser::ExpressionContext::boolexpr5() {
  return getRuleContext<LangParser::Boolexpr5Context>(0);
}


size_t LangParser::ExpressionContext::getRuleIndex() const {
  return LangParser::RuleExpression;
}

void LangParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void LangParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

LangParser::ExpressionContext* LangParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 20, LangParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(123);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(121);
      intexpr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(122);
      boolexpr5();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Boolexpr5Context ------------------------------------------------------------------

LangParser::Boolexpr5Context::Boolexpr5Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LangParser::Boolexpr4Context* LangParser::Boolexpr5Context::boolexpr4() {
  return getRuleContext<LangParser::Boolexpr4Context>(0);
}

LangParser::BinoplorexprContext* LangParser::Boolexpr5Context::binoplorexpr() {
  return getRuleContext<LangParser::BinoplorexprContext>(0);
}


size_t LangParser::Boolexpr5Context::getRuleIndex() const {
  return LangParser::RuleBoolexpr5;
}

void LangParser::Boolexpr5Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolexpr5(this);
}

void LangParser::Boolexpr5Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolexpr5(this);
}

LangParser::Boolexpr5Context* LangParser::boolexpr5() {
  Boolexpr5Context *_localctx = _tracker.createInstance<Boolexpr5Context>(_ctx, getState());
  enterRule(_localctx, 22, LangParser::RuleBoolexpr5);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(127);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(125);
      boolexpr4();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(126);
      binoplorexpr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BinoplorexprContext ------------------------------------------------------------------

LangParser::BinoplorexprContext::BinoplorexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LangParser::Boolexpr4Context* LangParser::BinoplorexprContext::boolexpr4() {
  return getRuleContext<LangParser::Boolexpr4Context>(0);
}

tree::TerminalNode* LangParser::BinoplorexprContext::BINOP_LOR() {
  return getToken(LangParser::BINOP_LOR, 0);
}

LangParser::Boolexpr5Context* LangParser::BinoplorexprContext::boolexpr5() {
  return getRuleContext<LangParser::Boolexpr5Context>(0);
}


size_t LangParser::BinoplorexprContext::getRuleIndex() const {
  return LangParser::RuleBinoplorexpr;
}

void LangParser::BinoplorexprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinoplorexpr(this);
}

void LangParser::BinoplorexprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinoplorexpr(this);
}

LangParser::BinoplorexprContext* LangParser::binoplorexpr() {
  BinoplorexprContext *_localctx = _tracker.createInstance<BinoplorexprContext>(_ctx, getState());
  enterRule(_localctx, 24, LangParser::RuleBinoplorexpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(129);
    boolexpr4();
    setState(130);
    match(LangParser::BINOP_LOR);
    setState(131);
    boolexpr5();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Boolexpr4Context ------------------------------------------------------------------

LangParser::Boolexpr4Context::Boolexpr4Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LangParser::Boolexpr3Context* LangParser::Boolexpr4Context::boolexpr3() {
  return getRuleContext<LangParser::Boolexpr3Context>(0);
}

LangParser::BinoplandexprContext* LangParser::Boolexpr4Context::binoplandexpr() {
  return getRuleContext<LangParser::BinoplandexprContext>(0);
}


size_t LangParser::Boolexpr4Context::getRuleIndex() const {
  return LangParser::RuleBoolexpr4;
}

void LangParser::Boolexpr4Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolexpr4(this);
}

void LangParser::Boolexpr4Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolexpr4(this);
}

LangParser::Boolexpr4Context* LangParser::boolexpr4() {
  Boolexpr4Context *_localctx = _tracker.createInstance<Boolexpr4Context>(_ctx, getState());
  enterRule(_localctx, 26, LangParser::RuleBoolexpr4);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(135);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(133);
      boolexpr3();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(134);
      binoplandexpr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BinoplandexprContext ------------------------------------------------------------------

LangParser::BinoplandexprContext::BinoplandexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LangParser::Boolexpr3Context* LangParser::BinoplandexprContext::boolexpr3() {
  return getRuleContext<LangParser::Boolexpr3Context>(0);
}

tree::TerminalNode* LangParser::BinoplandexprContext::BINOP_LAND() {
  return getToken(LangParser::BINOP_LAND, 0);
}

LangParser::Boolexpr4Context* LangParser::BinoplandexprContext::boolexpr4() {
  return getRuleContext<LangParser::Boolexpr4Context>(0);
}


size_t LangParser::BinoplandexprContext::getRuleIndex() const {
  return LangParser::RuleBinoplandexpr;
}

void LangParser::BinoplandexprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinoplandexpr(this);
}

void LangParser::BinoplandexprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinoplandexpr(this);
}

LangParser::BinoplandexprContext* LangParser::binoplandexpr() {
  BinoplandexprContext *_localctx = _tracker.createInstance<BinoplandexprContext>(_ctx, getState());
  enterRule(_localctx, 28, LangParser::RuleBinoplandexpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    boolexpr3();
    setState(138);
    match(LangParser::BINOP_LAND);
    setState(139);
    boolexpr4();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Boolexpr3Context ------------------------------------------------------------------

LangParser::Boolexpr3Context::Boolexpr3Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LangParser::Boolexpr2Context* LangParser::Boolexpr3Context::boolexpr2() {
  return getRuleContext<LangParser::Boolexpr2Context>(0);
}

LangParser::IntcompareexprContext* LangParser::Boolexpr3Context::intcompareexpr() {
  return getRuleContext<LangParser::IntcompareexprContext>(0);
}


size_t LangParser::Boolexpr3Context::getRuleIndex() const {
  return LangParser::RuleBoolexpr3;
}

void LangParser::Boolexpr3Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolexpr3(this);
}

void LangParser::Boolexpr3Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolexpr3(this);
}

LangParser::Boolexpr3Context* LangParser::boolexpr3() {
  Boolexpr3Context *_localctx = _tracker.createInstance<Boolexpr3Context>(_ctx, getState());
  enterRule(_localctx, 30, LangParser::RuleBoolexpr3);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(143);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(141);
      boolexpr2();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(142);
      intcompareexpr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntcompareexprContext ------------------------------------------------------------------

LangParser::IntcompareexprContext::IntcompareexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LangParser::IntexprContext *> LangParser::IntcompareexprContext::intexpr() {
  return getRuleContexts<LangParser::IntexprContext>();
}

LangParser::IntexprContext* LangParser::IntcompareexprContext::intexpr(size_t i) {
  return getRuleContext<LangParser::IntexprContext>(i);
}

tree::TerminalNode* LangParser::IntcompareexprContext::BINOP_LT() {
  return getToken(LangParser::BINOP_LT, 0);
}

tree::TerminalNode* LangParser::IntcompareexprContext::BINOP_GT() {
  return getToken(LangParser::BINOP_GT, 0);
}


size_t LangParser::IntcompareexprContext::getRuleIndex() const {
  return LangParser::RuleIntcompareexpr;
}

void LangParser::IntcompareexprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntcompareexpr(this);
}

void LangParser::IntcompareexprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntcompareexpr(this);
}

LangParser::IntcompareexprContext* LangParser::intcompareexpr() {
  IntcompareexprContext *_localctx = _tracker.createInstance<IntcompareexprContext>(_ctx, getState());
  enterRule(_localctx, 32, LangParser::RuleIntcompareexpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
    intexpr();
    setState(146);
    _la = _input->LA(1);
    if (!(_la == LangParser::BINOP_LT

    || _la == LangParser::BINOP_GT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(147);
    intexpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Boolexpr2Context ------------------------------------------------------------------

LangParser::Boolexpr2Context::Boolexpr2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LangParser::Boolexpr1Context* LangParser::Boolexpr2Context::boolexpr1() {
  return getRuleContext<LangParser::Boolexpr1Context>(0);
}

LangParser::UnopnegateexprContext* LangParser::Boolexpr2Context::unopnegateexpr() {
  return getRuleContext<LangParser::UnopnegateexprContext>(0);
}


size_t LangParser::Boolexpr2Context::getRuleIndex() const {
  return LangParser::RuleBoolexpr2;
}

void LangParser::Boolexpr2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolexpr2(this);
}

void LangParser::Boolexpr2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolexpr2(this);
}

LangParser::Boolexpr2Context* LangParser::boolexpr2() {
  Boolexpr2Context *_localctx = _tracker.createInstance<Boolexpr2Context>(_ctx, getState());
  enterRule(_localctx, 34, LangParser::RuleBoolexpr2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(151);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LangParser::TRUE:
      case LangParser::FALSE:
      case LangParser::NAME: {
        enterOuterAlt(_localctx, 1);
        setState(149);
        boolexpr1();
        break;
      }

      case LangParser::UNOP_NEGATION: {
        enterOuterAlt(_localctx, 2);
        setState(150);
        unopnegateexpr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnopnegateexprContext ------------------------------------------------------------------

LangParser::UnopnegateexprContext::UnopnegateexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LangParser::UnopnegateexprContext::UNOP_NEGATION() {
  return getToken(LangParser::UNOP_NEGATION, 0);
}

LangParser::Boolexpr2Context* LangParser::UnopnegateexprContext::boolexpr2() {
  return getRuleContext<LangParser::Boolexpr2Context>(0);
}


size_t LangParser::UnopnegateexprContext::getRuleIndex() const {
  return LangParser::RuleUnopnegateexpr;
}

void LangParser::UnopnegateexprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnopnegateexpr(this);
}

void LangParser::UnopnegateexprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnopnegateexpr(this);
}

LangParser::UnopnegateexprContext* LangParser::unopnegateexpr() {
  UnopnegateexprContext *_localctx = _tracker.createInstance<UnopnegateexprContext>(_ctx, getState());
  enterRule(_localctx, 36, LangParser::RuleUnopnegateexpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    match(LangParser::UNOP_NEGATION);
    setState(154);
    boolexpr2();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Boolexpr1Context ------------------------------------------------------------------

LangParser::Boolexpr1Context::Boolexpr1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LangParser::BoolliteralContext* LangParser::Boolexpr1Context::boolliteral() {
  return getRuleContext<LangParser::BoolliteralContext>(0);
}

LangParser::VarrefexprContext* LangParser::Boolexpr1Context::varrefexpr() {
  return getRuleContext<LangParser::VarrefexprContext>(0);
}


size_t LangParser::Boolexpr1Context::getRuleIndex() const {
  return LangParser::RuleBoolexpr1;
}

void LangParser::Boolexpr1Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolexpr1(this);
}

void LangParser::Boolexpr1Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolexpr1(this);
}

LangParser::Boolexpr1Context* LangParser::boolexpr1() {
  Boolexpr1Context *_localctx = _tracker.createInstance<Boolexpr1Context>(_ctx, getState());
  enterRule(_localctx, 38, LangParser::RuleBoolexpr1);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(158);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LangParser::TRUE:
      case LangParser::FALSE: {
        enterOuterAlt(_localctx, 1);
        setState(156);
        boolliteral();
        break;
      }

      case LangParser::NAME: {
        enterOuterAlt(_localctx, 2);
        setState(157);
        varrefexpr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoolliteralContext ------------------------------------------------------------------

LangParser::BoolliteralContext::BoolliteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LangParser::BoolliteralContext::TRUE() {
  return getToken(LangParser::TRUE, 0);
}

tree::TerminalNode* LangParser::BoolliteralContext::FALSE() {
  return getToken(LangParser::FALSE, 0);
}


size_t LangParser::BoolliteralContext::getRuleIndex() const {
  return LangParser::RuleBoolliteral;
}

void LangParser::BoolliteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolliteral(this);
}

void LangParser::BoolliteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolliteral(this);
}

LangParser::BoolliteralContext* LangParser::boolliteral() {
  BoolliteralContext *_localctx = _tracker.createInstance<BoolliteralContext>(_ctx, getState());
  enterRule(_localctx, 40, LangParser::RuleBoolliteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(160);
    _la = _input->LA(1);
    if (!(_la == LangParser::TRUE

    || _la == LangParser::FALSE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntexprContext ------------------------------------------------------------------

LangParser::IntexprContext::IntexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LangParser::AtomintexprContext* LangParser::IntexprContext::atomintexpr() {
  return getRuleContext<LangParser::AtomintexprContext>(0);
}

LangParser::BinopintexprContext* LangParser::IntexprContext::binopintexpr() {
  return getRuleContext<LangParser::BinopintexprContext>(0);
}


size_t LangParser::IntexprContext::getRuleIndex() const {
  return LangParser::RuleIntexpr;
}

void LangParser::IntexprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntexpr(this);
}

void LangParser::IntexprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntexpr(this);
}

LangParser::IntexprContext* LangParser::intexpr() {
  IntexprContext *_localctx = _tracker.createInstance<IntexprContext>(_ctx, getState());
  enterRule(_localctx, 42, LangParser::RuleIntexpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(164);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(162);
      atomintexpr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(163);
      binopintexpr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BinopintexprContext ------------------------------------------------------------------

LangParser::BinopintexprContext::BinopintexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LangParser::AtomintexprContext* LangParser::BinopintexprContext::atomintexpr() {
  return getRuleContext<LangParser::AtomintexprContext>(0);
}

LangParser::IntexprContext* LangParser::BinopintexprContext::intexpr() {
  return getRuleContext<LangParser::IntexprContext>(0);
}

tree::TerminalNode* LangParser::BinopintexprContext::BINOP_ADD() {
  return getToken(LangParser::BINOP_ADD, 0);
}

tree::TerminalNode* LangParser::BinopintexprContext::BINOP_SUB() {
  return getToken(LangParser::BINOP_SUB, 0);
}


size_t LangParser::BinopintexprContext::getRuleIndex() const {
  return LangParser::RuleBinopintexpr;
}

void LangParser::BinopintexprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinopintexpr(this);
}

void LangParser::BinopintexprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinopintexpr(this);
}

LangParser::BinopintexprContext* LangParser::binopintexpr() {
  BinopintexprContext *_localctx = _tracker.createInstance<BinopintexprContext>(_ctx, getState());
  enterRule(_localctx, 44, LangParser::RuleBinopintexpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    atomintexpr();
    setState(167);
    _la = _input->LA(1);
    if (!(_la == LangParser::BINOP_ADD

    || _la == LangParser::BINOP_SUB)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(168);
    intexpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomintexprContext ------------------------------------------------------------------

LangParser::AtomintexprContext::AtomintexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LangParser::IntliteralContext* LangParser::AtomintexprContext::intliteral() {
  return getRuleContext<LangParser::IntliteralContext>(0);
}

LangParser::VarrefexprContext* LangParser::AtomintexprContext::varrefexpr() {
  return getRuleContext<LangParser::VarrefexprContext>(0);
}


size_t LangParser::AtomintexprContext::getRuleIndex() const {
  return LangParser::RuleAtomintexpr;
}

void LangParser::AtomintexprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtomintexpr(this);
}

void LangParser::AtomintexprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtomintexpr(this);
}

LangParser::AtomintexprContext* LangParser::atomintexpr() {
  AtomintexprContext *_localctx = _tracker.createInstance<AtomintexprContext>(_ctx, getState());
  enterRule(_localctx, 46, LangParser::RuleAtomintexpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(172);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LangParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(170);
        intliteral();
        break;
      }

      case LangParser::NAME: {
        enterOuterAlt(_localctx, 2);
        setState(171);
        varrefexpr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntliteralContext ------------------------------------------------------------------

LangParser::IntliteralContext::IntliteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LangParser::IntliteralContext::NUMBER() {
  return getToken(LangParser::NUMBER, 0);
}


size_t LangParser::IntliteralContext::getRuleIndex() const {
  return LangParser::RuleIntliteral;
}

void LangParser::IntliteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntliteral(this);
}

void LangParser::IntliteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntliteral(this);
}

LangParser::IntliteralContext* LangParser::intliteral() {
  IntliteralContext *_localctx = _tracker.createInstance<IntliteralContext>(_ctx, getState());
  enterRule(_localctx, 48, LangParser::RuleIntliteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    match(LangParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarrefexprContext ------------------------------------------------------------------

LangParser::VarrefexprContext::VarrefexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LangParser::VarrefexprContext::NAME() {
  return getToken(LangParser::NAME, 0);
}


size_t LangParser::VarrefexprContext::getRuleIndex() const {
  return LangParser::RuleVarrefexpr;
}

void LangParser::VarrefexprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarrefexpr(this);
}

void LangParser::VarrefexprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarrefexpr(this);
}

LangParser::VarrefexprContext* LangParser::varrefexpr() {
  VarrefexprContext *_localctx = _tracker.createInstance<VarrefexprContext>(_ctx, getState());
  enterRule(_localctx, 50, LangParser::RuleVarrefexpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
    match(LangParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

LangParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LangParser::TypeContext::BOOL() {
  return getToken(LangParser::BOOL, 0);
}

tree::TerminalNode* LangParser::TypeContext::INT() {
  return getToken(LangParser::INT, 0);
}


size_t LangParser::TypeContext::getRuleIndex() const {
  return LangParser::RuleType;
}

void LangParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void LangParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

LangParser::TypeContext* LangParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 52, LangParser::RuleType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    _la = _input->LA(1);
    if (!(_la == LangParser::BOOL

    || _la == LangParser::INT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void LangParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  langParserInitialize();
#else
  ::antlr4::internal::call_once(langParserOnceFlag, langParserInitialize);
#endif
}
