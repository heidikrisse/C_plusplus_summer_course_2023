// print_array.cpp
#include <iostream>

void print_array(int *array, int length)
{
    std::cout << "\nThe array values in descending order are:\n";
    for (int i{0}; i < length; ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
}
