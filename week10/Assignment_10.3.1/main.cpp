// main.cpp
#include "include/static_allocator.h"
#include <vector>
#include <iostream>

int main()
{
    // Static allocator for an integer vector
    std::vector<int, StaticAllocator<int>> numbers;

    std::cout << "Inserting values into vector using StaticAllocator...\n";

    for (int i{1}; i < 11; ++i)
    {
        numbers.push_back(i);
    }

    std::cout << "Values in vector:\n";
    for (const int &value : numbers)
    {
        std::cout << value << '\n';
    }

    return 0;
}
