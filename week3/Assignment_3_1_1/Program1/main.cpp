/* main.cpp
 *
 * Program to perform a division. */
#include <iostream>
#include "include/number_input.h"
#include "include/division.h"

int main()
{
    double number1{get_number("Enter the numerator: ")};
    double number2{get_number("Enter the denominator: ")};

    try
    {
        double result{perform_division(number1, number2)};
        std::cout << "Result: " << result << "\n";
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
