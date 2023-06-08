#include "bankingFunctions.h"
#include <iostream>
#include <string>

int main()
{
    // Create a customer object
    Customer customer;

    // Get customer information from the user
    std::cout << "Enter customer name: ";
    std::getline(std::cin, customer.name);
    std::cout << "Enter customer address: ";
    std::getline(std::cin, customer.address);
    std::cout << "Enter customer phone number: ";
    std::getline(std::cin, customer.phone_number);

    // Menu loop
    while (true)
    {
        std::cout << "\nBanking application menu:\n";
        std::cout << "1. Add money\n";
        std::cout << "2. Withdraw money\n";
        std::cout << "3. See account balance\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice: ";
        int choice{};
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            addMoney(customer);
            break;
        case 2:
            withdrawMoney(customer);
            break;
        case 3:
            seeAccountBalance(customer);
            break;
        case 4:
            std::cout << "Exiting the banking application..\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
