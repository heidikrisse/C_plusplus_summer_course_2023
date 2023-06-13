// menu.cpp

#include "menu.h"
#include <iostream>

// Function to add a food item to the menu
void Menu::add_food(const Food &food)
{
    foods.push_back(food);
}

// Function to find a food item on the menu by name
const Food *Menu::get_food_by_name(const std::string &name) const
{
    for (const auto &food : foods)
    {
        if (food.name == name)
            return &food;
    }
    // if no such food found
    return nullptr;
}

// Function to print the menu
void Menu::print_menu() const
{
    std::cout << "MENU:\n\n";
    for (const auto &food : foods)
    {
        print_food(food);
        std::cout << "\n";
    }
    std::cout << "\n";
}

// Function to return the number of food items in the menu
std::size_t Menu::size() const
{
    return foods.size();
}
