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
    explicit PropositionParser(const Name2Variable &name2Variable,
                               Trace &trace);

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

    std::stack<std::string> constants;

    void enterFile(propositionParser::FileContext *ctx) override;

    void exitProposition(propositionParser::PropositionContext *ctx) override;

    void enterConstant(propositionParser::ConstantContext *ctx) override;

    void enterVariable(propositionParser::VariableContext *ctx) override;

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
    void exitHandleNot( propositionParser::HandleNotContext *ctx);
    void exitHandleNeg( propositionParser::HandleNegContext *ctx);

};

} // namespace oden
