
// Generated from Lang.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  LangLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, TRUE = 11, FALSE = 12, BOOL = 13, INT = 14, 
    NUMBER = 15, BINOP_ADD = 16, BINOP_SUB = 17, BINOP_LT = 18, BINOP_GT = 19, 
    BINOP_LAND = 20, BINOP_LOR = 21, UNOP_NEGATION = 22, NAME = 23, WHITESPACE = 24
  };

  explicit LangLexer(antlr4::CharStream *input);

  ~LangLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

