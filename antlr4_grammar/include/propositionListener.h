
// Generated from ../assertionminer/antlr4_grammar/proposition.gr by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "propositionParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by propositionParser.
 */
class  propositionListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(propositionParser::FileContext *ctx) = 0;
  virtual void exitFile(propositionParser::FileContext *ctx) = 0;

  virtual void enterProposition(propositionParser::PropositionContext *ctx) = 0;
  virtual void exitProposition(propositionParser::PropositionContext *ctx) = 0;

  virtual void enterAtomicProp(propositionParser::AtomicPropContext *ctx) = 0;
  virtual void exitAtomicProp(propositionParser::AtomicPropContext *ctx) = 0;

  virtual void enterNumericExpression(propositionParser::NumericExpressionContext *ctx) = 0;
  virtual void exitNumericExpression(propositionParser::NumericExpressionContext *ctx) = 0;

  virtual void enterBooleanExpression(propositionParser::BooleanExpressionContext *ctx) = 0;
  virtual void exitBooleanExpression(propositionParser::BooleanExpressionContext *ctx) = 0;

  virtual void enterHandleNot(propositionParser::HandleNotContext *ctx) = 0;
  virtual void exitHandleNot(propositionParser::HandleNotContext *ctx) = 0;

  virtual void enterHandleNeg(propositionParser::HandleNegContext *ctx) = 0;
  virtual void exitHandleNeg(propositionParser::HandleNegContext *ctx) = 0;

  virtual void enterLogicExpression(propositionParser::LogicExpressionContext *ctx) = 0;
  virtual void exitLogicExpression(propositionParser::LogicExpressionContext *ctx) = 0;

  virtual void enterAtom(propositionParser::AtomContext *ctx) = 0;
  virtual void exitAtom(propositionParser::AtomContext *ctx) = 0;

  virtual void enterConstant(propositionParser::ConstantContext *ctx) = 0;
  virtual void exitConstant(propositionParser::ConstantContext *ctx) = 0;

  virtual void enterVariable(propositionParser::VariableContext *ctx) = 0;
  virtual void exitVariable(propositionParser::VariableContext *ctx) = 0;

  virtual void enterArtop(propositionParser::ArtopContext *ctx) = 0;
  virtual void exitArtop(propositionParser::ArtopContext *ctx) = 0;

  virtual void enterLrelop(propositionParser::LrelopContext *ctx) = 0;
  virtual void exitLrelop(propositionParser::LrelopContext *ctx) = 0;

  virtual void enterRelop(propositionParser::RelopContext *ctx) = 0;
  virtual void exitRelop(propositionParser::RelopContext *ctx) = 0;

  virtual void enterLogop(propositionParser::LogopContext *ctx) = 0;
  virtual void exitLogop(propositionParser::LogopContext *ctx) = 0;

  virtual void enterBoolop(propositionParser::BoolopContext *ctx) = 0;
  virtual void exitBoolop(propositionParser::BoolopContext *ctx) = 0;


};

