// main.cpp
#include "include/exercise1.h"
#include "include/exercise2.h"
#include "include/exercise3.h"
#include "include/exercise4.h"
#include <iostream>

int main()
{
    // Exercise 1:
    std::cout << "Exercise 1:\n";
    // Declare a local stack variable in the main function
    int stack_var_in_main{};
    std::cout << "Memory address of stack variable in main: " << &stack_var_in_main << '\n';
    print_memory_address_in_function_and_compare_address_difference(&stack_var_in_main);

    // Exercise 2:
    std::cout << "\nExercise 2:\n";
    print_vector_and_element_addresses();

    // Exercise 3:
    std::cout << "\nExercise 3:\n";
    check_contiguous_memory_different_containers();

    // Exercise 4:
    std::cout << "\nExercise 4:\n";
    check_vector_of_vectors_is_contiguous();

    return 0;
}
