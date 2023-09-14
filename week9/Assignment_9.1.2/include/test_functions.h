// test_functions.h
// --- Exercise 1c ---
#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTIONS_H

#include "function_template_class.h"

#include <iostream>
#include <typeinfo>

// Test function to calculate the sum of two integers (takes two integers) and return the integer result
int add_two_numbers(int, int);

// Test function to return void (takes no arguments)
void return_void();

// Used decltype to printing out infomation contained without manually entering the template parameters
template <typename FunctionType>
void print_function_info(FunctionType function_template)
{
    std::cout << "Function return type: " << typeid(typename FunctionType::ReturnType).name() << '\n';
    std::cout << "Function arity (how many arguments the function takes): " << function_template.get_arity() << '\n';
    std::cout << "Function argument types: " << typeid(typename FunctionType::ArgumentTypes).name() << "\n\n";
}

#endif
