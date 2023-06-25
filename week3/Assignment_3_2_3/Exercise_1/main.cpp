// main.cpp
#include <iostream>
#include "include/reverse_string.h"

int main()
{
    std::cout << "Enter a string to be reversed: ";
    std::string str{};
    std::getline(std::cin, str);

    std::string reversed_str{reverse_string(str)};
    std::cout << "Reversed string: " << reversed_str << "\n";

    return 0;
}
