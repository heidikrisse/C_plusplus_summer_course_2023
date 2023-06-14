// sort_array_descending.cpp
#include <algorithm> // for std::sort and std::greater

void sort_array_descending(int *array, int length)
{
    std::sort(array, array + length, std::greater<int>());
}
