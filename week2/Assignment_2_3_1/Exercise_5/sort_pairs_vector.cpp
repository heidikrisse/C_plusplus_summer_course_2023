// sort_pairs_vector.cpp
#include "sort_pairs_vector.h"
#include <algorithm>

// Function to compare the second element in the pair (age)
bool compare_second(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
{
    return a.second < b.second;
}

// Function to sort based on the integral values (age)
void sort_pairs_vector(std::vector<std::pair<std::string, int>> &vec)
{
    std::stable_sort(vec.begin(), vec.end(), compare_second);
}
