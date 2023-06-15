// printer.cpp
#include <iostream>

#include "../include/printer.h"

// Print the contents of a vector of strings
void print_file_content(const std::vector<std::string> &content)
{
    // Iterate over the vector and print each string
    for (const auto &line : content)
    {
        std::cout << line << '\n';
    }
}
