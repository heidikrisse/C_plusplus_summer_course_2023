#define NDEBUG // with the NDEBUG macro defined makes assert() inactive and the assert does nothing
#include <iostream>
#include <cassert>

// Function to calculate the sum of two numbers
int sum(int firstNumber, int secondNumber)
{
    int result{firstNumber + secondNumber};
    // Check if the sum is positive
    assert((result > 0) && "Error: the sum is not positive");
    return result;
}

int main()
{
    std::cout << "Sum of 1 and 2: " << sum(1, 2) << "\n";
    // To see the assertion if the sum is negative
    std::cout << "Sum of 1 and -2: " << sum(1, -2) << "\n";

    return 0;
}
