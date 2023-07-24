// main.cpp
#include "type_checker.h"
#include <iostream>

int main()
{
    // Testing are_same_types
    std::cout << "Are int and double the same types? ";
    if (are_same_types<int, double>())
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }

    std::cout << "Are int and int the same types? ";
    if (are_same_types<int, int>())
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }

    // Testing can_be_decayed_further
    std::cout << "Can int& be decayed further? ";
    if (can_be_decayed_further<int &>())
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }

    std::cout << "Can int be decayed further? ";
    if (can_be_decayed_further<int>())
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }

    return 0;
}
