// exercise4.cpp
#include "../include/exercise4.h"
#include <iostream>
#include <vector>

void check_vector_of_vectors_is_contiguous()
{
    std::vector<std::vector<int>> vector_of_vectors{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    std::cout << std::boolalpha; // To get alphabets true or false instead of 1 or 0
    std::cout << "Is std::vector of std::vectors contiguous?\n";
    if (are_elements_contiguous(vector_of_vectors))
    {
        std::cout << "The elements of std::vector<std::vector<int>> are contiguous in memory.\n";
    }
    else
    {
        std::cout << "The elements of std::vector<std::vector<int>> are not contiguous in memory.\n";
    }
}
