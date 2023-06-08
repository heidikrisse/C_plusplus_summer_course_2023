#ifndef BANKING_FUNCTIONS_H
#define BANKING_FUNCTIONS_H

#include <string>

// Structure to store account information
struct Account
{
    double balance{};
};

// Structure to store customer information
struct Customer
{
    std::string name{};
    std::string address{};
    std::string phone_number{};
    Account account{};
};

// Function to add money to the account
void addMoney(Customer &customer);
// Function to withdraw money from the account
void withdrawMoney(Customer &customer);
// Function to display the account balance
void seeAccountBalance(const Customer &customer);

#endif // BANKING_FUNCTIONS_H
