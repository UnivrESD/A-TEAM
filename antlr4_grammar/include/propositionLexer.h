
// Generated from ../assertionminer/antlr4_grammar/proposition.gr by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  propositionLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, NextOp = 6, PastOp = 7, 
    LGPAREN = 8, RGPAREN = 9, LCPAREN = 10, RCPAREN = 11, LPAREN = 12, RPAREN = 13, 
    VARIABLE = 14, NUMERIC = 15, BINARY = 16, BOOLEAN = 17, PLUS = 18, MINUS = 19, 
    TIMES = 20, DIV = 21, GT = 22, GE = 23, LT = 24, LE = 25, EQ = 26, NEQ = 27, 
    BAND = 28, BOR = 29, BXOR = 30, NEG = 31, AND = 32, OR = 33, NOT = 34, 
    WS = 35
  };

  propositionLexer(antlr4::CharStream *input);
  ~propositionLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

