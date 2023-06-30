// order.cpp

#include "order.h"
#include <iostream>

// Function to add a food item to the order
void Order::order_food(const Food &food)
{
    foods.push_back(food);
}

// Function to print the order
void Order::print_order() const
{
    std::cout << "Order:\n";
    for (const auto &food : foods)
    {
        print_food(food);
        std::cout << "\n";
    }
}

// Function to calculate the total price of the order
double Order::calculate_total() const
{
    double total{0.0};
    for (const auto &food : foods)
    {
        total += food.price;
    }
    return total;
}

std::size_t Order::size() const
{
    return foods.size();
}
