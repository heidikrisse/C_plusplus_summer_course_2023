/* main.cpp
 *
 * A program that sorts an array of integers in ascending order using std::sort.
 **/
#include "sort_array.h"
#include "get_array_input.h"
#include "print_array.h"

#include <iostream>
#include <algorithm> // for std::sort

int main()
{
    int length{};
    int *array{get_array_from_user(length)};

    sort_array(array, length);

    print_array(array, length);

    delete[] array;

    return 0;
}
