#include "oden/classes/Trace.hh"
#include "oden/classes/atom/Variable.hh"
#include "oden/odenUtils/applicationUtils.hh"

namespace oden {

Trace::Trace(List<DataType> &variables, size_t length)
    : _numeriTrace(nullptr), _booleanTrace(nullptr), _logicTrace(nullptr),
      _length(length), _logicName2size(), _varName2varValues() {

    for (DataType *dt : variables)
        if (dt->getType() == VariableType::logic)
            _logicName2size[dt->getName()] = dt->getSize();

    _allocateTrace(variables);
    _allocatePointers(variables);
}

Trace::~Trace() {
    delete[] _numeriTrace;
    delete[] _booleanTrace;
    delete[] _logicTrace;
}

size_t Trace::getLength() const { return _length; }

void Trace::_allocateTrace(List<DataType> &variables) {
    size_t numVarCounter = 0;
    size_t bolVarCounter = 0;
    size_t logVarCounter = 0;

    for (DataType *var : variables) {
        switch (var->getType()) {
        case VariableType::numeric: {
            ++numVarCounter;
            break;
        }
        case VariableType::boolean: {
            ++bolVarCounter;
            break;
        }
        case VariableType::logic: {
            // number of values in a Logic
            size_t val4Logic = _bits4Logic / var->getSize();
            // number of 64 bits integers to represent all the values of this
            // variable
            size_t tmpSize = (_length + val4Logic - 1) / val4Logic;

            logVarCounter += tmpSize;
            break;
        }
        case VariableType::unknown: {
        }
        default: {
        }
        }
    }

    _numeriTrace  = new Numeric[_length * numVarCounter]{};
    _booleanTrace = new unsigned[((_length + 31) >> 5) * bolVarCounter]{};
    _logicTrace   = new uint64_t[logVarCounter]{};

}

void Trace::_allocatePointers(List<DataType> &variables) {
    size_t numVarCounter = 0;
    size_t bolVarCounter = 0;
    size_t logVarAccu    = 0;

    for (DataType *var : variables) {
        switch (var->getType()) {
        case VariableType::numeric: {
            _varName2varValues[var->getName()] = reinterpret_cast<uintptr_t>(
                &_numeriTrace[_length * numVarCounter]);
            ++numVarCounter;
            break;
        }
        case VariableType::boolean: {
            _varName2varValues[var->getName()] = reinterpret_cast<uintptr_t>(
                &_booleanTrace[((_length + 31) >> 5) * bolVarCounter]);
            ++bolVarCounter;
            break;
        }
        case VariableType::logic: {
            _varName2varValues[var->getName()] =
                reinterpret_cast<uintptr_t>(&_logicTrace[logVarAccu]);

            // number of values in a Logic
            size_t val4Logic = _bits4Logic / var->getSize();
            // number of Logics to represent all the values of this variable
            size_t tmpSize = (_length + val4Logic - 1) / val4Logic;
            logVarAccu += tmpSize;

            break;
        }
        case VariableType::unknown: {
        }
        default: {
        }
        }
    }
}

BooleanVariable *Trace::getBooleanVariable(const std::string &name) const {
    auto found = _varName2varValues.find(name);
    if (found == _varName2varValues.end()){
        messageError("Can't find boolean variable with name: " + name);
    }

    return new BooleanVariable(reinterpret_cast<unsigned int *>(found->second),
                               name, _length);
}

LogicVariable *Trace::getLogicVariable(const std::string &name) const {
    auto found = _varName2varValues.find(name);
    if (found == _varName2varValues.end()){
        messageError("Can't find logic variable with name: " + name);
    }

    uint8_t size = _logicName2size.at(name);
    return new LogicVariable(reinterpret_cast<uint64_t *>(found->second), size,
                             name, _length);
}

NumericVariable *Trace::getNumericVariable(const std::string &name) const {
    auto found = _varName2varValues.find(name);

    if (found == _varName2varValues.end()){
        messageError("Can't find numeric variable with name: " + name);
    }

    return new NumericVariable(reinterpret_cast<Numeric *>(found->second), name,
                               _length);
}

} // namespace oden
