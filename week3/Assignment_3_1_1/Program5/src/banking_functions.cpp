// banking_functions.cpp
#include "../include/banking_functions.h"
#include "../include/account_functions.h"
#include "../include/database.h"

// Case 1: Function to add a new customer
void add_customer(Bank &bank)
{
    std::cout << "Enter customer number: ";
    int customer_number{};
    std::cin >> customer_number;

    // Check if the customer number is already taken
    if (bank.customers.find(customer_number) != bank.customers.end())
    {
        std::cout << "The customer number " << customer_number << " is already taken. Please choose another available customer number.\n";
        return;
    }

    std::cin.ignore(); // Clear the newline character from the input buffer
    Customer new_customer;

    std::cout << "Enter customer name: ";
    std::getline(std::cin, new_customer.name);

    std::cout << "Enter customer address: ";
    std::getline(std::cin, new_customer.address);

    std::cout << "Enter customer phone number: ";
    std::getline(std::cin, new_customer.phone_number);

    bank.customers[customer_number] = new_customer;
    save_account_data(bank);
    std::cout << "Customer with number " << customer_number << " added successfully!\n";
}

// Case 2: Function to add a new account for a customer
void add_account(Bank &bank)
{
    std::cout << "Enter customer number: ";
    int customer_number{};
    std::cin >> customer_number;

    // Check if the customer exists
    if (bank.customers.find(customer_number) == bank.customers.end())
    {
        std::cout << "Customer number " << customer_number << " does not exist. Please add the customer first.\n";
        return;
    }

    std::cout << "Enter account number: ";
    int account_number{};
    std::cin >> account_number;

    // Check if the account number is already taken
    if (bank.customers[customer_number].accounts.find(account_number) != bank.customers[customer_number].accounts.end())
    {
        std::cout << "This account number is already taken. Please choose another available account number.\n";
        return;
    }

    bank.customers[customer_number].accounts[account_number] = Account();

    save_account_data(bank);
    std::cout << "Account with number " << account_number << " created successfully for customer " << customer_number << "!\n";
}

// Case 3: Function to log in to an account
void login_account(Bank &bank)
{
    std::cout << "Enter customer number: ";
    int customer_number{};
    std::cin >> customer_number;

    // Check if the customer exists
    if (bank.customers.find(customer_number) == bank.customers.end())
    {
        std::cout << "Customer number " << customer_number << " does not exist.\n";
        return;
    }

    std::cout << "Enter account number: ";
    int account_number{};
    std::cin >> account_number;

    // Check if the account exists
    if (bank.customers[customer_number].accounts.find(account_number) == bank.customers[customer_number].accounts.end())
    {
        std::cout << "Account number " << account_number << " does not exist.\n";
        return;
    }

    // Account menu loop
    while (true)
    {
        std::cout << "\nAccount menu:\n";
        std::cout << "1. Add money to the account\n";
        std::cout << "2. Withdraw money from the account\n";
        std::cout << "3. See account balance\n";
        std::cout << "4. Log out from the account\n";
        std::cout << "Enter your choice: ";
        int choice{};
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            add_money(bank.customers[customer_number], account_number);
            break;
        case 2:
            withdraw_money(bank.customers[customer_number], account_number);
            break;
        case 3:
            see_account_balance(bank.customers[customer_number], account_number);
            break;
        case 4:
            std::cout << "\nLogging out from the account..\n";
            return;
        default:
            std::cout << "\nInvalid choice. Please try again.\n";
        }
    }
}

// Case 4: Function to delete a customer
void delete_customer(Bank &bank)
{
    std::cout << "Enter customer number: ";
    int customer_number{};
    std::cin >> customer_number;

    // Check if the customer exists
    if (bank.customers.find(customer_number) == bank.customers.end())
    {
        std::cout << "Customer number " << customer_number << " does not exist.\n";
        return;
    }

    bank.customers.erase(customer_number);
    save_account_data(bank);
    std::cout << "Customer with number " << customer_number << " deleted successfully!\n";
}

// Case 5: Function to delete an account
void delete_account(Bank &bank)
{
    std::cout << "Enter customer number: ";
    int customer_number{};
    std::cin >> customer_number;

    // Check if the customer exists
    if (bank.customers.find(customer_number) == bank.customers.end())
    {
        std::cout << "Customer number " << customer_number << " does not exist.\n";
        return;
    }

    std::cout << "Enter account number: ";
    int account_number{};
    std::cin >> account_number;

    // Check if the account exists
    if (bank.customers[customer_number].accounts.find(account_number) == bank.customers[customer_number].accounts.end())
    {
        std::cout << "Account number " << account_number << " does not exist.\n";
        return;
    }

    bank.customers[customer_number].accounts.erase(account_number);
    save_account_data(bank);
    std::cout << "Account with number " << account_number << " deleted successfully!\n";
}
