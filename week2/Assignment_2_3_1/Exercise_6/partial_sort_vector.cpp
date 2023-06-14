// partial_sort_vector.cpp
#include "partial_sort_vector.h"
#include <algorithm>

// Function to sort the vector and keep only the top 5 elements in
// descending order
void partial_sort_vector(std::vector<int> &vec)
{
    std::partial_sort(vec.begin(), vec.begin() + 5, vec.end(), std::greater<int>());
}
