/* exercise5.h
 *
 * Exercise 5:
 *
 * Create a function that takes arbitrary number of containers as arguments
 * and creates a concatenated container.  (e.g.
 * concatenate(std::vector{1, 2}, std::list{5, 8}) -> std::vector{1, 2, 5, 8}; */
#ifndef EXERCISE5_H
#define EXERCISE5_H

#include <vector>
#include <list>

// Base case: When there's only one container left, just convert and return.
template <typename Container, typename Last>
Container concatenate_containers(const Last &last)
{
    return Container(last.begin(), last.end());
}

// Recursive case: Concatenate the first container with the results of the rest.
template <typename Container, typename First, typename... Rest>
Container concatenate_containers(const First &first, const Rest &...rest)
{
    Container result(first.begin(), first.end());
    Container temp = concatenate_containers<Container>(rest...);
    result.insert(result.end(), temp.begin(), temp.end());
    return result;
}

#endif
