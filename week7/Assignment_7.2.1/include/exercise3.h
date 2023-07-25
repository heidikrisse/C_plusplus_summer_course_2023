/* exercise3.h
 *
 * Exercise 3:
 * In exercise 7.1.1. we created a function to check if two types are
 * the same. Expand on this to check if any number of types given are all
 * the same.*/
#ifndef EXERCISE3_H
#define EXERCISE3_H

#include <type_traits>

// Check if all types are the same
template <typename T, typename... Rest>
constexpr bool are_all_same()
{
    return (... && std::is_same_v<T, Rest>);
}

#endif
