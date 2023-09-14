// main.cpp
#include "type_checker.h"
#include <iostream>

int main()
{
    using TypeA = int;
    using TypeB = double;
    using TypeC = int;
    using TypeD = int &;

    // Testing are_same_types
    std::cout << "Are TypeA and TypeB the same types? ";
    if (are_same_types<TypeA, TypeB>())
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }

    std::cout << "Are TypeA and TypeC the same types? ";
    if (are_same_types<TypeA, TypeC>())
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }

    // Testing can_be_decayed_further
    std::cout << "Can TypeD be decayed further? ";
    if (can_be_decayed_further<TypeD>())
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }

    std::cout << "Can TypeA be decayed further? ";
    if (can_be_decayed_further<TypeA>())
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }

    return 0;
}
