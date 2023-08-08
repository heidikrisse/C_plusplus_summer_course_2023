// exercise_3.cpp
#include "../include/exercise_3.h"

#include <iostream>

// Function to print out set options given a set of flags in human-readable form
void print_set_options(uint8_t flags)
{
    if (flags & IS_FUZZY)
        std::cout << "is fuzzy\n";
    if (flags & IS_LARGE)
        std::cout << "is large\n";
    if (flags & HAS_GOOGLY_EYES)
        std::cout << "has googly eyes\n";
    if (flags & IS_CUTE)
        std::cout << "is cute\n";
    if (flags & HAS_TEETH)
        std::cout << "has teeth\n";
    if (flags & IS_ABOUT_TO_EAT_YOU)
        std::cout << "is about to eat you\n";
    if (flags & IS_FRIENDLY)
        std::cout << "is friendly\n";
    if (flags & IS_SPIDER)
        std::cout << "is a spider\n";
}
