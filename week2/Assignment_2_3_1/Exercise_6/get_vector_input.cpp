// get_vector_input.cpp
#include "get_vector_input.h"
#include <iostream>

std::vector<int> get_int_vector_from_user()
{
    std::vector<int>::size_type size{};

    do
    {
        std::cout << "Enter the size of the vector (at least 20): ";
        std::cin >> size;
        if (size < 20)
        {
            std::cout << "Size must be at least 20. Please try again.\n";
        }
    } while (size < 20);

    std::vector<int> vec(size);
    for (std::vector<int>::size_type i{0}; i < size; ++i)
    {
        std::cout << "Enter the " << i + 1 << ". integer value of the vector: ";
        std::cin >> vec[i];
    }
    return vec;
}
