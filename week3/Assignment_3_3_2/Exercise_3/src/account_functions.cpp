// account_functions.cpp
#include "../include/account_functions.h"

// Case 1: Function to add money to an account
void add_money(Customer &customer, int account_number)
{
    std::cout << "\nEnter the money amount to be added to account " << account_number << ": ";
    double money_amount{};
    if (!(std::cin >> money_amount))
    {
        throw std::runtime_error("Invalid input, expecting a number for money amount\n");
    }
    customer.accounts[account_number].balance += money_amount;
    std::cout << money_amount << "e added successfully to the bank account " << account_number << ".\n";
}

// Case 2: Function to withdraw money from an account
void withdraw_money(Customer &customer, int account_number)
{
    std::cout << "\nEnter the money amount to be withdrawn from account " << account_number << ": ";
    double money_amount{};
    if (!(std::cin >> money_amount))
    {
        throw std::runtime_error("Invalid input, expecting a number for money amount\n");
    }

    if (money_amount > customer.accounts[account_number].balance)
    {
        throw std::runtime_error("Insufficient funds! You cannot withdraw " + std::to_string(money_amount) + "e from the bank account because there are insufficient funds.\n");
    }
    else
    {
        customer.accounts[account_number].balance -= money_amount;
        std::cout << money_amount << "e withdrawn successfully!\n";
    }
}

// Case 3: Function to see the account balance
void see_account_balance(const Customer &customer, int account_number)
{
    std::cout << "Account " << account_number << " balance: " << customer.accounts.at(account_number).balance << "e\n";
}
