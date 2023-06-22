// number_input.cpp
#include <iostream>
#include "../include/number_input.h"

double get_number(const std::string &prompt)
{
    std::cout << prompt;
    double num{};
    std::cin >> num;
    return num;
}
