// food.h

#ifndef FOOD_H
#define FOOD_H

#include <string>
#include <vector>

// Definition of the Food structure.
struct Food
{
    std::string name{};
    double price{};
    std::vector<std::string> ingredients{};
};

// Function to print food information
void print_food(const Food &food);

#endif
