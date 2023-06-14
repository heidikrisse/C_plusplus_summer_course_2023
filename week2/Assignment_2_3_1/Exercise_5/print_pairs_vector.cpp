// print_pairs_vector.cpp
#include "print_pairs_vector.h"
#include <iostream>

void print_pairs_vector(const std::vector<std::pair<std::string, int>> &vec)
{
    std::cout << "\nA vector of name (str) - age (int) pairs sorted based on the integer (age):\n\n";
    for (const auto &pair : vec)
    {
        std::cout << "Name: " << pair.first << ", Age: " << pair.second << '\n';
    }
}
