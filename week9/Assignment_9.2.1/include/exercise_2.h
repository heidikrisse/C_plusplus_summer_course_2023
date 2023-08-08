// exercise_2.h
#ifndef EXERCISE_2_H
#define EXERCISE_2_H

#include <type_traits>

//  Template function to swap byte order of the value it is given, regardless of its size
template <typename T>
T swap_byte_order(T value)
{
    static_assert(std::is_integral_v<T>, "Only integral types are accepted!");

    T result = 0;
    for (std::size_t i{0}; i < sizeof(T); ++i)
    {
        result = (result << 8) | ((value >> (i * 8)) & 0xFF);
    }

    return result;
}

#endif
