#include "oden/odenUtils/templateUtils.hh"

#include <spot/tl/parse.hh>
#include <spot/tl/print.hh>
#include <sstream>

namespace oden {

std::string template2String(Template templ) {
    std::stringstream ss;
    spot::print_psl(ss, templ);
    return ss.str();
}

Template string2Template(const std::string &str) {
    return spot::parse_formula(str);
}

bool isAtomicProposition(oden::Template templ) {
    return templ.is(spot::op::ap);
}

oden::Template removeNext(oden::Template templ) {
    while (templ.is(spot::op::X))
        templ = templ[0];

    return templ;
}

size_t countNext(oden::Template templ) {
    size_t counter = 0;
    while (templ.is(spot::op::X)) {
        ++counter;
        templ = templ[0];
    }

    return counter;
}

} // namespace oden
