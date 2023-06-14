// print_vector.cpp
#include "print_vector.h"
#include <iostream>

void print_int_vector(const std::vector<int> &vec)
{
    std::cout << "\nThe top 5 elements of the vector (int):\n\n";
    for (std::size_t i = 0; i < std::min(vec.size(), static_cast<std::size_t>(5)); ++i)
    {
        std::cout << vec[i] << '\n';
    }
}
