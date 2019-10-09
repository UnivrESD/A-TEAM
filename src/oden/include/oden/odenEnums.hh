#pragma once

#include <string>

namespace oden {

/// @brief Variable types.
enum class VariableType { unknown = 1, logic = 2, numeric = 4, boolean = 8 };

enum class BinaryOperator {
    // Boolean operators
    AND = 1,
    OR  = 2,
    XOR = 3,
    // Arithmetic operators
    SUM = 4,
    SUB = 5,
    MUL = 6,
    DIV = 7,
    // Bitwise operators
    BAND = 8,
    BOR  = 9,
    BXOR = 10,
    NOT  = 11,
    // Relational operators
    EQ  = 12,
    NEQ = 13,
    LT  = 14,
    LE  = 15,
    GT  = 16,
    GE  = 17
};

/// @brief Return a string representing the given variable type.
/// @param t The variable type.
/// @return The string representation of the given variable type.
std::string variableTypeToString(VariableType t);

/// @brief Return the variable type for a given string.
/// @param s The string.
/// @return The variable type for the given string.
VariableType variableTypeFromString(const std::string &s);

/// @brief Variable direction.
enum class VariableDirection { dir_in, dir_out, dir_inout };

/// @brief Return string representation of given variable direction.
/// @param t The variable direction.
/// @return The string representation of given variable direction.
std::string variableDirectionToString(VariableDirection t);

/// @brief Return the variable direction for given string.
/// @param s The string.
/// @return The variable direction for given string.
VariableDirection variableDirectionFromString(const std::string &s);
} // namespace oden
