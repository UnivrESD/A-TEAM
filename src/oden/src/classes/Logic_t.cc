#include "oden/classes/Logic_t.hh"
#include "oden/odenUtils/applicationUtils.hh"
#include <algorithm>
#include <bitset>
#include <sstream>

namespace oden {
using namespace applicationUtils;

Logic_t::Logic_t(uint64_t value, uint8_t s = 64) : _value(value), _size(s) {
    if (s > 64)
        messageError("Not supported size for Logic_t (MAX. 64)");
}

Logic_t::Logic_t(std::string value)
    : _value(0), _size(static_cast<uint8_t>(value.size())) {

    if (any_of(begin(value), end(value),
               [](char e) { return e != '0' && e != '1'; }))
        messageError("Trace value of Logic variable is not binary!");

    if (value.size() > 64)
        messageError("Not supported size for Logic_t (MAX. 64)");

    for (size_t i = 0; i < value.size(); ++i) {
        _value = _value << 1;
        if (value.at(i) == '1')
            _value = _value + 1;
    }
}

Logic_t Logic_t::operator~() {
    return (((~_value) << 64 - _size) >> (64 - _size));
}

Logic_t Logic_t::operator&(Logic_t other) {
    return Logic_t(other._value & _value,
                   _size > other._size ? _size : other._size);
}

Logic_t Logic_t::operator|(Logic_t other) {
    return Logic_t(other._value | _value,
                   _size > other._size ? _size : other._size);
}

Logic_t Logic_t::operator^(Logic_t other) {
    return Logic_t(other._value ^ _value,
                   _size > other._size ? _size : other._size);
}

Logic_t Logic_t::operator+(Logic_t other) {
    return Logic_t(other._value + _value,
                   _size > other._size ? _size : other._size);
}

Logic_t Logic_t::operator-(Logic_t other) {
    return Logic_t(other._value - _value,
                   _size > other._size ? _size : other._size);
}

Logic_t Logic_t::operator*(Logic_t other) {
    return Logic_t(other._value * _value,
                   _size > other._size ? _size : other._size);
}

Logic_t Logic_t::operator/(Logic_t other) {
    return Logic_t(other._value / _value,
                   _size > other._size ? _size : other._size);
}

Logic_t Logic_t::operator<<(size_t bits) {
    return Logic_t(_value << bits, _size);
}

Logic_t Logic_t::operator>>(size_t bits) {
    return Logic_t(_value >> bits, _size);
}

bool Logic_t::operator==(Logic_t other) { return _value == other._value; }

bool Logic_t::operator!=(Logic_t other) { return _value != other._value; }

bool Logic_t::operator<(Logic_t other) { return _value < other._value; }

bool Logic_t::operator<=(Logic_t other) { return _value <= other._value; }

bool Logic_t::operator>(Logic_t other) { return _value > other._value; }

bool Logic_t::operator>=(Logic_t other) { return _value >= other._value; }

uint64_t Logic_t::getValue() { return _value; }

uint8_t Logic_t::size() { return _size; }

std::string Logic_t::to_string() const {
    std::stringstream ss;
    uint64_t mask = 1;
    ss<<"'b";
    for (int i = (_size-1); i >= 0; i--) {
                ss << ((_value & (mask << i)) ? 1 : 0);
    }
    return ss.str();
}

bool Logic_t::operator[](int position) {
    if (position > _size)
        messageWarning("Position out of range");

    uint64_t mask        = 1 << position;
    uint64_t masked_data = _value & mask;
    return masked_data != 0;
}
std::ostream &operator<<(std::ostream &out, const Logic_t &c) {
    out << c.to_string();
    return out;
}

} // namespace oden
