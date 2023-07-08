// print_vector.cpp
#include "print_vector.h"
#include <iostream>

void print_vector(const std::vector<float> &vec)
{
    std::cout << "\nA vector of floating point numbers after sorting:\n";
    for (const auto &value : vec)
    {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}
