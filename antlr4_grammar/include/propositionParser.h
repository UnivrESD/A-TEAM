
// Generated from ../assertionminer/antlr4_grammar/proposition.gr by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  propositionParser : public antlr4::Parser {
public:
  enum {
    NextOp = 1, LCPAREN = 2, RCPAREN = 3, LPAREN = 4, RPAREN = 5, VARIABLE = 6, 
    CONSTANT = 7, PLUS = 8, MINUS = 9, TIMES = 10, DIV = 11, GT_ = 12, GE_ = 13, 
    LT_ = 14, LE_ = 15, EQ_ = 16, NEQ_ = 17, GT = 18, GE = 19, LT = 20, 
    LE = 21, EQ = 22, NEQ = 23, BAND = 24, BOR = 25, BXOR = 26, NEG = 27, 
    PLUS_ = 28, MINUS_ = 29, TIMES_ = 30, DIV_ = 31, AND = 32, OR = 33, 
    NOT = 34, WS = 35
  };

  enum {
    RuleFile = 0, RuleProposition = 1, RuleAtomicProp = 2, RuleNumericExpression = 3, 
    RuleBooleanExpression = 4, RuleHandleNot = 5, RuleHandleNeg = 6, RuleLogicExpression = 7, 
    RuleAtom = 8, RuleConstant = 9, RuleVariable = 10, RuleArtop = 11, RuleLrelop = 12, 
    RuleRelop = 13, RuleLogop = 14, RuleBoolop = 15
  };

  propositionParser(antlr4::TokenStream *input);
  ~propositionParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FileContext;
  class PropositionContext;
  class AtomicPropContext;
  class NumericExpressionContext;
  class BooleanExpressionContext;
  class HandleNotContext;
  class HandleNegContext;
  class LogicExpressionContext;
  class AtomContext;
  class ConstantContext;
  class VariableContext;
  class ArtopContext;
  class LrelopContext;
  class RelopContext;
  class LogopContext;
  class BoolopContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PropositionContext *proposition();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FileContext* file();

  class  PropositionContext : public antlr4::ParserRuleContext {
  public:
    PropositionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomicPropContext *atomicProp();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PropositionContext* proposition();

  class  AtomicPropContext : public antlr4::ParserRuleContext {
  public:
    AtomicPropContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumericExpressionContext *numericExpression();
    BooleanExpressionContext *booleanExpression();
    LogicExpressionContext *logicExpression();
    antlr4::tree::TerminalNode *LPAREN();
    AtomicPropContext *atomicProp();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AtomicPropContext* atomicProp();

  class  NumericExpressionContext : public antlr4::ParserRuleContext {
  public:
    NumericExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<NumericExpressionContext *> numericExpression();
    NumericExpressionContext* numericExpression(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    AtomContext *atom();
    ArtopContext *artop();
    RelopContext *relop();
    BoolopContext *boolop();
    BooleanExpressionContext *booleanExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NumericExpressionContext* numericExpression();
  NumericExpressionContext* numericExpression(int precedence);
  class  BooleanExpressionContext : public antlr4::ParserRuleContext {
  public:
    BooleanExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NOT();
    antlr4::tree::TerminalNode* NOT(size_t i);
    std::vector<HandleNotContext *> handleNot();
    HandleNotContext* handleNot(size_t i);
    BoolopContext *boolop();
    std::vector<BooleanExpressionContext *> booleanExpression();
    BooleanExpressionContext* booleanExpression(size_t i);
    std::vector<NumericExpressionContext *> numericExpression();
    NumericExpressionContext* numericExpression(size_t i);
    RelopContext *relop();
    std::vector<LogicExpressionContext *> logicExpression();
    LogicExpressionContext* logicExpression(size_t i);
    LrelopContext *lrelop();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    AtomContext *atom();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BooleanExpressionContext* booleanExpression();
  BooleanExpressionContext* booleanExpression(int precedence);
  class  HandleNotContext : public antlr4::ParserRuleContext {
  public:
    HandleNotContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BooleanExpressionContext *booleanExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  HandleNotContext* handleNot();

  class  HandleNegContext : public antlr4::ParserRuleContext {
  public:
    HandleNegContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LogicExpressionContext *logicExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  HandleNegContext* handleNeg();

  class  LogicExpressionContext : public antlr4::ParserRuleContext {
  public:
    LogicExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NEG();
    antlr4::tree::TerminalNode* NEG(size_t i);
    std::vector<HandleNegContext *> handleNeg();
    HandleNegContext* handleNeg(size_t i);
    LogopContext *logop();
    std::vector<LogicExpressionContext *> logicExpression();
    LogicExpressionContext* logicExpression(size_t i);
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    AtomContext *atom();
    LrelopContext *lrelop();
    BoolopContext *boolop();
    BooleanExpressionContext *booleanExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LogicExpressionContext* logicExpression();
  LogicExpressionContext* logicExpression(int precedence);
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
    antlr4::tree::TerminalNode *NextOp();
    antlr4::tree::TerminalNode *LCPAREN();
    antlr4::tree::TerminalNode *CONSTANT();
    antlr4::tree::TerminalNode *RCPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableContext* variable();

  class  ArtopContext : public antlr4::ParserRuleContext {
  public:
    ArtopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArtopContext* artop();

  class  LrelopContext : public antlr4::ParserRuleContext {
  public:
    LrelopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQ_();
    antlr4::tree::TerminalNode *NEQ_();
    antlr4::tree::TerminalNode *GT_();
    antlr4::tree::TerminalNode *GE_();
    antlr4::tree::TerminalNode *LT_();
    antlr4::tree::TerminalNode *LE_();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LrelopContext* lrelop();

  class  RelopContext : public antlr4::ParserRuleContext {
  public:
    RelopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NEQ();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *GE();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *LE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RelopContext* relop();

  class  LogopContext : public antlr4::ParserRuleContext {
  public:
    LogopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BAND();
    antlr4::tree::TerminalNode *BOR();
    antlr4::tree::TerminalNode *BXOR();
    antlr4::tree::TerminalNode *TIMES_();
    antlr4::tree::TerminalNode *DIV_();
    antlr4::tree::TerminalNode *PLUS_();
    antlr4::tree::TerminalNode *MINUS_();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LogopContext* logop();

  class  BoolopContext : public antlr4::ParserRuleContext {
  public:
    BoolopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BoolopContext* boolop();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool numericExpressionSempred(NumericExpressionContext *_localctx, size_t predicateIndex);
  bool booleanExpressionSempred(BooleanExpressionContext *_localctx, size_t predicateIndex);
  bool logicExpressionSempred(LogicExpressionContext *_localctx, size_t predicateIndex);

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

