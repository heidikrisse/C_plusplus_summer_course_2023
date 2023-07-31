// exercise3.h
#ifndef EXERCISE3_H
#define EXERCISE3_H

#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <deque>

template <typename Container>
bool are_elements_contiguous(const Container &container)
{
    auto previous_address{reinterpret_cast<const char *>(&(*container.begin()))};
    for (auto it{std::next(container.begin())}; it != container.end(); ++it)
    {
        auto current_address{reinterpret_cast<const char *>(&(*it))};
        if (current_address - previous_address != sizeof(typename Container::value_type))
        {
            return false;
        }
        previous_address = current_address;
    }
    return true;
}

void check_contiguous_memory_different_containers();

#endif
