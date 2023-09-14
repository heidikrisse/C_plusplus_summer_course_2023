#ifndef EXERCISE1_H
#define EXERCISE1_H

#include <string>
#include <type_traits>
#include <stdexcept>
#include <cstdio>
#include <vector>

// Helper struct to determine the type of the given argument
template <typename T>
struct TypeSpecifier;

template <>
struct TypeSpecifier<int>
{
    static constexpr const char *value = "%d";
};

template <>
struct TypeSpecifier<double>
{
    static constexpr const char *value = "%f";
};

template <>
struct TypeSpecifier<char>
{
    static constexpr const char *value = "%c";
};

// Other types and their corresponding printf format specifiers can be added here as well

// Function to retrieve all format specifiers from the given string
std::vector<std::string> extract_format_specifiers(const std::string &fmt)
{
    std::vector<std::string> specifiers;
    for (size_t i{0}; i < fmt.size(); ++i)
    {
        if (fmt[i] == '%' && i != fmt.size() - 1)
        {
            char next_char{fmt[i + 1]};
            if (next_char == 'd' || next_char == 'f' || next_char == 'c')
            {
                specifiers.push_back(fmt.substr(i, 2));
                // Move past the format specifier/char to avoid double counting
                ++i;
            }
        }
    }
    return specifiers;
}

template <typename... Ts>
// Function to safely call printf by ensuring that the types of arguments passed match the format specifiers
void safe_printf(const std::string &fmt, Ts... args)
{
    std::vector<std::string> specifiers = extract_format_specifiers(fmt);
    std::vector<std::string> expected = {TypeSpecifier<Ts>::value...};

    if (specifiers.size() != expected.size())
    {
        throw std::runtime_error("Number of arguments doesn't match number of format specifiers in the string.");
    }

    for (size_t i{0}; i < specifiers.size(); ++i)
    {
        if (specifiers[i] != expected[i])
        {
            throw std::runtime_error("Expected a different type for one or more of the provided arguments.");
        }
    }

    std::printf(fmt.c_str(), args...);
}

#endif
