// reverse_string.cpp
#include "../include/greatest_common_divisor.h"

// Function to find the Greatest Common Divisor of two numbers using the Euclidean algorithm
int calculate_gcd(int input_number1, int input_number2)
{
    // Base condition
    if (input_number2 == 0)
    {
        return input_number1;
    }

    // Recursive call
    return calculate_gcd(input_number2, input_number1 % input_number2);
}
