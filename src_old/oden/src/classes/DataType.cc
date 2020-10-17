#include "oden/classes/DataType.hh"

namespace oden {

DataType::DataType()
    : _name(""), _type(VariableType::unknown), _size(1),
      _direction(VariableDirection::dir_inout) {
    // ntd
}

void DataType::setName(const std::string &name) { _name = name; }

std::string DataType::getName() const { return _name; }

void DataType::setType(VariableType type, uint8_t size) {
    _type = type;
    _size = size;
}

VariableType DataType::getType() const { return _type; }

uint8_t DataType::getSize() const { return _size; }

void DataType::setDirection(VariableDirection dir) { _direction = dir; }

VariableDirection DataType::getDirection() const { return _direction; }

} // namespace oden
