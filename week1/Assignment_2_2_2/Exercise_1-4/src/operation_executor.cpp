// operation_executor.cpp
#include "../includes/operation_executor.h"
#include "../includes/argument_parser.h"

#include <iostream>

// Function to execute an operation based on parsed command line arguments
void execute_operation(cxxopts::ParseResult &result)
{
    if (result.count("help"))
    {
        std::cout << get_options().help() << "\n";
    }
    else if (result.count("add"))
    {
        // create a reference 'list' and automatically deduce the type
        auto &list{result["add"].as<std::vector<double>>()};
        std::cout << "Result: " << add(list[0], list[1]) << "\n";
    }
    else if (result.count("subtract"))
    {
        auto &list{result["subtract"].as<std::vector<double>>()};
        std::cout << "Result: " << subtract(list[0], list[1]) << "\n";
    }
    else if (result.count("multiply"))
    {
        auto &list{result["multiply"].as<std::vector<double>>()};
        std::cout << "Result: " << multiply(list[0], list[1]) << "\n";
    }
    else if (result.count("divide"))
    {
        auto &list{result["divide"].as<std::vector<double>>()};
        std::cout << "Result: " << divide(list[0], list[1]) << "\n";
    }
    else if (result.count("encrypt"))
    {
        auto &list{result["encrypt"].as<std::vector<std::string>>()};
        std::cout << "Result: " << encrypt_caesar_cipher(list[0], std::stoi(list[1])) << "\n";
    }
    else if (result.count("decrypt"))
    {
        auto &list{result["decrypt"].as<std::vector<std::string>>()};
        std::cout << "Result: " << decrypt_caesar_cipher(list[0], std::stoi(list[1])) << "\n";
    }
    // If none of the specified options were found, print the help text
    else
    {
        std::cout << get_options().help() << "\n";
    }
}
