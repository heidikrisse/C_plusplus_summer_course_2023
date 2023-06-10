// #define NDEBUG
#include <iostream>
#include <cassert>

// Function to perform division of two numbers
double divide(int numerator, int denominator)
{
    // Check if the denominator is not zero
    assert((denominator != 0) && "Error: Division by zero is not allowed");
    return static_cast<double>(numerator) / denominator;
}

int main()
{
    // Displaying the division of 4 by 2
    std::cout << "4 divided by 2: " << divide(4, 2) << "\n";
    // To see the assertion if the denominator is zero
    std::cout << "4 divided by 0: " << divide(4, 0) << "\n";

    return 0;
}
