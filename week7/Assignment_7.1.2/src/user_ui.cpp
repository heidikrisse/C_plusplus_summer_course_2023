#include "user_ui.h"
#include <iostream>
#include <limits>

std::size_t get_positive_input(const std::string &prompt)
{
    std::size_t grid_size_value{};
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> grid_size_value)
        {
            return grid_size_value;
        }
        else
        {
            std::cout << "Invalid input. Please enter a positive integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int get_input(const std::string &prompt)
{
    int grid_init_value{};
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> grid_init_value)
        {
            return grid_init_value;
        }
        else
        {
            std::cout << "Invalid input. Please enter an integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
