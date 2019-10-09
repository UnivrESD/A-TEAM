
// Generated from ../assertionminer/antlr4_grammar/proposition.gr by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  propositionLexer : public antlr4::Lexer {
public:
  enum {
    NextOp = 1, LCPAREN = 2, RCPAREN = 3, LPAREN = 4, RPAREN = 5, VARIABLE = 6, 
    CONSTANT = 7, PLUS = 8, MINUS = 9, TIMES = 10, DIV = 11, GT_ = 12, GE_ = 13, 
    LT_ = 14, LE_ = 15, EQ_ = 16, NEQ_ = 17, GT = 18, GE = 19, LT = 20, 
    LE = 21, EQ = 22, NEQ = 23, BAND = 24, BOR = 25, BXOR = 26, NEG = 27, 
    PLUS_ = 28, MINUS_ = 29, TIMES_ = 30, DIV_ = 31, AND = 32, OR = 33, 
    NOT = 34, WS = 35
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

