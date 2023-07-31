// exercise2.cpp
#include "../include/exercise2.h"
#include <iostream>
#include <vector>

void print_vector_and_element_addresses()
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::cout << "Address of vector: " << &vec << '\n';
    for (const auto &element : vec)
    {
        std::cout << "Address of vector element " << element << ": " << &element << '\n';
    }
}
