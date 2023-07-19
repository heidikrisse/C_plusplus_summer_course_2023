#include "positive_integer.h"
#include <iostream>
#include <limits>

PositiveInteger::PositiveInteger(int input_value)
{
    if (input_value < 0)
    {
        throw std::invalid_argument("Value cannot be negative");
    }
    value = input_value;
}

void PositiveInteger::print_value() const
{
    std::cout << value << "\n";
}

void PositiveInteger::add(const PositiveInteger &other)
{
    unsigned int sum{value + other.value};
    if (sum < value)
    {
        sum = std::numeric_limits<unsigned int>::max();
    }
    value = sum;
}

void PositiveInteger::subtract(const PositiveInteger &other)
{
    // The integers saturate at 0 and the maximum value(so they do
    // not overflow, e.g.42 - 51 = 0)
    if (value > other.value)
    {
        value = value - other.value;
    }
    else
    {
        value = 0;
    }
}

// Friend function implementations
PositiveInteger add(const PositiveInteger &a, const PositiveInteger &b)
{
    unsigned int sum{a.value + b.value};
    if (sum < a.value)
    {
        sum = std::numeric_limits<unsigned int>::max();
    }
    return PositiveInteger(sum);
}

PositiveInteger subtract(const PositiveInteger &a, const PositiveInteger &b)
{
    unsigned int result{};
    if (a.value > b.value)
    {
        result = a.value - b.value;
    }
    else
    {
        result = 0;
    }
    return PositiveInteger(result);
}
