#include "FaultChecker.hh"
#include "oden/Checker.hh"
#include "oden/modules/default/MangroveTraceReader.hh"

namespace ateam {

namespace /**/ {

inline void assign_INL(unsigned int *_array, size_t time, bool value) {
    if (value)
        _array[time >> 5] |= 1 << (time & 31);
    else
        _array[time >> 5] &= ~(1 << (time & 31));
}

inline bool evaluate_INL(const unsigned int *_array, size_t time) {
    size_t tPos          = time >> 5;
    unsigned int _buffer = _array[tPos];

    return (_buffer & (1 << (time & 31))) != 0;
}

} // namespace

FaultChecker::FaultChecker(XmlNode *xmlNode)
    : _faultyTraces(nullptr), _covTraces(0), _coverageMap(nullptr) {
    auto tReader  = new modules::MangroveTraceReader(xmlNode);
    _faultyTraces = tReader->readTraces();
    delete tReader;

    int logNumTraces = (_faultyTraces->size() + 31) >> 5;
    _coverageMap     = new unsigned[logNumTraces];

    for (int i = 0; i < logNumTraces; ++i)
        _coverageMap[i] = 0;
}

FaultChecker::~FaultChecker() {
    delete _faultyTraces;
    delete[] _coverageMap;
}

double FaultChecker::getCoverage() {
    size_t traces = _faultyTraces->size();
    return static_cast<double>(_covTraces) / static_cast<double>(traces);
}

void FaultChecker::check(Assertion &assertion) {
    Checker checker;
    for (size_t traceId = 0; traceId < _faultyTraces->size(); ++traceId) {
        Trace &trace = (*_faultyTraces)[traceId];
        if (!(checker.evaluate(assertion, trace))) {
            assertion.faultList.push_back(traceId);
            if (!evaluate_INL(_coverageMap, traceId))
                ++_covTraces;
            assign_INL(_coverageMap, traceId, true);
        }
    }
}

}