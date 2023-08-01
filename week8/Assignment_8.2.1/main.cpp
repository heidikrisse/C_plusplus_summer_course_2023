// main.cpp
#include "include/exercise1.h"
#include "include/exercise2.h"
#include "include/exercise3.h"

#include <iostream>

int main()
{
    // Exercise 1:
    std::cout << "Exercise 1:\n";
    int lvalue_variable{};
    determine_reference_type(lvalue_variable); // lvalue reference
    determine_reference_type(5);               // rvalue reference

    // Exercise 2:
    std::cout << "\nExercise 2:\n";
    DebugClass<true> object1;
    // Calls copy constructor
    DebugClass<true> object2 = object1;
    // Calls move constructor
    DebugClass<true> object3 = std::move(object2);

    // Exercise 3:
    std::cout << "\nExercise 3:\n";
    // Create an instance and count instances:
    CountedInstance instance1("instance1");
    CountedInstance::print_count(); // Instance count: 1

    {
        // Create another instance inside a block scope
        CountedInstance instance2("instance2");
        CountedInstance::print_count(); // Instance count: 2

        // Move instance2 to new_instance
        // Move gives instance2's data to new_instance (also its name) without creating a new instance or destroying instance2, so it's move and not copy
        CountedInstance new_instance = std::move(instance2);
        CountedInstance::print_count(); // Instance count: 2 (instance1 and new_instance called "instance2")

    } // At the end of the block, "instance2" is destroyed and instance count is 1 becuase instance1 remains

    CountedInstance::print_count(); // 1 (instance1)

    return 0;
} // Instance 1 is destroyed
