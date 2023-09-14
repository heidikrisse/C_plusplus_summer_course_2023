// exercise1.h
#ifndef EXERCISE1_H
#define EXERCISE1_H

#include <iostream>
#include <type_traits>

template <typename T>
// Function to determine if a reference is lvalue or rvalue
void determine_reference_type(T &&ref)
{
    // Ignore warning about unused parameter ref
    (void)ref;
    // Check if the reference is lvalue
    if constexpr (std::is_lvalue_reference_v<T>)
    {
        std::cout << "The reference is lvalue reference.\n";
    }
    // Else rvalue
    else
    {
        std::cout << "The reference is rvalue reference.\n";
    }
}

#endif
