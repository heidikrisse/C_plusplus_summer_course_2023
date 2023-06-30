// userInterface.h

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "menu.h"
#include "order.h"

// Enum class for the different choices a user can make
enum class UserChoice
{
    /* Sets underlying integral value for the first enumerator (PlaceOrder)
     * so that if the user selects the choice 1, the choice is PlaceOrder
     */
    PlaceOrder = 1,
    AddFood,
    Quit
};

// Function to get a user's choice
UserChoice get_user_choice();
// Function to handle adding food to the menu
void handle_add_food(Menu &menu);
// Function to handle a user placing an order
void handle_place_order(Menu &menu, Order &order);

#endif
