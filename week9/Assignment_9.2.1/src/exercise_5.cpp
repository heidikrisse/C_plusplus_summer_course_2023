// exercise_5.cpp
#include "../include/exercise_5.h"

/* Function to create a bitmask from a string input: Goes through bytes in the string, and for each character of the string, marks the bit set if the character represents a comma. */
uint32_t create_bitmask_from_string(const std::string &str)
{
    uint32_t bitmask{0};
    for (std::size_t i{0}; i < str.size(); ++i)
    {
        if (str[i] == ',')
        {
            bitmask |= (1 << (str.size() - i - 1));
        }
    }
    return bitmask;
}
