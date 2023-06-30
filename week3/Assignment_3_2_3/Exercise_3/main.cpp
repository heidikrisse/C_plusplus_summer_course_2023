// main.cpp
#include <iostream>
#include "include/power_calculator.h"

int main()
{
    std::cout << "Enter the base number: ";
    double base{};
    std::cin >> base;

    std::cout << "Enter the exponent: ";
    int exponent{};
    std::cin >> exponent;

    double power{calculate_power(base, exponent)};
    std::cout << "The result of " << base << " to the power of " << exponent << " is: " << power << "\n";

    return 0;
}
