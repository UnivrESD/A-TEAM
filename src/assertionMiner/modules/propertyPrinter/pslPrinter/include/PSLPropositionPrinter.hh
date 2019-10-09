#pragma once
#include "oden/visitors/PrinterVisitor.hh"

namespace pslPrinter {

/// @brief This class prints a proposition in PSL format
class PSLPropositionPrinter : public oden::PrinterVisitor {
  public:
    PSLPropositionPrinter();
    ~PSLPropositionPrinter() override = default;

    void visit(oden::PropositionNext &o) override;
    void visit(oden::NumericNext &o) override;
    void visit(oden::LogicNext &o) override;
};
} // namespace pslPrinter
