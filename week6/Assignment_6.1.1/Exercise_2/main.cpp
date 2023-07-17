#include "include/order.h"

int main()
{
    Order order;
    order.print_status();

    order.advance_status();
    order.print_status();

    order.advance_status();
    order.print_status();

    order.advance_status();
    order.print_status();

    // order.advance_status();
    // order.print_status();

    return 0;
}
