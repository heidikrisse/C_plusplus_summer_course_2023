#include <iostream>
#include <cassert>

// Function to calculate factorial of a given number
int factorial(int number)
{
    assert(number >= 0 && "Error: factorial is not defined for negative numbers");
    int result{1};
    // Calculating factorial by multiplying numbers from 1 to num
    for (int i{1}; i <= number; ++i)
    {
        result *= i;
    }
    return result;
}

int main()
{
    std::cout << "Factorial of 5: " << factorial(5) << "\n";
    // To see the assertion when given a negative number
    std::cout << "Factorial of -5: " << factorial(-5) << "\n";

    return 0;
}
