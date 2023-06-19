// numbers_input.cpp
#include <iostream>
#include <limits>
#include "../include/numbers_input.h"

std::vector<int> get_numbers(const std::string &prompt)
{
    std::cout << prompt;
    std::vector<int> numbers{};
    int number{};

    while (std::cin >> number)
    {
        numbers.push_back(number);
    }

    // Clear the error state after non-number input
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return numbers;
}
