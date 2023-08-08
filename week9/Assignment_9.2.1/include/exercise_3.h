// exercise_3.h
#ifndef EXERCISE_3_H
#define EXERCISE_3_H

#include <cstdint>

// A set of flags for 8 different options:
constexpr static uint8_t IS_FUZZY = 0b1;
constexpr static uint8_t IS_LARGE = 0b10;
constexpr static uint8_t HAS_GOOGLY_EYES = 0b100;
constexpr static uint8_t IS_CUTE = 0b1000;
constexpr static uint8_t HAS_TEETH = 0b10000;
constexpr static uint8_t IS_ABOUT_TO_EAT_YOU = 0b100000;
constexpr static uint8_t IS_FRIENDLY = 0b1000000;
constexpr static uint8_t IS_SPIDER = 0b10000000;

// Function to print out set options given a set of flags in human-readable form
void print_set_options(uint8_t flags);

#endif
