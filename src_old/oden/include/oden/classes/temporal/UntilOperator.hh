#pragma once

#include "oden/classes/atom/Atom.hh"
#include "oden/classes/expression/Expression.hh"

namespace oden {

/// @brief UntilOperator declaration.
/// This class represents the temporal logic operator Until
class UntilOperator : public Proposition {

  public:
    /// @brief T he constructor defines the new temporal proposition (p1 U p2)
    /// given the propositions p1 and p2.
    /// @param p1 The proposition p1
    /// @param p2 The proposition p2
    UntilOperator(Proposition *p1, Proposition *p2);

    /// @brief Copy constructor.
    UntilOperator(const UntilOperator &other) = delete;

    /// @brief Destructor.
    ~UntilOperator() override;

    /// @brief Evaluate the proposition in a given simulation time.
    /// @param time The simulation time
    /// @return The value of the proposition
    bool evaluate(size_t time) override;

    /// @brief Accepts a visitor to visit the current object.
    /// @param vis The visitor.
    void acceptVisitor(OdenVisitor &vis) override;

    /// @brief Return the sub-expressions of the Until operator
    /// @return A reference to the expression.
    Proposition &getItem1();

    Proposition &getItem2();

    /// @brief Assing operator
    UntilOperator &operator=(const UntilOperator &other) = delete;

    // declare friend class to allow it access private variables
    friend class PeTraceChanger;

  private:
    // The p1 proposition
    Proposition *_p1;
    // The p2 proposition
    Proposition *_p2;
    // ...
    bool _inCache;
    // the proposition is evaluated on the whole trace
    unsigned int *_cachedValues;
};

} // namespace oden