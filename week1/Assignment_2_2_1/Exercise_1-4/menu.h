// menu.h

#ifndef MENU_H
#define MENU_H

#include "food.h"
#include <vector>

class Menu
{
public:
    // Function to add a food item to the menu
    void add_food(const Food &food);
    // Function to print the menu
    void print_menu() const;
    // Function to find a food item on the menu by name
    const Food *get_food_by_name(const std::string &name) const;
    // Function to return the number of food items in the menu
    std::size_t size() const;

private:
    std::vector<Food> foods{};
};

#endif
