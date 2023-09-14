#include "../include/exercise_2.h"

#include <iostream>

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    if (b != 0)
        return a / b;
    else
    {
        std::cerr << "Error: You cannot divide by zero!\n";

        return 0;
    }
}

int modulus(int a, int b)
{
    if (b != 0)
        return a % b;
    else
    {
        std::cerr << "Error: You cannot divide by zero!\n";

        return 0;
    }
}

// Function to returns an unordered_map of char and function pairs
calculator_map_t get_calculator_functions()
{
    return {
        // Map '+' to the add function
        {'+', add},
        // Map '-' to the subtract function
        {'-', subtract},
        // Map '*' to the multiply function
        {'*', multiply},
        // Map '/' to the divide function
        {'/', divide},
        // Map '%' to the modulus function
        {'%', modulus}};
}

void perform_operation(const calculator_map_t &calculator_functions)
{
    std::cout << "\n--- Exercise 2: ---\n";
    std::cout << "Enter operation (for example '1 + 2'): ";
    int a{};
    char op{};
    int b{};
    std::cin >> a >> op >> b;

    // Find the operator in the map
    auto it{calculator_functions.find(op)};
    // If the operator is in the map, calculate the operation
    if (it != calculator_functions.end())
    {
        std::cout << "Result: " << it->second(a, b) << '\n';
    }
    // otherwise print error
    else
    {
        std::cerr << "Invalid operator\n";
    }
}
