// exercise1.cpp
#include "../include/exercise1.h"

#include <iostream>

// Print the memory address of a local variable within this function
void print_memory_address_in_function_and_compare_address_difference(int *main_address)
{
    int stack_var_in_function{};
    std::cout << "Memory address of variable in function: " << &stack_var_in_function << '\n';

    // Address difference:
    // Converting addresses to uintptr_t to get integer (otherwise reinterpret_cast not recommended if can be avoided)
    uintptr_t difference{reinterpret_cast<uintptr_t>(main_address) - reinterpret_cast<uintptr_t>(&stack_var_in_function)};
    std::cout << "Difference between addresses: " << difference << '\n';
}
