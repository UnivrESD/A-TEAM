#pragma once

#include <iostream>
#include <string>

namespace oden {

/// @brief Logic_t declaration.
/// This class represents the value of a bitvector
class Logic_t {

  public:
    /// @brief Contruct a new Logic_t value
    /// @param value A Logic_t value
    /// @param size The size of the Logic_t
    Logic_t(uint64_t value, uint8_t s);

    /// @brief Contruct a new Logic_t value
    /// @param value A Logic_t value saved in string
    explicit Logic_t(std::string value);

    /// @brief Bitwise Not Operator
    /// @return A new Logic_t value = ~this
    Logic_t operator~();

    /// @brief Bitwise And Operator
    /// If two data have a different size the method mantains the higher size.
    /// @param other Other Logic_t value
    /// @return A new Logic_t value = this & other
    Logic_t operator&(Logic_t other);

    /// @brief Bitwise Or Operator
    /// If two data have a different size the method mantains the higher size.
    /// @param other Other Logic_t value
    /// @return A new Logic_t value = this | other
    Logic_t operator|(Logic_t other);

    /// @brief Bitwise Xor Operator
    /// If two data have a different size the method mantains the higher size.
    /// @param other Other Logic_t value
    /// @return A new Logic_t value = this ^ other
    Logic_t operator^(Logic_t other);

    /// @brief Left Shift Operator
    /// @param bits Number of bits to shift
    /// @return A new Logic_t value = this << bits;
    Logic_t operator<<(size_t bits);

    /// @brief Right Shift Operator
    /// @param bits Number of bits to shift
    /// @return A new Logic_t value = this >> bits;
    Logic_t operator>>(size_t bits);

    /// @brief Arithmetic addition Operator
    /// If two data have a different size the method mantains the higher size.
    /// @param other Other Logic_t value
    /// @return A new Logic_t value = this + other
    Logic_t operator+(Logic_t other);

    Logic_t operator-(Logic_t other);

    Logic_t operator*(Logic_t other);

    Logic_t operator/(Logic_t other);

    /// @brief Equals Operator
    /// @param other Other Logic_t value
    /// @return true if are equals false otherwise
    bool operator==(Logic_t other);
    bool operator!=(Logic_t other);
    bool operator<(Logic_t other);
    bool operator<=(Logic_t other);
    bool operator>(Logic_t other);
    bool operator>=(Logic_t other);

    /// @brief Return the bit in that position
    bool operator[](int position);

    /// @brief Get the value of this logic
    uint64_t getValue();

    /// @brief Get the size of this Logic_t value
    uint8_t size();

    /// @brief Return a string representation of this Logic_t value
    std::string to_string() const;

    friend std::ostream &operator<<(std::ostream &out, const Logic_t &c);

  private:
    uint64_t _value;
    uint8_t _size;
};

} // namespace oden
