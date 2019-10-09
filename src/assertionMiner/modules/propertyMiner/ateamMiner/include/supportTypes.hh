#pragma once

#include "oden/List.hh"
#include "oden/classes/atom/Atom.hh"
#include "oden/classes/atom/Variable.hh"
#include "oden/types.hh"

#include <list>
#include <map>

using namespace std;
using namespace oden;

namespace ateam {

struct TraceInfo {
    /// @brief Constructor.
    explicit TraceInfo(size_t l);

    /// @brief Destructor.
    ~TraceInfo();

    void setGoal(size_t time, bool value);

    size_t length;
    BooleanVariable *goal;
    BooleanVariable *coverageTrue;
    BooleanVariable *coverageFalse;

    size_t initTrue;
    size_t reachedTrue;
    size_t reachedFalse;

    TraceInfo &operator=(const TraceInfo &other);

    TraceInfo(const TraceInfo &other);
};

// (offset, (p, !p))  offset: delay due to NEXT operator. Examples:
// (0, (p, !p));
// (1, (X[1](p), X[1](!p)));
// (2, (X[2](p), X[2](!p)));
// ....
using DelayedProposition = pair<size_t, Proposition *[2]>;
// NEXT operator is managed by introducing DelayedProposition
using Prop2DProps = map<Proposition *, list<DelayedProposition>>;

// for the decision tree algorithm variables are numerated.
// Each variable is a proposition splitting the research space.
using DecTreeVariables = map<size_t, Proposition *[2]>;

} // namespace ateam
