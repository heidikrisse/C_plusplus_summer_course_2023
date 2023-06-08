#include <iostream>
#include <string>
#include <cassert>
#include <cctype>

// Function to capitalize the first letter of each word in a string
std::string capitalize_string(std::string inputString)
{
    bool isNewWord{true}; // boolean variable to detect the start of a new word
    for (auto &character : inputString)
    {
        if (std::isspace(character))
        {
            isNewWord = true;
        }
        else
        {
            if (isNewWord)
            { // If it's the start of a new word, capitalize the letter
                character = std::toupper(character);
                isNewWord = false;
            }
            else
            {
                character = std::tolower(character); // else convert it to lowercase
            }
        }
    }
    return inputString;
}

int main()
{
    // Test our capitalize function with assertions
    assert(capitalize_string("the string challenge") == "The String Challenge");
    std::cout << "Test 1 passed\n";
    assert(capitalize_string("THIS IS an ExamplE, should wORk!") == "This Is An Example, Should Work!");
    std::cout << "Test 2 passed\n";

    return 0;
}
