// exercise_1.h
#ifndef EXERCISE_1_H
#define EXERCISE_1_H

#include <iostream>

// Template function to print bits
template <typename T>
void print_bits(const T &value)
{
    using decay_type = std::decay_t<T>;
    bool started_printing{false};

    std::cout << "0b";

    for (int i{sizeof(decay_type) * 8 - 1}; i >= 0; --i)
    {
        if ((value & (1 << i)) || started_printing)
        {
            started_printing = true;
            
            std::cout << ((value & (1 << i)) ? '1' : '0');
        }

        // Add space after every 8 bits but not at the very end
        if (i % 8 == 0 && started_printing && i != 0)
        {
            std::cout << ' ';
        }
    }

    // If no '1' found in the value = bits were printed, print only '0'
    if (!started_printing)
    {
        std::cout << '0';
    }

    std::cout << '\n';
}

// Function to check if nth bit is set in a given value, returns true or false
bool is_nth_bit_set(int value, int n);

#endif
