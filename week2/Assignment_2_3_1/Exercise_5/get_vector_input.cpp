// get_vector_input.cpp
#include "get_vector_input.h"
#include <iostream>

std::vector<std::pair<std::string, int>> get_pairs_vector_from_user()
{
    std::cout << "Enter the size of the vector: ";
    int size{};
    std::cin >> size;

    std::vector<std::pair<std::string, int>> vec(size);
    for (int i{0}; i < size; ++i)
    {
        std::cout << "Enter the " << i + 1 << ". name-age value pair of the vector (name age): ";
        std::cin >> vec[i].first >> vec[i].second;
    }
    return vec;
}
