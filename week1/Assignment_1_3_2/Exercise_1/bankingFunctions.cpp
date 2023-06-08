#include "bankingFunctions.h"
#include <iostream>

// Function to add money to the account
void addMoney(Customer &customer)
{
    std::cout << "Enter the money amount to be added to the bank account: ";
    double moneyAmount{};
    std::cin >> moneyAmount;
    customer.account.balance += moneyAmount;
    std::cout << moneyAmount << "e added successfully to the bank account!\n";
}

// Function to withdraw money from the account
void withdrawMoney(Customer &customer)
{
    std::cout << "Enter the money amount to be withdrawn from the bank account: ";
    double moneyAmount{};
    std::cin >> moneyAmount;

    if (moneyAmount > customer.account.balance)
    {
        std::cout << "Insufficient funds! You cannot withdraw " << moneyAmount << "e from the bank account because there are insufficient funds.\n";
    }
    else
    {
        customer.account.balance -= moneyAmount;
        std::cout << moneyAmount << "e withdrawn successfully!\n";
    }
}

// Function to display the account balance
void seeAccountBalance(const Customer &customer)
{
    std::cout << "Account balance: " << customer.account.balance << "e\n";
}
