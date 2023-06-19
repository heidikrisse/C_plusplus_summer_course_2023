#include <iostream>
#include <vector>
#include "../include/names_input.h"

std::vector<std::string> get_names(const std::string &prompt)
{
    std::cout << prompt;
    std::vector<std::string> names;
    std::string name;

    do
    {
        std::cin >> name;
        if (name != "e" && name != "E")
        {
            names.push_back(name);
        }
    } while (name != "e" && name != "E");

    return names;
}

int get_number(const std::string &prompt)
{
    std::cout << prompt;
    int number{};
    std::cin >> number;

    return number;
}
