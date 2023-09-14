// exercise_1.cpp
#include "../include/exercise_1.h"

// Function to check if nth bit is set in a given value, returns true or false
bool is_nth_bit_set(int value, int n)
{
    return (value & (1 << n)) != 0;
}
