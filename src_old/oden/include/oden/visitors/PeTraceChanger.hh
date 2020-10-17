#pragma once

#include "oden/OdenVisitor.hh"
#include "oden/classes/Trace.hh"

namespace oden {

/// @brief PeTraceChanger changes the pointers to value of every
/// variable in an expression.
class PeTraceChanger : public OdenVisitor {
  public:
    /// @brief Constructor.
    PeTraceChanger();

    PeTraceChanger(const PeTraceChanger &other) = delete;

    /// @brief Destructor.
    ~PeTraceChanger() override = default;

    /// @brief ....
    void setTrace(Trace *trace);

    // variables of an expression.
    void visit(BooleanVariable &o) override;
    void visit(NumericVariable &o) override;
    void visit(LogicVariable &o) override;
    void visit(UntilOperator &o) override;
    void visit(ReleaseOperator &o) override;

    PeTraceChanger &operator=(const PeTraceChanger &other) = delete;

  private:
    Trace *_trace;
};

} // namespace oden
