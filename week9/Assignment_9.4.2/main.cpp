// main.cpp
#include "include/exercise_1.h"
#include "include/exercise_2.h"

#include <iostream>

int main()
{
    // Exercise 1:
    std::cout << "Exercise 1:\n\n";
    auto instance_success_optional{ClassWithOptional::create_instance(false)};
    if (instance_success_optional)
    {
        std::cout << "Successfully created instance with optional.\n";
    }
    else
    {
        std::cout << "Failed to create instance with optional.\n";
    }

    auto instance_failure_optional{ClassWithOptional::create_instance(true)};
    if (!instance_failure_optional)
    {
        std::cout << "Failed to create instance with optional (expected).\n";
    }

    // Exercise 2:
    std::cout << "\nExercise 2:\n\n";
    auto instance_success_expected{ClassWithExpected::create_instance(false)};
    if (instance_success_expected)
    {
        std::cout << "Successfully created instance with expected.\n";
    }
    else
    {
        std::cout << "Failed to create instance with expected due to: " << instance_success_expected.error() << '\n';
    }

    auto instance_failure_expected{ClassWithExpected::create_instance(true)};
    if (!instance_failure_expected)
    {
        std::cout << "Failed to create instance with expected due to: " << instance_failure_expected.error() << " (expected)\n";
    }

    return 0;
}
