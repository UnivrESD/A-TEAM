#include "oden/classes/TraceRepository.hh"
#include "oden/odenUtils/applicationUtils.hh"

namespace oden {

TraceRepository::TraceRepository(List<DataType> &variables)
    : _variables(), _varName2varDeclaration(), _repository() {

    for (DataType *var : variables) {
        if (var->getType() == VariableType::unknown)
            messageInfo("The variable " + var->getName() +
                        " was discarded because of its unknown type.");
        else {
            auto *dt = new DataType(*var);
            _variables.push_back(dt);
            _varName2varDeclaration[var->getName()] = dt;
        }
    }
}

const DataType &TraceRepository::getVariable(const std::string &name) {
    auto found = _varName2varDeclaration.find(name);
    messageErrorIf(found == _varName2varDeclaration.end(),
                   "Unknown variable name: " + name);

    return *(found->second);
}

const Name2Variable &TraceRepository::getVariables() {
    return _varName2varDeclaration;
}

Trace &TraceRepository::makeTrace(size_t length) {
    auto *trace = new Trace(_variables, length);
    _repository.push_back(trace);

    return *trace;
}

Trace &TraceRepository::operator[](size_t position) {
    return *_repository[position];
}

size_t TraceRepository::size() const { return _repository.size(); }

} // namespace oden
