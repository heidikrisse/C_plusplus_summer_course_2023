#include "../include/exercise_4.h"

#include <iostream>

// Function to check for certain combinations of the set flags, and print out something special for those
void check_combinations(uint8_t flags)
{
    if ((flags & IS_FRIENDLY) && (flags & IS_SPIDER))
    {
        std::cout << "The creature is a friendly spider.\n";
    }
    if ((flags & HAS_TEETH) && (flags & IS_ABOUT_TO_EAT_YOU))
    {
        std::cout << "The creature has teeth and might eat you!\n";
    }
    if ((flags & IS_FUZZY) && (flags & HAS_GOOGLY_EYES))
    {
        std::cout << "The creature is fuzzy and has googly eyes.\n";
    }
}
