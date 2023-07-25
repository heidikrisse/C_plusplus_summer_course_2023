/* exercise2.h
 *
 * Exercise 2:
 * Create a function that takes arbitrary number of arguments and returns
 * the sum of the arguments. How should you handle errors (such as argument
 * not being a number) here? */
#ifndef EXERCISE2_H
#define EXERCISE2_H

template <typename... Args>
auto sum_of_arguments(Args... args)
{
    // Return fold expression
    return (... + args);
}

#endif
