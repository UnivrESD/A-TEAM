
#include "oden/classes/temporal/ReleaseOperator.hh"
#include "oden/OdenVisitor.hh"

namespace oden {

namespace /**/ {

inline void assign_INL(unsigned int *_array, size_t time, bool value) {
    if (value)
        _array[time >> 5] |= 1 << (time & 31);
    else
        _array[time >> 5] &= ~(1 << (time & 31));
}

inline bool evaluate_INL(unsigned int *_array, size_t time) {
    size_t tPos          = time >> 5;
    unsigned int _buffer = _array[tPos];

    return (_buffer & (1 << (time & 31))) != 0;
}

} // namespace

ReleaseOperator::ReleaseOperator(Proposition *p1, Proposition *p2)
    : Proposition(std::min(p1->getMaxTime(), p2->getMaxTime())), _p1(p1),
      _p2(p2), _inCache(false), _cachedValues(nullptr) {}

ReleaseOperator::~ReleaseOperator() {
    delete _p1;
    delete _p2;
    delete[] _cachedValues;
}

void ReleaseOperator::acceptVisitor(OdenVisitor &vis) { vis.visit(*this); }

Proposition &ReleaseOperator::getItem1() { return *_p1; }

Proposition &ReleaseOperator::getItem2() { return *_p2; }

bool ReleaseOperator::evaluate(size_t time) {

    if (!_inCache) {
        // inCache is false when:
        // we have not called the method evaluate yet;
        // the PeTraceChanger changed the simulation trace.
        delete[] _cachedValues;

        size_t length = (_max_time + 31) >> 5;
        _cachedValues = new unsigned int[length];

        // init. cachedValues to zero.
        for (size_t i = 0; i < length; ++i)
            _cachedValues[i] = 0;

        // check where the temporal proposition p1 R p2 is true in the trace
        size_t start, stop = 0;
        while (stop < _max_time) {
            start = stop;

            // find where p2 is true
            while (!_p2->evaluate(start) && start < _max_time)
                ++start;

            // go ahead until p2 is true and p1 false
            stop = start;
            while (_p2->evaluate(stop) && !_p1->evaluate(stop) &&
                   stop < _max_time) {
                ++stop;
            }

            // check if p2 and p1 are both true now
            if (_p2->evaluate(stop) && _p1->evaluate(stop) && stop > start) {
                // check if p2 is false at the next simulation time
                if ((stop + 1) < _max_time && !_p2->evaluate(stop + 1))
                    // for (; start <= stop; ++start)
                    assign_INL(_cachedValues, start, true);
            }

            ++stop;
        }
        _inCache = true;
    }

    return evaluate_INL(_cachedValues, time);
}

} // namespace oden
