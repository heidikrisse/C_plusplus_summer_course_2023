#include "include/banking_functions.h"
#include <iostream>

// Function to print the program header
void print_header()
{
    std::cout << "*****************************\n";
    std::cout << "*                           *\n";
    std::cout << "*    BANKING APPLICATION    *\n";
    std::cout << "*                           *\n";
    std::cout << "*****************************\n\n";
}

int main()
{
    try
    {
        print_header();

        Bank bank{}; // Bank instance

        load_account_data(bank);

        // Main menu loop
        while (true)
        {
            std::cout << "\nBanking application menu:\n";
            std::cout << "1. Add a new customer\n";
            std::cout << "2. Add a new account\n";
            std::cout << "3. Log in to account\n";
            std::cout << "4. Save account data\n";
            std::cout << "5. Delete a customer\n";
            std::cout << "6. Delete an account\n";
            std::cout << "7. Quit\n";
            std::cout << "Enter your choice: ";
            int choice{};
            std::cin >> choice;

            switch (choice)
            {
            case 1:
                add_customer(bank);
                break;
            case 2:
                add_account(bank);
                break;
            case 3:
                login_account(bank);
                break;
            case 4:
                save_account_data(bank);
                break;
            case 5:
                delete_customer(bank);
                break;
            case 6:
                delete_account(bank);
                break;
            case 7:
                std::cout << "\nExiting the banking application..\n";
                return 0;
            default:
                std::cout << "\nInvalid choice. Please try again.\n";
            }
        }
    }

    catch (const std::runtime_error &e)
    {
        std::cerr << e.what();
    }

    return 0;
}
