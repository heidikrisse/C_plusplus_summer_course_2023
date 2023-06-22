// main.cpp
#include "include/string_utils.h"
#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter a string: ";
    std::string input{};
    std::getline(std::cin, input);

    std::cout << "Reverse of '" << input << "' is '" << reverse_string(input) << "'\n";
    std::cout << "Uppercase of '" << input << "' is '" << to_uppercase(input) << "'\n";
    std::cout << "Lowercase of '" << input << "' is '" << to_lowercase(input) << "'\n";

    if (is_palindrome(input))
    {
        std::cout << "'" << input << "' is a palindrome.\n";
    }
    else
    {
        std::cout << "'" << input << "' is not a palindrome.\n";
    }

    return 0;
}
