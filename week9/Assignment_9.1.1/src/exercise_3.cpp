// exercise3.cpp
#include "../include/exercise_3.h"

#include <iostream>

// Function to set two variables in variable_map
void set_variable(variable_map_t &variable_map)
{
    // Set a variable
    std::cout << "\n--- Exercise 3: ---\n";
    std::cout << "Enter variable name (for example 'a'): ";
    std::string variable_name{};
    std::cin >> variable_name;

    std::cout << "Enter the value of the variable " << variable_name << ": ";
    int value{};
    std::cin >> value;

    variable_map[variable_name] = value;

    // Set another variable
    std::cout << "Enter variable name (for example 'b'): ";
    std::cin >> variable_name;

    std::cout << "Enter the value of the variable " << variable_name << ": ";
    std::cin >> value;

    variable_map[variable_name] = value;
}

// Function to return the variable value
int get_variable_value(const variable_map_t &variable_map, const std::string &variable_name)
{
    // Find the variable in variable_map
    auto it{variable_map.find(variable_name)};
    // If the variable is in variable_map, return its value
    if (it != variable_map.end())
    {
        return it->second;
    }
    // otherwise print error message and return 0
    else
    {
        std::cerr << "Variable not found\n";

        return 0;
    }
}

// Function to calculate operation with variables
void calculate_operation_with_variables(const calculator_map_t &calculator_functions, const variable_map_t &variable_map)
{
    std::cout << "Enter operation (for example 'a + b'): ";
    std::string a_name{};
    std::string b_name{};
    char op{};
    std::cin >> a_name >> op >> b_name;

    int a{get_variable_value(variable_map, a_name)};
    int b{get_variable_value(variable_map, b_name)};

    auto it{calculator_functions.find(op)};
    if (it != calculator_functions.end())
    {
        std::cout << "Result: " << it->second(a, b) << '\n';
    }
    else
    {
        std::cerr << "Invalid operator\n";
    }
}
