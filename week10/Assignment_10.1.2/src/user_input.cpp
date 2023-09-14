// user_input.cpp
#include "../include/user_input.h"
#include "../include/log.h"

#include <string>
#include <iostream>

// Function to read user input and interact with the log
void read_user_input()
{
    std::string user_input{};
    do
    {
        std::cout << "Enter a message to the log (or enter 'log' to print the log or 'quit' to exit): ";
        std::getline(std::cin, user_input);

        if (user_input == "log")
        {
            print_log();
        }
        // Add any other input, except "quit", to the log.
        else
        {
            add_to_log(user_input);
        }
    } while (user_input != "quit");

    // Set the global 'is_running' to false to stop other threads
    is_running.store(false);
}
