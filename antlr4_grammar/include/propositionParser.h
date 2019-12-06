
// Generated from ../assertionminer/antlr4_grammar/proposition.gr by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  propositionParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, NextOp = 2, PastOp = 3, LCPAREN = 4, RCPAREN = 5, LPAREN = 6, 
    RPAREN = 7, VARIABLE = 8, CONSTANT = 9, PLUS = 10, MINUS = 11, TIMES = 12, 
    DIV = 13, GT = 14, GE = 15, LT = 16, LE = 17, EQ = 18, NEQ = 19, BAND = 20, 
    BOR = 21, BXOR = 22, NEG = 23, AND = 24, OR = 25, NOT = 26, WS = 27
  };

  enum {
    RuleFile = 0, RuleExpression = 1, RuleNumeric_logic = 2, RuleLogic = 3, 
    RuleAtom = 4, RuleConstant = 5, RuleVariable = 6, RuleRelop = 7
  };

  propositionParser(antlr4::TokenStream *input);
  ~propositionParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FileContext;
  class ExpressionContext;
  class Numeric_logicContext;
  class LogicContext;
  class AtomContext;
  class ConstantContext;
  class VariableContext;
  class RelopContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FileContext* file();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *boolop = nullptr;;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *NextOp();
    antlr4::tree::TerminalNode *LCPAREN();
    antlr4::tree::TerminalNode *CONSTANT();
    antlr4::tree::TerminalNode *RCPAREN();
    antlr4::tree::TerminalNode *PastOp();
    antlr4::tree::TerminalNode *NOT();
    std::vector<Numeric_logicContext *> numeric_logic();
    Numeric_logicContext* numeric_logic(size_t i);
    RelopContext *relop();
    AtomContext *atom();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NEQ();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  Numeric_logicContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *artop = nullptr;;
    Numeric_logicContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<Numeric_logicContext *> numeric_logic();
    Numeric_logicContext* numeric_logic(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *NextOp();
    antlr4::tree::TerminalNode *LCPAREN();
    antlr4::tree::TerminalNode *CONSTANT();
    antlr4::tree::TerminalNode *RCPAREN();
    antlr4::tree::TerminalNode *PastOp();
    AtomContext *atom();
    LogicContext *logic();
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Numeric_logicContext* numeric_logic();
  Numeric_logicContext* numeric_logic(int precedence);
  class  LogicContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *logop = nullptr;;
    LogicContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LogicContext *> logic();
    LogicContext* logic(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    AtomContext *atom();
    antlr4::tree::TerminalNode *NEG();
    antlr4::tree::TerminalNode *BAND();
    antlr4::tree::TerminalNode *BOR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LogicContext* logic();
  LogicContext* logic(int precedence);
  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstantContext *constant();
    VariableContext *variable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AtomContext* atom();

  class  ConstantContext : public antlr4::ParserRuleContext {
  public:
    ConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONSTANT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConstantContext* constant();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VARIABLE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableContext* variable();

  class  RelopContext : public antlr4::ParserRuleContext {
  public:
    RelopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *GE();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *LE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RelopContext* relop();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);
  bool numeric_logicSempred(Numeric_logicContext *_localctx, size_t predicateIndex);
  bool logicSempred(LogicContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

