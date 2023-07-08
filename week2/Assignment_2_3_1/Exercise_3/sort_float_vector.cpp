// sort_float_vector.cpp
#include "sort_float_vector.h"
#include <algorithm>

void sort_float_vector(std::vector<float> &vec)
{
    std::stable_sort(vec.begin(), vec.end());
}
