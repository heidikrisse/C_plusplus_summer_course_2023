/* main.cpp
 *
 * A program that uses std::sort with std::greater<int>() to sort an array
 * of integers in descending order
 **/
#include "sort_array_descending.h"
#include "get_array_input.h"
#include "print_array.h"

#include <iostream>
#include <algorithm> // for std::sort and std::greater

int main()
{
    int length{};
    int *array{get_array_from_user(length)};

    sort_array_descending(array, length);

    print_array(array, length);

    delete[] array;

    return 0;
}
