// get_vector_input.cpp
#include "get_vector_input.h"
#include <iostream>

std::vector<float> get_vector_from_user()
{
    std::cout << "Enter the size of the vector: ";
    int size{};
    std::cin >> size;

    std::vector<float> vec(size);
    for (int i{0}; i < size; ++i)
    {
        std::cout << "Enter the " << i + 1 << ". floating value of the vector: ";
        std::cin >> vec[i];
    }
    return vec;
}
