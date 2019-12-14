#pragma once

#include "oden/classes/atom/Atom.hh"
#include "oden/classes/atom/Constant.hh"
#include "oden/odenUtils/applicationUtils.hh"

namespace oden {

/// @brief BitSelector declaration.
/// This class represents the bit selector operator
template <typename ET,typename RT> class BitSelector : public RT {


  public:
    BitSelector(ET *e, size_t upper_bound, size_t lower_bound);

    using ReturnType = typename std::conditional<std::is_same<RT, LogicExpression>::value, Logic, bool>::type;
    /// @brief Copy constructor.
    BitSelector(const BitSelector &other) = delete;

    /// @brief Destructor.
    virtual ~BitSelector();

    /// @brief Evaluate the expression in a given simulation time.
    /// @param time The simulation time
    /// @return The value of the expression
    ReturnType evaluate(size_t time) override;

    /// @brief Accepts a visitor to visit the current object.
    /// @param vis The visitor.
    void acceptVisitor(OdenVisitor &vis) override;

    /// @brief Return the expression of the next operator
    /// @return A reference to the expression.
    ET &getItem();

    /// @brief Assing operator
    BitSelector &operator=(const BitSelector &other) = delete;

    size_t getLowerBound();
    size_t getUpperBound();

  private:
    // The evaluated expression at time t + offset
    ET *_e;
    // The temporal offset
    size_t _upper_bound;
    size_t _lower_bound;
};
using LogicBitSelector = BitSelector<LogicExpression,LogicExpression>;
using PropositionBitSelector = BitSelector<LogicExpression,Proposition>;

} // namespace oden

#include "BitSelector.i.hh"
