// main.cpp
#include "include/function_template_class.h"
#include "include/test_functions.h"

#include <iostream>

int main()
{
    // Create an instance of FunctionTemplateClass for the test function,
    // should have integer as return type and two arguments
    auto function1{make_function(&add_two_numbers)};
    // Create another instance that has return type void and no arguments
    auto function2{make_function(&return_void)};

    // Functions to print function information using decltype
    print_function_info<decltype(function1)>(function1);
    print_function_info<decltype(function2)>(function2);

    return 0;
}
