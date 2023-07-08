// get_vector_input.cpp
#include "get_vector_input.h"
#include <iostream>

std::vector<std::string> get_string_vector_from_user()
{
    std::cout << "Enter the size of the vector: ";
    std::vector<std::string>::size_type size{};
    std::cin >> size;

    std::cin.ignore(); // Ignore the newline character

    std::vector<std::string> vec(size);
    for (std::vector<std::string>::size_type i{0}; i < size; ++i)
    {
        std::cout << "Enter the " << i + 1 << ". value of the vector: ";
        std::getline(std::cin, vec[i]);
    }
    return vec;
}
