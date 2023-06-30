// main.cpp

#include <iostream>
#include "userInterface.h"

int main()
{
    Menu menu;   // menu object
    Order order; // order object

    while (true)
    {
        std::cout << "FOOD ORDER SYSTEM FOR THE RESTAURANT HEIDI\n\n";

        // gets a user's choice
        UserChoice choice{get_user_choice()};
        switch (choice)
        {
        case UserChoice::PlaceOrder:
            handle_place_order(menu, order);
            break;
        case UserChoice::AddFood:
            handle_add_food(menu);
            break;
        case UserChoice::Quit:
            return 0;
        default:
            std::cerr << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
