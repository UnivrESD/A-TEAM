#include "PSLPropositionPrinter.hh"

namespace pslPrinter {

PSLPropositionPrinter::PSLPropositionPrinter() : oden::PrinterVisitor() {
    operators[ope::PropositionAnd] = std::string("&&");
    operators[ope::PropositionOr]  = std::string("||");
    operators[ope::PropositionEq]  = std::string("==");
    operators[ope::NumericEq]      = std::string("==");
    operators[ope::LogicEq]        = std::string("==");
}

void PSLPropositionPrinter::visit(oden::PropositionNext &o) {
    _ss << "next[" << o.getOffset() << "](";
    o.getItem().acceptVisitor(*this);
    _ss << ")";
}

void PSLPropositionPrinter::visit(oden::NumericNext &o) {
    _ss << "next[" << o.getOffset() << "](";
    o.getItem().acceptVisitor(*this);
    _ss << ")";
}

void PSLPropositionPrinter::visit(oden::LogicNext &o) {
    _ss << "next[" << o.getOffset() << "](";
    o.getItem().acceptVisitor(*this);
    _ss << ")";
}

} // namespace pslPrinter
