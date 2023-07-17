#include "../include/order.h"

Order::Order() : status(Status::ORDERED) {}

void Order::print_status()
{
    std::cout << "Order status: ";
    switch (status)
    {
    case Status::ORDERED:
        std::cout << "Ordered\n";
        break;
    case Status::PROCESSING:
        std::cout << "Processing\n";
        break;
    case Status::SHIPPED:
        std::cout << "Shipped\n";
        break;
    case Status::DELIVERED:
        std::cout << "Delivered\n";
        break;
    }
}

void Order::advance_status()
{
    switch (status)
    {
    case Status::ORDERED:
        status = Status::PROCESSING;
        break;
    case Status::PROCESSING:
        status = Status::SHIPPED;
        break;
    case Status::SHIPPED:
        status = Status::DELIVERED;
        break;
    case Status::DELIVERED:
        std::cout << "Order has already been delivered.\n";
        break;
    }
}
