#include "oden/classes/atom/Constant.hh"
#include "oden/OdenVisitor.hh"

namespace oden {

template <> bool Constant<bool>::evaluate(size_t) { return _value; }

template <> Numeric Constant<Numeric>::evaluate(size_t) { return _value; }

template <> Logic Constant<Logic>::evaluate(size_t) { return _value; }

template <> void Constant<bool>::acceptVisitor(OdenVisitor &vis) {
    vis.visit(*this);
}

template <> void Constant<Numeric>::acceptVisitor(OdenVisitor &vis) {
    vis.visit(*this);
}

template <> void Constant<Logic>::acceptVisitor(OdenVisitor &vis) {
    vis.visit(*this);
}

}