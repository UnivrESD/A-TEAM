#pragma once

#include "oden/classes/TraceRepository.hh"
#include "oden/odenEnums.hh"
#include "propositionBaseListener.h"

#include <stack>
#include <string>

using namespace antlr4;

namespace oden {

class PropositionParser : public propositionBaseListener {

public:
  explicit PropositionParser(const Name2Variable &name2Variable, Trace &trace);

  ~PropositionParser() override = default;

  Proposition *getProposition();

private:
  const Name2Variable &_varName2varDec;
  const Trace &_trace;
  bool _abort;
  bool createExpression = false;

  DataType _type;

  std::stack<Proposition *> _proposition;
  std::stack<LogicExpression *> _logicExpressions;
  std::stack<NumericExpression *> _numericExpressions;
  size_t boolStack = 0;
  size_t logicStack = 0;
  size_t numeriStack = 0;

  std::stack<std::string> constants;

  void enterFile(propositionParser::FileContext *ctx) override;
  void exitBoolean(propositionParser::BooleanContext *ctx) override;
  virtual void exitLogic(propositionParser::LogicContext *ctx) override;
  virtual void exitNumeric(propositionParser::NumericContext * ctx) override;
  void enterBooleanVariable(propositionParser::BooleanVariableContext *ctx) override;
  virtual void enterLogicVariable(propositionParser::LogicVariableContext * ctx) override;
  virtual void enterNumericVariable(propositionParser::NumericVariableContext * ctx) override;
  virtual void enterBooleanConstant(propositionParser::BooleanConstantContext * ctx) override;
  virtual void enterLogicConstant(propositionParser::LogicConstantContext * ctx) override;
  virtual void enterNumericConstant(propositionParser::NumericConstantContext * ctx) override;
  /*
  void enterVariable(propositionParser::VariableContext *ctx) override;
  void enterConstant(propositionParser::ConstantContext *ctx) override;
  void
  exitNumeric_logic(propositionParser::Numeric_logicContext *ctx) override;
  void exitExpression(propositionParser::ExpressionContext *ctx) override;
  void exitLogic(propositionParser::LogicContext *ctx) override;
  */
  void exitFile(propositionParser::FileContext *ctx) override;
  void handleNumericExpression(propositionParser::RelopContext *relop);
  void handleBooleanExpression(antlr4::Token *boolop);
  void makeLogicFromLogic(antlr4::Token *art_log_op);
  void makeBoolFromNumericLogic(propositionParser::RelopContext *relop);
  void makeNumericLogicFromNumericLogic(antlr4::Token *art_log_op);

  /*
  void exitHandleNot( propositionParser::HandleNotContext *ctx) override;
  void exitHandleNeg( propositionParser::HandleNegContext *ctx) override;
  */
  /*

  void exitProposition(propositionParser::PropositionContext *ctx) override;



  void exitLogicExpression(
      propositionParser::LogicExpressionContext *ctx) override;

  void exitBooleanExpression(
      propositionParser::BooleanExpressionContext *ctx) override;

  void exitNumericExpression(
      propositionParser::NumericExpressionContext *ctx) override;

  void exitAtomicProp(propositionParser::AtomicPropContext *ctx) override;

  void visitErrorNode(tree::ErrorNode *node) override;
  void handleNumericExpression( propositionParser::RelopContext *relop);
  void handleNumericExpression( propositionParser::ArtopContext *artop);
  void handleBooleanExpression( propositionParser::BoolopContext *boolop);
  void handleLogicExpression( propositionParser::LogopContext *logop);
  void handleNumericExpression( propositionParser::LrelopContext *lrelop);
  */
};

} // namespace oden
