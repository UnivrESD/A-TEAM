#pragma once

#include "oden/classes/atom/Atom.hh"

namespace oden {

/// @brief NextOperator declaration.
/// This class represents the temporal operator Next
template <typename ET> class NextOperator : public ET {

    using ReturnType = typename std::conditional<
        std::is_same<ET, NumericExpression>::value, Numeric,
        typename std::conditional<std::is_same<ET, LogicExpression>::value,
                                  Logic, bool>::type>::type;

  public:
    /// @brief Given an expression e, and a temporal offset t, the constructor
    /// defines the new expression X[offset](p)
    /// @param e An expression
    /// @param offset A temporal offset
    NextOperator(ET *e, size_t offset);

    /// @brief Copy constructor.
    NextOperator(const NextOperator &other) = delete;

    /// @brief Destructor.
    virtual ~NextOperator();

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
    NextOperator &operator=(const NextOperator &other) = delete;

    /// @brief Return the temporal offset of the Next operator
    /// @return temporal offset
    size_t getOffset();

  private:
    // The evaluated expression at time t + offset
    ET *_e;
    // The temporal offset
    size_t _offset;
};

using NumericNext     = NextOperator<NumericExpression>;
using LogicNext       = NextOperator<LogicExpression>;
using PropositionNext = NextOperator<Proposition>;

} // namespace oden

#include "NextOperator.i.hh"