// check_relative_order.cpp
#include "check_relative_order.h"
#include <iostream>

void check_relative_order(const std::vector<std::pair<int, std::string>> &vec)
{
    bool is_order_maintained{true};

    for (std::size_t i{1}; i < vec.size(); ++i)
    {
        if (vec[i].first == vec[i - 1].first && vec[i].second < vec[i - 1].second)
        {
            is_order_maintained = false;
            break;
        }
    }

    if (is_order_maintained)
    {
        std::cout << "The relative order is maintained.\n";
    }
    else
    {
        std::cout << "The relative order is not maintained.\n";
    }
}
