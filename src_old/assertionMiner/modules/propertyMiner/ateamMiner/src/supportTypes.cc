#include "supportTypes.hh"

namespace ateam {

TraceInfo::TraceInfo() 
    : length(1), goal(nullptr), coverageTrue(nullptr), coverageFalse(nullptr),
      initTrue(0), reachedTrue(0), reachedFalse(0) {
      
        goal = new BooleanVariable(new unsigned int[1], "goal", 1);
        coverageTrue =
            new BooleanVariable(new unsigned int[1], "coverageTrue", 1);
        coverageFalse =
            new BooleanVariable(new unsigned int[1], "coverageFalse", 1);
      
      }

TraceInfo::TraceInfo(const TraceInfo &other)
    : length(other.length), goal(other.goal), coverageTrue(other.coverageTrue),
      coverageFalse(other.coverageFalse), initTrue(other.initTrue),
      reachedTrue(other.reachedTrue), reachedFalse(other.reachedFalse) {

    // ntd
}

void TraceInfo::initTraceInfo(size_t l) {
    if (l > length) {
        goal->deleteArray();
        coverageTrue->deleteArray();
        coverageFalse->deleteArray();
        delete goal;
        delete coverageTrue;
        delete coverageFalse;


        goal = new BooleanVariable(new unsigned int[((l + 31) >> 5)], "goal", l);
        coverageTrue =
            new BooleanVariable(new unsigned int[((l + 31) >> 5)], "coverageTrue", l);
        coverageFalse =
            new BooleanVariable(new unsigned int[((l + 31) >> 5)], "coverageFalse", l);
    }
    length = l;
    initTrue=0;
    reachedTrue=0;
    reachedFalse=0;
}
TraceInfo::~TraceInfo() {
    // memory leak here. Array in BooleanVariables is not deleted.
        goal->deleteArray();
        coverageTrue->deleteArray();
        coverageFalse->deleteArray();
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
