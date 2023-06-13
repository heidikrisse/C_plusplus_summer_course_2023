// calculator_utils.cpp
#include "../includes/calculator_utils.h"

#include <cassert>
#include <string>

// Definitions of basic operation functions
double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    assert(b != 0 && "Error: Can not divide by zero.");
    return a / b;
}

// Function to encrypt a string using Caesar's Cipher
std::string encrypt_caesar_cipher(const std::string &text, int shift)
{
    // Initialize an empty string for the encrypted result
    std::string result{};

    // Iterate over each character in the input text
    for (char c : text)
    {
        // If a letter (alpha)
        if (std::isalpha(c))
        {
            /* Determine the base ASCII value ('A' for upper case, 'a'
             * for lower case).
             * If 'c' is uppercase, the base is set to A, otherwise the base
             * is set to 'a'. */
            char base{std::isupper(c) ? 'A' : 'a'};
            /* Shift the character, ensuring that the shifted character
             * remains within the A-Z or a-z range
             * The modulo (%) ensures the new ASCII value wraps aroung within
             * the alphabetic range */
            c = static_cast<char>(base + (c - base + shift) % 26);
        }
        // Append the (possibly shifted) character to the result
        result.push_back(c);
    }

    return result;
}

// Function to decrypt a string encrypted using Caesar's Cipher
std::string decrypt_caesar_cipher(const std::string &text, int shift)
{
    /* To decrypt we "encrypt" in reverse by using the opposite shift
     * (26 - original shift)
     * 26 letters in English alphabet so if you shift a letter by 26
     * places, you end up with the original letter itself
     */
    return encrypt_caesar_cipher(text, 26 - shift);
}
