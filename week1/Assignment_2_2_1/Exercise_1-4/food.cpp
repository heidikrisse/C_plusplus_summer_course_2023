// food.cpp

#include "food.h"
#include <iostream>

// Function to print food information with name, price and ingredients
void print_food(const Food &food)
{
    std::cout << "Name: " << food.name << "\n";
    std::cout << "Price: " << food.price << "\n";
    std::cout << "Ingredients: ";
    // Loop over the ingredients
    for (std::size_t i{0}; i < food.ingredients.size(); ++i)
    {
        std::cout << food.ingredients[i];

        // If this is not the last ingredient, print a comma
        if (i != food.ingredients.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "\n";
}
