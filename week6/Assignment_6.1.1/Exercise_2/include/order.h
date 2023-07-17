// order.h
#ifndef ORDER_H
#define ORDER_H

#include <iostream>

enum class Status
{
    ORDERED,
    PROCESSING,
    SHIPPED,
    DELIVERED,
};

class Order
{
private:
    Status status;

public:
    Order();

    void print_status();
    void advance_status();
};

#endif
