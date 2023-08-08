// exercise_5.h
#ifndef EXERCISE_5_H
#define EXERCISE_5_H

#include <cstdint>
#include <string>

/* Function to create a bitmask from a string input: Goes through bytes in the string, and for each character of the string, marks the bit set if the character represents a comma. */
uint32_t create_bitmask_from_string(const std::string &str);

#endif
