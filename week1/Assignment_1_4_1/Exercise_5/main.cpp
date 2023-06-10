// #define NDEBUG
#include <iostream>
#include <cmath>
#include <cassert>

// Function to calculate the square root of a given number
double square_root(double number)
{
    // Check if the number is not negative
    assert((number >= 0) && "Error: Square root is not defined for negative numbers");
    return std::sqrt(number);
}

int main()
{
    // Displaying the square root of 2
    std::cout << "Square root of 2: " << square_root(2) << "\n";
    // To see the assertion if the number is negative
    std::cout << "Square root of -2: " << square_root(-2) << "\n";

    return 0;
}
