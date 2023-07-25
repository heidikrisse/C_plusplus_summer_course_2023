/* exercise4.h
 *
 * Exercise 4:
 * Create a function that takes arbitrary number of arguments and return
 * the product of the arguments times the number of arguments.*/
#ifndef EXERCISE4_H
#define EXERCISE4_H

#include <cstddef>

template <typename... Args>
// Function to count the number of arguments
constexpr size_t count_args(Args... args)
{
    return sizeof...(args);
}

template <typename... Args>
auto product_of_args_times_count(Args... args)
{
    // Return fold expression of product of arguments * number of arguments
    return (... * args) * sizeof...(args);
}

#endif
