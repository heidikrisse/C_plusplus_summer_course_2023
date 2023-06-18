// random_number_generator.cpp
#include "../include/random_number_generator.h"

#include <random>

// Function to generate a random number within the range [min, max]
int generate_random_number(int min, int max)
{
    std::random_device rd{};
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);

    return distrib(gen); // Return a random number
}
