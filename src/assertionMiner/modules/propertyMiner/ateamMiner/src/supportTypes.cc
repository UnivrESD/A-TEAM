#include "supportTypes.hh"

namespace ateam {

TraceInfo::TraceInfo(size_t l)
    : length(l), goal(nullptr), coverageTrue(nullptr), coverageFalse(nullptr),
      initTrue(0), reachedTrue(0), reachedFalse(0) {

    size_t length32 = length >> 5;

    goal = new BooleanVariable(new unsigned int[length32], "goal", l);
    coverageTrue =
        new BooleanVariable(new unsigned int[length32], "coverageTrue", l);
    coverageFalse =
        new BooleanVariable(new unsigned int[length32], "coverageFalse", l);
}

TraceInfo::TraceInfo(const TraceInfo &other)
    : length(other.length), goal(other.goal), coverageTrue(other.coverageTrue),
      coverageFalse(other.coverageFalse), initTrue(other.initTrue),
      reachedTrue(other.reachedTrue), reachedFalse(other.reachedFalse) {
    // ntd
}

TraceInfo::~TraceInfo() {
    // memory leak here. Array in BooleanVariables is not deleted.
    delete goal;
    delete coverageTrue;
    delete coverageFalse;
}

TraceInfo &TraceInfo::operator=(const TraceInfo &other) {
    length        = other.length;
    goal          = other.goal;
    coverageTrue  = other.coverageTrue;
    coverageFalse = other.coverageFalse;
    initTrue      = other.initTrue;
    reachedTrue   = other.reachedTrue;
    reachedFalse  = other.reachedFalse;

    return *this;
}

void TraceInfo::setGoal(size_t time, bool value) {
    goal->assign(time, value);
    coverageTrue->assign(time, value);
    coverageFalse->assign(time, !value);

    if (value)
        ++initTrue;
}

} // namespace ateam
