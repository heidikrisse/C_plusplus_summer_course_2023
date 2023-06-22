// name_selector.cpp
#include <vector>
#include <stdexcept> // for std::runtime_error
#include "../include/name_selector.h"

std::string select_name(const std::vector<std::string> &names, int user_index)
{
    if (user_index < 0 || user_index >= static_cast<int>(names.size()))
    {
        throw std::runtime_error("Index out of range");
    }

    return names[user_index];
}
