// print_pairs_vector.cpp
#include "print_pairs_vector.h"
#include <iostream>

void print_pairs_vector(const std::vector<std::pair<int, std::string>> &vec)
{
    std::cout << "\nSorted vector of pairs: \n";
    for (const auto &pair : vec)
    {
        std::cout << "Name: " << pair.second << ", Age: " << pair.first << '\n';
    }
}
