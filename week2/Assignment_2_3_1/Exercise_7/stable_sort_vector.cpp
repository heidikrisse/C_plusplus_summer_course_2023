// stable_sort_vector.cpp
#include "stable_sort_vector.h"
#include <algorithm>

void stable_sort_vector(std::vector<std::pair<int, std::string>> &vec)
{
    std::stable_sort(vec.begin(), vec.end());
}
