#include <iostream>
#include <string>

// Function to reverse a string
std::string reverseString(std::string str)
{
    std::string::size_type n{str.length()};
    // Iterate over the first half of the string
    for (std::string::size_type i{0}; i < n / 2; ++i)
    {
        // Swap characters symmetrically from the beginning and end
        std::swap(str[i], str[n - i - 1]);
    }
    return str;
}

int main()
{
    std::string input{};
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    std::string reversed{reverseString(input)};
    std::cout << "Reversed string is: " << reversed << "\n";

    return 0;
}
