#include <iostream>
#include "include/exercise1.h"
#include "include/exercise2.h"
#include "include/exercise3.h"

int main()
{
    // Create two instances of ValueType with int type
    ValueType<int> value1{1};
    ValueType<int> value2{2};

    std::cout << "Value1: ";
    value1.print_value();
    std::cout << "Value2: ";
    value2.print_value();
    std::cout << '\n';

    // Compare value1 and value2 using overloaded operators
    if (value1 == value2)
    {
        std::cout << "Value1 is equal to value2.\n";
    }

    if (value1 != value2)
    {
        std::cout << "Value1 is not equal to value2.\n";
    }

    if (value1 < value2)
    {
        std::cout << "Value1 is less than value2.\n";
    }

    if (value1 > value2)
    {
        std::cout << "Value1 is greater than value2.\n ";
    }

    if (value1 <= value2)
    {
        std::cout << "Value1 is less than or equal to value2.\n";
    }

    if (value1 >= value2)
    {
        std::cout << "Value1 is greater than or equal to value2.\n";
    }

    // Testing MyType which inherits both ValueType and TypePrinter functionality
    MyType<int> my_type(2);
    my_type.print_type(); // MyType<int>

    return 0;
}
