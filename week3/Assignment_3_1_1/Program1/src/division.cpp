// divicion.cpp
#include "../include/division.h"

#include <stdexcept> // uses std::runtime_error

double perform_division(double numerator, double denominator)
{
    if (denominator == 0)
    {
        throw std::runtime_error("Cannot divide by zero");
    }
    return numerator / denominator;
}
