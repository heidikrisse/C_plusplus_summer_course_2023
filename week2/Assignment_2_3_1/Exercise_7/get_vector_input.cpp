// get_vector_input.cpp
#include "get_vector_input.h"
#include <iostream>

std::vector<std::pair<int, std::string>> get_pairs_vector_from_user()
{
    std::cout << "Enter the size of the vector: ";
    std::vector<std::pair<int, std::string>>::size_type size{};
    std::cin >> size;

    std::vector<std::pair<int, std::string>> vec(size);
    for (std::vector<std::pair<int, std::string>>::size_type i{0}; i < size; ++i)
    {
        std::cout << "Enter the " << i + 1 << " name-age pair of the vector (name age): ";
        std::cin >> vec[i].second >> vec[i].first;
    }
    return vec;
}
