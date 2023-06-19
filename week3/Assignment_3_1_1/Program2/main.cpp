/* main.cpp
 *
 * Program to find maximum value from a vector of numbers. */
#include <iostream>
#include <vector>
#include "include/numbers_input.h"
#include "include/max_value_finder.h"

int main()
{
    std::vector<int> numbers{get_numbers("Enter integers (enter 'e' when done): ")};

    try
    {
        int max_value{find_max(numbers)};
        std::cout << "Maximum value is: " << max_value << "\n";
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
