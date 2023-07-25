// exercise2.h
#ifndef EXERCISE2_H
#define EXERCISE2_H

#include <cstddef>

// Create a class where the constructor takes any number of arguments.
template <std::size_t N>
class VariadicClass
{
public:
    // Constructor that takes any number of arguments.
    template <typename... Ts>
    VariadicClass(Ts... args)
    {
        // Use static_assert to force a certain number of parameters for the constructor.
        static_assert(sizeof...(args) == N, "Number of provided arguments do not match the expected value.");
    }

    // Function to return the number of arguments the constructor was called with.
    constexpr static std::size_t number_of_arguments()
    {
        return N;
    }

    // Function that requires at compile-time the exact number of arguments the constructor was called with.
    template <typename... Ts>
    void require_exact_args(Ts... args)
    {
        static_assert(sizeof...(args) == N, "Number of provided arguments do not match the expected value.");
    }
};

// Deduction guide to tell how to deduce the template parameters from the constructor.
template <typename... Ts>
VariadicClass(Ts...) -> VariadicClass<sizeof...(Ts)>;

#endif
