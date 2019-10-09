#include "oden/types.hh"
#include "oden/visitors/CopyVisitor.hh"

namespace oden {

Assertion::Assertion() : id(0), templ(), t2p(), faultList() {
    // ntd
}

Assertion::Assertion(const Assertion &other)
    : id(other.id), templ(other.templ), t2p(), faultList(other.faultList) {
    oden::CopyVisitor copy;
    // deep copy of each oden proposition of Assertion other.
    for (auto &kv : other.t2p) {
        (kv.second)->acceptVisitor(copy);
        t2p[kv.first] = copy.get();
    }
}

Assertion::~Assertion() {
    // call the destructor of each proposition
    for (auto &kv : t2p)
        delete kv.second;
}

} // namespace oden
