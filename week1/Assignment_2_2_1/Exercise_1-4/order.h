// order.h

#ifndef ORDER_H
#define ORDER_H

#include "food.h"
#include <vector>

class Order
{
public:
    // Function to add a food item to the order
    void order_food(const Food &food);
    // Function to print the order
    void print_order() const;
    // Function to calculate the total price of the order
    double calculate_total() const;
    // Function to return the number of food items in the order
    std::size_t size() const;

private:
    // Vector to store the food items in the order
    std::vector<Food> foods{};
};

#endif
