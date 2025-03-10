
// Generated from Lang.g4 by ANTLR 4.13.2


#include "LangLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct LangLexerStaticData final {
  LangLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LangLexerStaticData(const LangLexerStaticData&) = delete;
  LangLexerStaticData(LangLexerStaticData&&) = delete;
  LangLexerStaticData& operator=(const LangLexerStaticData&) = delete;
  LangLexerStaticData& operator=(LangLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag langlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<LangLexerStaticData> langlexerLexerStaticData = nullptr;

void langlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (langlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(langlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LangLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "TRUE", "FALSE", "BOOL", "INT", "NUMBER", "BINOP_ADD", "BINOP_SUB", 
      "BINOP_LT", "BINOP_GT", "BINOP_LAND", "BINOP_LOR", "UNOP_NEGATION", 
      "NAME", "WHITESPACE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,24,129,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,
  	1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,9,1,
  	9,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,
  	12,1,12,1,12,1,13,1,13,1,13,1,13,1,14,4,14,100,8,14,11,14,12,14,101,1,
  	15,1,15,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,1,21,1,21,1,
  	22,4,22,119,8,22,11,22,12,22,120,1,23,4,23,124,8,23,11,23,12,23,125,1,
  	23,1,23,0,0,24,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,
  	12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,
  	47,24,1,0,3,1,0,48,57,1,0,97,122,3,0,9,10,13,13,32,32,131,0,1,1,0,0,0,
  	0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,
  	0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,
  	0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,
  	1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,
  	0,0,0,47,1,0,0,0,1,49,1,0,0,0,3,51,1,0,0,0,5,53,1,0,0,0,7,55,1,0,0,0,
  	9,57,1,0,0,0,11,59,1,0,0,0,13,61,1,0,0,0,15,68,1,0,0,0,17,71,1,0,0,0,
  	19,76,1,0,0,0,21,78,1,0,0,0,23,83,1,0,0,0,25,89,1,0,0,0,27,94,1,0,0,0,
  	29,99,1,0,0,0,31,103,1,0,0,0,33,105,1,0,0,0,35,107,1,0,0,0,37,109,1,0,
  	0,0,39,111,1,0,0,0,41,113,1,0,0,0,43,115,1,0,0,0,45,118,1,0,0,0,47,123,
  	1,0,0,0,49,50,5,40,0,0,50,2,1,0,0,0,51,52,5,41,0,0,52,4,1,0,0,0,53,54,
  	5,58,0,0,54,6,1,0,0,0,55,56,5,123,0,0,56,8,1,0,0,0,57,58,5,125,0,0,58,
  	10,1,0,0,0,59,60,5,44,0,0,60,12,1,0,0,0,61,62,5,114,0,0,62,63,5,101,0,
  	0,63,64,5,116,0,0,64,65,5,117,0,0,65,66,5,114,0,0,66,67,5,110,0,0,67,
  	14,1,0,0,0,68,69,5,105,0,0,69,70,5,102,0,0,70,16,1,0,0,0,71,72,5,101,
  	0,0,72,73,5,108,0,0,73,74,5,115,0,0,74,75,5,101,0,0,75,18,1,0,0,0,76,
  	77,5,61,0,0,77,20,1,0,0,0,78,79,5,116,0,0,79,80,5,114,0,0,80,81,5,117,
  	0,0,81,82,5,101,0,0,82,22,1,0,0,0,83,84,5,102,0,0,84,85,5,97,0,0,85,86,
  	5,108,0,0,86,87,5,115,0,0,87,88,5,101,0,0,88,24,1,0,0,0,89,90,5,98,0,
  	0,90,91,5,111,0,0,91,92,5,111,0,0,92,93,5,108,0,0,93,26,1,0,0,0,94,95,
  	5,105,0,0,95,96,5,110,0,0,96,97,5,116,0,0,97,28,1,0,0,0,98,100,7,0,0,
  	0,99,98,1,0,0,0,100,101,1,0,0,0,101,99,1,0,0,0,101,102,1,0,0,0,102,30,
  	1,0,0,0,103,104,5,43,0,0,104,32,1,0,0,0,105,106,5,45,0,0,106,34,1,0,0,
  	0,107,108,5,60,0,0,108,36,1,0,0,0,109,110,5,62,0,0,110,38,1,0,0,0,111,
  	112,5,38,0,0,112,40,1,0,0,0,113,114,5,124,0,0,114,42,1,0,0,0,115,116,
  	5,33,0,0,116,44,1,0,0,0,117,119,7,1,0,0,118,117,1,0,0,0,119,120,1,0,0,
  	0,120,118,1,0,0,0,120,121,1,0,0,0,121,46,1,0,0,0,122,124,7,2,0,0,123,
  	122,1,0,0,0,124,125,1,0,0,0,125,123,1,0,0,0,125,126,1,0,0,0,126,127,1,
  	0,0,0,127,128,6,23,0,0,128,48,1,0,0,0,4,0,101,120,125,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  langlexerLexerStaticData = std::move(staticData);
}

}

LangLexer::LangLexer(CharStream *input) : Lexer(input) {
  LangLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *langlexerLexerStaticData->atn, langlexerLexerStaticData->decisionToDFA, langlexerLexerStaticData->sharedContextCache);
}

LangLexer::~LangLexer() {
  delete _interpreter;
}

std::string LangLexer::getGrammarFileName() const {
  return "Lang.g4";
}

const std::vector<std::string>& LangLexer::getRuleNames() const {
  return langlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& LangLexer::getChannelNames() const {
  return langlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& LangLexer::getModeNames() const {
  return langlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& LangLexer::getVocabulary() const {
  return langlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView LangLexer::getSerializedATN() const {
  return langlexerLexerStaticData->serializedATN;
}

const atn::ATN& LangLexer::getATN() const {
  return *langlexerLexerStaticData->atn;
}




void LangLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  langlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(langlexerLexerOnceFlag, langlexerLexerInitialize);
#endif
}
