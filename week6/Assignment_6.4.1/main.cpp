// main.cpp
#include "exercise1.h"
#include "exercise2.h"
#include "exercise3.h"
#include <iostream>

int main()
{
    // Exercise 1:
    std::cout << "Exercise 1:\n";
    exercise1_namespace::function_in_namespace();
    TypeInGlobalNamespace::static_member_function();

    // Exercise 2:
    std::cout << "\nExercise 2:\n";
    vector_namespace::Vector3D vector1;
    vector1.x = 1.0;
    vector1.y = 2.0;
    vector1.z = 3.0;
    std::cout << vector1 << "\n";

    // Exercise 3:
    std::cout << "\nExercise 3:\n";
    vector_namespace::Vector3D vector2;
    vector2.x = 1.0;
    vector2.y = 1.0;
    vector2.z = 1.0;

    vector1 += vector2;
    std::cout << "After addition: " << vector1 << "\n"; // Should be Vector3D(2, 3, 4) after adding +1 to each

    vector1 -= vector2;
    std::cout << "After subtraction: " << vector1 << "\n"; // Should be Vector3D(1, 2, 3) again after substracting -1 from each

    return 0;
}
