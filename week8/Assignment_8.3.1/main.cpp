// main.cpp
#include <iostream>
#include "include/heap_array.h"

int main()
{
    // Exercise 2:
    std::cout << " --- Exercise 2: ---\n\n";

    // A.) Default constructor
    std::cout << "A.) Default constructor:\n";
    HeapArray<int> default_array;

    std::cout << "Size of array using default constructor: " << default_array.size() << "\n\n"; // Should print 0

    HeapArray<int> array1{3};

    for (int i{0}; i < 3; ++i)
    {
        array1[i] = i + 1;
    }

    // B.) Copy constructor
    std::cout << "B.) Copy constructor:\n";
    HeapArray<int> copy_array = array1;
    std::cout << "Original array (using copy constructor):\n";
    for (int array_value : copy_array)
    {
        std::cout << array_value << " ";
    }
    std::cout << "\n\n";

    // C.) Move constructor:
    std::cout << "C.) Move constructor:\n";
    HeapArray<int> move_array = std::move(copy_array);
    std::cout << "Array after move (using move constructor):\n";
    for (int array_value : move_array)
    {
        std::cout << array_value << " ";
    }
    std::cout << "\n\n";

    // D.) Destructor

    // E.) Assignment operators

    // Exercise 3:
    std::cout << " --- Exercise 3: ---\n\n";

    // A.) Access using operator[]
    std::cout << "A.) Access using operator[]\n";
    std::cout << "Third element using operator[]: " << array1[2] << "\n\n";

    // B.) Access using at()
    std::cout << "B.) Access using at()\n";
    try
    {
        std::cout << "Third element of the array using at(): " << array1.at(2) << '\n';
        // Try to access an out-of-range element
        std::cout << array1.at(5) << "\n\n";
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Exception caught: " << e.what() << "\n\n";
    }

    // Exercise 4:
    std::cout << " --- Exercise 4: ---\n\n";

    std::cout << "Swapping two arrays:\n\n";
    for (int i{0}; i < 3; i++)
    {
        array1[i] = i + 1; // values 1, 2, 3
    }
    HeapArray<int> array2{4};
    for (int i{0}; i < 4; ++i)
    {
        array2[i] = i + 4; // values 4, 5, 6, 7
    }

    std::cout << "Before swapping:\n";
    std::cout << "array1: ";
    for (int array_value : array1)
        std::cout << array_value << ' ';
    std::cout << "\narray2: ";
    for (int array_value : array2)
        std::cout << array_value << ' ';
    std::cout << "\n\n";

    array1.swap(array2);

    std::cout << "After swapping:\n";
    std::cout << "array1: ";
    for (int array_value : array1)
        std::cout << array_value << ' ';
    std::cout << "\narray2: ";
    for (int array_value : array2)
        std::cout << array_value << ' ';
    std::cout << "\n\n";

    // Exercise 5:
    std::cout << " --- Exercise 5: ---\n\n";

    std::cout << "Rest of the container requirements:\n\n";

    // --- empty() ---

    std::cout << "Is the array1 empty?: ";
    if (array1.empty())
    {
        std::cout << "Yes";
    }
    else
    {
        std::cout << "No";
    }
    std::cout << "\n\n";

    // --- size() ---

    std::cout << "Size of the array1: " << array1.size() << "\n\n"; // Should print 5

    // --- max_size() ---

    std::cout << "Max size of the array1: " << array1.max_size() << "\n\n";

    // --- Equality and inequality operators

    // Inequal arrays:
    std::cout << "Inequal arrays:\n\n";

    std::cout << "Array1 values: ";
    for (const auto &array_value : array1)
    {
        std::cout << array_value << ' ';
    }
    std::cout << '\n';

    std::cout << "Array2 values: ";
    for (const auto &array_value : array2)
    {
        std::cout << array_value << ' ';
    }
    std::cout << "\n\n";

    if (array1 == array2)
    {
        std::cout << "Array1 and Array2 are equal.\n\n";
    }
    else
    {
        std::cout << "Array1 and Array2 are not equal.\n\n"; // Should print
    }

    // Equal arrays
    std::cout << "Equal arrays:\n\n";

    HeapArray<int> array3{3};
    for (int i{0}; i < 3; ++i)
        array3[i] = i + 1;

    std::cout << "Array2 values: ";
    for (const auto &array_value : array2)
    {
        std::cout << array_value << ' ';
    }
    std::cout << '\n';

    std::cout << "Array3 values: ";
    for (const auto &array_value : array3)
    {
        std::cout << array_value << ' ';
    }
    std::cout << "\n\n";

    if (array2 == array3)
    {
        std::cout << "Array2 and Array3 are equal.\n\n"; // Should print
    }
    else
    {
        std::cout << "Array2 and Array3 are not equal.\n\n";
    }

    // --- Clear() ---

    array1.clear();

    std::cout << "After clearing, the size of the array1: " << array1.size() << "\n\n"; // Should print 0

    return 0;
}
