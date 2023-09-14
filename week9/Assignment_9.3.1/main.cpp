// main.cpp
#include "include/string_adapter.h"

#include <iostream>

int main()
{
    // Exercise 1:
    std::cout << "\nExercise 1:\n\n";
    std::cout << "Enter a UTF-8 encoded string: ";
    std::string input_string{};
    std::getline(std::cin, input_string);

    // Standard string iterator used to print individual character
    std::cout << "\nUsing std::string::iterator:\n";
    for (auto it = input_string.begin(); it != input_string.end(); ++it)
    {
        std::cout << *it;
    }
    std::cout << '\n';

    // Exercise 3:
    std::cout << "\nExercise 3:\n";
    // Own UnicodeIterator used to print characters
    std::cout << "\nUsing own UnicodeIterator:\n";
    for (UnicodeIterator it(input_string.begin()); *it; ++it)
    {
        std::cout << static_cast<char>(*it);
    }
    std::cout << '\n';

    std::cout << "\nExercise 4 - 5:\n";
    // StringAdapter used to print size and individual codepoints as integers
    StringAdapter adapter(input_string);
    std::cout << "\nThe string has " << adapter.size() << " characters (codepoints).\n\n";

    std::cout << "String characters (individual codepoints) as integers:\n";
    for (char32_t codepoint : adapter)
    {
        std::cout << static_cast<uint32_t>(codepoint) << ' ';
    }
    std::cout << '\n';

    return 0;
}
