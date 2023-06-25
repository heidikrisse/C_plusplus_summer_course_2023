// reverse_string.cpp
#include "../include/reverse_string.h"

// Function to reverse a string recursively
std::string reverse_string(std::string str)
{
    // If string is empty (base condition of recursion)
    if (str.empty())
    {
        return str; // if string is empty, return empty string
    }

    // Take the last character of the string
    char last_character = str.back();

    // Remove the last character from the string
    str.pop_back();

    // Reverse the remaining string
    std::string remaining_reversed{reverse_string(str)};

    // Add the last character to the start of the reversed remaining string
    std::string result{last_character + remaining_reversed};

    return result;
}
