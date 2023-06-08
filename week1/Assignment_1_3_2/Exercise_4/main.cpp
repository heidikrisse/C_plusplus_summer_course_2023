#include "bankingFunctions.h"
#include <iostream>

// Function to print the program header
void printHeader()
{
    std::cout << "*****************************\n";
    std::cout << "*                           *\n";
    std::cout << "*    BANKING APPLICATION    *\n";
    std::cout << "*                           *\n";
    std::cout << "*****************************\n\n";
}

int main()
{
    printHeader();

    std::map<int, Customer> customers; // Map to store multiple customers

    loadAccountData(customers);

    // Main menu loop
    while (true)
    {
        std::cout << "\nBanking application menu:\n";
        std::cout << "1. Add a new customer\n";
        std::cout << "2. Add a new account\n";
        std::cout << "3. Log in to account\n";
        std::cout << "4. Save account data\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter your choice: ";
        int choice{};
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            addCustomer(customers);
            break;
        case 2:
            addAccount(customers);
            break;
        case 3:
            loginAccount(customers);
            break;
        case 4:
            saveAccountData(customers);
            break;
        case 5:
            std::cout << "Exiting the banking application..\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
