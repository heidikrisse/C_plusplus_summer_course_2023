// sort_string_vector.cpp
#include "sort_string_vector.h"
#include <algorithm>

// Function to compare string lengths
bool compare_length(const std::string &a, const std::string &b)
{
    return a.length() < b.length();
}

/* Function to sort strings based on length using stable_sort to
 * preserve lexicographical order */
void sort_string_vector(std::vector<std::string> &vec)
{
    std::stable_sort(vec.begin(), vec.end(), compare_length);
}
