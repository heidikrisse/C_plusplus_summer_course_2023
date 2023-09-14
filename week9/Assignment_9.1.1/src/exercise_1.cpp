// exercise_1.cpp
#include "../include/exercise_1.h"

#include <iostream>

void function_1()
{
    std::cout << "Function 1 called\n";
}

void function_2()
{
    std::cout << "Function 2 called\n";
}

std::vector<void_func_t> get_functions()
{
    return {function_1, function_2};
}

void call_user_function(const std::vector<void_func_t> &functions)
{
    std::cout << "--- Exercise 1: ---\n";
    while (true)
    {
        std::cout << "Enter the function index to call (0 or 1): ";
        int index{};
        std::cin >> index;

        if (index >= 0 && index < static_cast<int>(functions.size()))
        {
            functions[index]();
            break;
        }
        else
        {
            std::cout << "Invalid index. Please enter a valid index.\n";
        }
    }
}
