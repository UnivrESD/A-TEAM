
#include "oden/classes/temporal/UntilOperator.hh"
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

UntilOperator::UntilOperator(Proposition *p1, Proposition *p2)
    : Proposition(std::min(p1->getMaxTime(), p2->getMaxTime())), _p1(p1),
      _p2(p2), _inCache(false), _cachedValues(nullptr) {}

UntilOperator::~UntilOperator() {
    delete _p1;
    delete _p2;
    delete[] _cachedValues;
}

void UntilOperator::acceptVisitor(OdenVisitor &vis) { vis.visit(*this); }

Proposition &UntilOperator::getItem1() { return *_p1; }

Proposition &UntilOperator::getItem2() { return *_p2; }

bool UntilOperator::evaluate(size_t time) {

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

        // check where the temporal proposition p1 U p2 is true in the trace
        size_t start, stop = 0;
        while (stop < _max_time) {
            start = stop;

            // find where p1 is true
            while (!_p1->evaluate(start) && start < _max_time)
                ++start;

            // go ahead until p1 is true and p2 false
            stop = start;
            while (_p1->evaluate(stop) && !_p2->evaluate(stop) &&
                   stop < _max_time) {
                ++stop;
            }

            // check if p2 is true and p1 is false now
            if (_p2->evaluate(stop) && !_p1->evaluate(stop) && stop > start) {
                // check if we stop evaluating because end-of-trace
                if (stop < _max_time)
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
