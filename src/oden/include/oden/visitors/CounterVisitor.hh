#pragma once
#include "oden/OdenVisitor.hh"

#include <sstream>
#include <string>

namespace oden {

/// @brief This class generates a string given a Proposition or an Expression
class CounterVisitor : public OdenVisitor {
  public:
    /// @brief Constructor.
    CounterVisitor();

    /// @brief Destructor.
    ~CounterVisitor() override = default;

    /// @brief Clean up the internal string buffer.
    void clear();

    /// @return A integer for number of leterals.
    int get();

    ///@return next offset consequent
    int get_next();

    // proposition
    void visit(BooleanConstant &o) override;
    void visit(BooleanVariable &o) override;
    void visit(PropositionAnd &o) override;
    void visit(PropositionOr &o) override;
    void visit(PropositionXor &o) override;
    void visit(PropositionEq &o) override;
    void visit(PropositionNeq &o) override;
    void visit(PropositionNot &o) override;
    void visit(PropositionNext &o) override;
    void visit(PropositionPast &o) override;
    void visit(UntilOperator &o) override;
    void visit(ReleaseOperator &o) override;
    void visit(LogicToBool &o) override;

    // numeric
    void visit(NumericConstant &o) override;
    void visit(NumericVariable &o) override;
    void visit(NumericSum &o) override;
    void visit(NumericSub &o) override;
    void visit(NumericMul &o) override;
    void visit(NumericDiv &o) override;
    void visit(NumericNext &o) override;
    void visit(NumericPast &o) override;
    void visit(NumericEq &o) override;
    void visit(NumericNeq &o) override;
    void visit(NumericGreater &o) override;
    void visit(NumericGreaterEq &o) override;
    void visit(NumericLess &o) override;
    void visit(NumericLessEq &o) override;

    // logic
    void visit(LogicConstant &o) override;
    void visit(LogicVariable &o) override;
    void visit(LogicSum &o) override;
    void visit(LogicSub &o) override;
    void visit(LogicMul &o) override;
    void visit(LogicDiv &o) override;
    void visit(LogicBAnd &o) override;
    void visit(LogicBOr &o) override;
    void visit(LogicBXor &o) override;
    void visit(LogicNot &o) override;
    void visit(LogicNext &o) override;
    void visit(LogicPast &o) override;
    void visit(LogicEq &o) override;
    void visit(LogicNeq &o) override;
    void visit(LogicGreater &o) override;
    void visit(LogicGreaterEq &o) override;
    void visit(LogicLess &o) override;
    void visit(LogicLessEq &o) override;
    void visit(LogicBitSelector &o) override;
    void visit(NumericToLogic &o) override;

  protected:
    int counter;
    int c_next_counter;
};

} // namespace oden