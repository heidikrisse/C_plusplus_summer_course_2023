// type_checker.h
#ifndef TYPE_CHECKER_H
#define TYPE_CHECKER_H

#include <type_traits> // for std::is_same_v and std::decay_t

// Exercise 1: checks if types are the same
template <typename T, typename U>
constexpr bool are_same_types()
{
    return std::is_same_v<T, U>;
}

// Exercise 2: creates a constexpr function that checks if a type can be decayed further
template <typename T>
constexpr bool can_be_decayed_further()
{
    return !std::is_same_v<T, std::decay_t<T>>;
}

#endif
