// print_vector.cpp
#include "print_vector.h"
#include <iostream>

void print_string_vector(const std::vector<std::string> &vec)
{
    std::cout << "A vector of strings sorted in lexicographical order and based on the string length:\n";
    for (const auto &value : vec)
    {
        std::cout << value << '\n';
    }
}
