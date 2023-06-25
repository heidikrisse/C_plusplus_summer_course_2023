// main.cpp
#include <iostream>
#include "include/greatest_common_divisor.h"

int main()
{
    std::cout << "Enter the first number: ";
    int input_number1{};
    std::cin >> input_number1;

    std::cout << "Enter the second number: ";
    int input_number2{};
    std::cin >> input_number2;

    int greatest_common_divisor{calculate_gcd(input_number1, input_number2)};
    std::cout << "The Greatest Common Divisor of number " << input_number1 << " and number " << input_number2 << " is: " << greatest_common_divisor << "\n";

    return 0;
}
