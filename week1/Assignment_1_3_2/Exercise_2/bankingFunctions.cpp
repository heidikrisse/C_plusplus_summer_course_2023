#include "bankingFunctions.h"

// Function to add money to an account
void addMoney(Customer &customer, int account_number)
{
    std::cout << "Enter the money amount to be added to account " << account_number << ": ";
    double moneyAmount{};
    std::cin >> moneyAmount;
    customer.accounts[account_number].balance += moneyAmount;
    std::cout << moneyAmount << "e added successfully to the bank account " << account_number << ".\n";
}

// Function to withdraw money from an account
void withdrawMoney(Customer &customer, int account_number)
{
    std::cout << "Enter the money amount to be withdrawn from account " << account_number << ": ";
    double moneyAmount{};
    std::cin >> moneyAmount;

    if (moneyAmount > customer.accounts[account_number].balance)
    {
        std::cout << "Insufficient funds! You cannot withdraw " << moneyAmount << "e from the bank account because there are insufficient funds.\n";
    }
    else
    {
        customer.accounts[account_number].balance -= moneyAmount;
        std::cout << moneyAmount << "e withdrawn successfully!\n";
    }
}

// Function to display the account balance
void seeAccountBalance(const Customer &customer, int account_number)
{
    std::cout << "Account " << account_number << " balance: " << customer.accounts.at(account_number).balance << "e\n";
}
