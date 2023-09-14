/* exercise1.h
 *
 * Exercise 1a:
 * Create a function with an integer template parameters, that prints out
 * the first integer value, and then calls the function with remaining
 * values. Break the recursion using overload resolution.
 *
 * Exercise 1b:
 * Create a function with an integer template parameters, that prints out
 * the first integer value, and then calls the function with remaining
 * values. Break the recursion using if contexpr*/
#ifndef EXERCISE1_H
#define EXERCISE1_H

#include <iostream>

// Exercise 1a: Recursion using overload resolution

// Base case
void print_first_and_call_rest() {}

// Recursive case
template <typename First, typename... Rest>
void print_first_and_call_rest(First first, Rest... rest)
{
    std::cout << first << '\n';
    print_first_and_call_rest(rest...);
}

// Exercise 1b: Recursion using `if constexpr`

template <typename First, typename... Rest>
void print_with_if_constexpr(First first, Rest... rest)
{
    std::cout << first << '\n';
    if constexpr (sizeof...(rest) > 0)
    {
        print_with_if_constexpr(rest...);
    }
}

#endif
