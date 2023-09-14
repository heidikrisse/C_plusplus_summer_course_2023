#ifndef POSITIVE_INTEGER_H
#define POSITIVE_INTEGER_H

#include <stdexcept>

class PositiveInteger
{
private:
    unsigned int value;

public:
    PositiveInteger() : value(0) {}
    PositiveInteger(int input_value);
    PositiveInteger(const PositiveInteger &other) : value(other.value) {}

    void print_value() const;
    void add(const PositiveInteger &other);
    void subtract(const PositiveInteger &other);

    // Declare friend functions to enable operations between two PositiveInteger objects in the Positive integer class as it can access private unsigned int value without showing it to everyone.
    friend PositiveInteger add(const PositiveInteger &a, const PositiveInteger &b);
    friend PositiveInteger subtract(const PositiveInteger &a, const PositiveInteger &b);
};

#endif
