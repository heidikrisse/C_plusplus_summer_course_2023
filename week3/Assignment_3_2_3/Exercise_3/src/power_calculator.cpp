// power_calculator.cpp
#include "../include/power_calculator.h"

// Function to calculate the power of a number recursively
double calculate_power(double base, int exponent)
{
    // Base condition
    if (exponent == 0)
    {
        return 1;
    }

    // If exponent is negative, get the reciprocal of base
    if (exponent < 0)
    {
        return calculate_power(1 / base, -exponent);
    }

    // Recursive call
    return base * calculate_power(base, exponent - 1);
}
