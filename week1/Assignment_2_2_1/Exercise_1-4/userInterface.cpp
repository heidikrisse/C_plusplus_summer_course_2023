/* userInterface.cpp
 *
 * Contains the functions for interacting with the user.
 */

#include "userInterface.h"
#include <iostream>

// Function to get a user's choice from the menu
UserChoice get_user_choice()
{
    int choice{};
    do
    {
        std::cout << "1. See the menu and place an order\n";
        std::cout << "2. Add a new food to the menu\n";
        std::cout << "3. Quit\n";
        std::cout << "Select your choice: ";
        std::cin >> choice;

        // Validating a user's input
        if (choice < 1 || choice > 3)
            std::cout << "Invalid choice. Please enter again.\n";
        std::cout << "\n";
    } while (choice < 1 || choice > 3); // continue until a valid choice is given

    // Casting the user's choice to an enum value
    return static_cast<UserChoice>(choice);
}

// Function to handle a user adding a new food to the menu
void handle_add_food(Menu &menu)
{
    std::cout << "Enter food name: ";
    // clears the input buffer by ignoring the next character in buffer
    std::cin.ignore();
    std::string name{};
    std::getline(std::cin, name);

    std::cout << "Enter food price: ";
    double price{};
    std::cin >> price;

    std::vector<std::string> ingredients;
    std::string ingredient{};
    std::cout << "Enter ingredients (hit enter [empty] to finish): \n";
    // clears the input buffer
    std::cin.ignore();
    // continue until an empty input is given
    while (std::getline(std::cin, ingredient))
    {
        if (ingredient.empty())
        {
            break;
        }
        else
        {
            // Adding the ingredient to the ingredient list
            ingredients.push_back(ingredient);
            ingredient = {}; // resets for next iteration
        }
    }

    // Creating the new food and adding it to the menu
    Food new_food{name, price, ingredients};
    menu.add_food(new_food);

    std::cout << "Food " << name << " added successfully to the menu.\n\n";
}

// Function to handle a user placing an order
void handle_place_order(Menu &menu, Order &order)
{
    menu.print_menu();

    std::string choice{};
    while (true)
    {
        std::cout << "Enter the name of the food you want to order (hit enter to finish): ";
        std::cin.ignore(); // clears the input buffer
        std::getline(std::cin, choice);

        // Check for empty input
        if (choice.empty())
        {
            break;
        }
        else
        {
            // Find the ordered food and add it to the order
            const Food *food_to_order = menu.get_food_by_name(choice);
            order.order_food(*food_to_order);
            std::cout << "Food " << food_to_order->name << " added to order.\n";
        }
    }

    // If no food has been ordered
    if (order.size() == 0)
    {
        std::cout << "No food has been added to the order.\n\n";
    }
    // else confirm the successful order and display the total price
    else
    {
        std::cout << "Order placed successfully.\n";
        std::cout << "The total price of the order is: " << order.calculate_total() << " euros.\n\n";
    }
}
