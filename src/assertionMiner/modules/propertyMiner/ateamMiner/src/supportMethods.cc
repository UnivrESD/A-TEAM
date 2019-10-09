#include "supportMethods.hh"
#include "oden/odenUtils/applicationUtils.hh"
#include "oden/odenUtils/templateUtils.hh"
#include <cmath>

namespace ateam {
namespace support {

Template getConsequent(Template templ) {
    Template gTemplate  = templ;
    Template imply      = gTemplate[0];
    Template consequent = imply[1];

    return consequent;
}

void getOffsetsFromChain(Template templ, std::vector<size_t> &offsets) {
    // if it is an atomic proposition, then the offset is zero
    if (templ.is(spot::op::ap)) {
        offsets.push_back(0);
        return;
    }

    for (unsigned int fIndex = 0; fIndex < templ.size(); ++fIndex) {
        Template templ_tmp = templ[fIndex];
        size_t counter     = countNext(templ_tmp);

        templ_tmp = removeNext(templ_tmp);
        messageErrorIf(!(templ_tmp.is(spot::op::ap)),
                       "Template's antecedent not supported: " + templ_tmp);

        offsets.push_back(counter);
    }
}

Template getAntecedent(Template templ) {
    Template gTemplate  = templ;
    Template imply      = gTemplate[0];
    Template antecedent = imply[0];

    return antecedent;
}

double getEntropy(size_t occurrences, size_t traceLength) {
    double goalTrue  = DIV(occurrences, traceLength);
    double goalFalse = 1 - goalTrue;

    return (-1) * goalTrue * log2(goalTrue) +
           (-1) * goalFalse * log2(goalFalse);
}

} // namespace support
} // namespace ateam
