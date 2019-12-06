
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

  virtual void enterExpression(propositionParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(propositionParser::ExpressionContext *ctx) = 0;

  virtual void enterNumeric_logic(propositionParser::Numeric_logicContext *ctx) = 0;
  virtual void exitNumeric_logic(propositionParser::Numeric_logicContext *ctx) = 0;

  virtual void enterLogic(propositionParser::LogicContext *ctx) = 0;
  virtual void exitLogic(propositionParser::LogicContext *ctx) = 0;

  virtual void enterAtom(propositionParser::AtomContext *ctx) = 0;
  virtual void exitAtom(propositionParser::AtomContext *ctx) = 0;

  virtual void enterConstant(propositionParser::ConstantContext *ctx) = 0;
  virtual void exitConstant(propositionParser::ConstantContext *ctx) = 0;

  virtual void enterVariable(propositionParser::VariableContext *ctx) = 0;
  virtual void exitVariable(propositionParser::VariableContext *ctx) = 0;

  virtual void enterRelop(propositionParser::RelopContext *ctx) = 0;
  virtual void exitRelop(propositionParser::RelopContext *ctx) = 0;


};

