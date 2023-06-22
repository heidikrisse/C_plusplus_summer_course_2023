// data_processor.cpp
#include <iostream>
#include <string>
#include <cctype>
#include <limits> // for std::numeric_limits
#include "../include/data_processor.h"

int get_number(const std::string &prompt)
{
    std::cout << prompt;
    int number{};
    std::cin >> number;

    // Ignore remaining characters in the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return number;
}

std::string get_string(const std::string &prompt)
{
    std::cout << prompt;
    std::string str{};
    std::cin >> str;

    return str;
}

void process_data(int number)
{
    if (number < 0)
    {
        throw std::runtime_error("Invalid integer. Integer should not be negative.");
    }
    std::cout << "Processing integer: " << number << "\n";
}

void process_data(const std::string &str)
{
    for (char ch : str)
    {
        if (!std::isalpha(ch))
        {
            throw std::runtime_error("Invalid string. String should only contain alphabet characters.");
        }
    }
    std::cout << "Processing string: " << str << "\n";
}
