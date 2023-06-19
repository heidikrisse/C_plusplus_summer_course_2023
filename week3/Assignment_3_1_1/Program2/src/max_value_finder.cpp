// max_value_finder.cpp
#include <algorithm>
#include <stdexcept> // for std::runtime_error
#include "../include/max_value_finder.h"

int find_max(const std::vector<int> &numbers)
{
    if (numbers.empty())
    {
        throw std::runtime_error("List is empty");
    }

    return *std::max_element(numbers.begin(), numbers.end());
}
