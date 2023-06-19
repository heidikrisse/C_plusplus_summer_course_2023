/* main.cpp
 *
 * Program to print names by user index */
#include <iostream>
#include <vector>
#include "include/names_input.h"
#include "include/name_selector.h"

int main()
{
    std::vector<std::string> names{get_names("Enter names (enter 'e' when done): ")};

    try
    {
        int user_index{get_number("Enter the user index of the name you want to print: ")};
        std::string name{select_name(names, user_index)};
        std::cout << "Selected name: " << name << "\n";
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
