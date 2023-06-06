#include <iostream>
#include <string>
#include <cctype>

// Function to check if the password is strong
bool isStrongPassword(const std::string &password)
{
    if (password.length() < 8)
        return false;

    bool hasUppercase{false}, hasLowercase{false}, hasDigit{false}, hasSpecialCharacter{false};
    for (const auto &ch : password)
    {
        if (std::isupper(ch))
            hasUppercase = true;
        else if (std::islower(ch))
            hasLowercase = true;
        else if (std::isdigit(ch))
            hasDigit = true;
        else if (std::ispunct(ch))
            hasSpecialCharacter = true;
    }

    // Return true only if the password has at least one uppercase letter, one lowercase letter,
    // one digit, and one special character
    return hasUppercase && hasLowercase && hasDigit && hasSpecialCharacter;
}

int main()
{
    std::string password{};
    std::cout << "Enter a password: ";
    std::getline(std::cin, password);

    if (isStrongPassword(password))
        std::cout << "The password '" << password << "' is strong.\n";
    else
        std::cout << "The password '" << password << "' is not strong.\n";

    return 0;
}
