/* main.cpp */
#include <iostream>
#include "include/data_processor.h"

int main()
{
    try
    {
        // processing integer
        int number{get_number("Enter an integer: ")};
        process_data(number);

        // processing string
        std::string str{get_string("Enter a string: ")};
        process_data(str);
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
