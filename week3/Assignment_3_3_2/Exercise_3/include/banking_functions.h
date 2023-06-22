#ifndef BANKING_FUNCTIONS_H
#define BANKING_FUNCTIONS_H

#include <iostream>
#include <string>
#include <map>

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
    std::map<int, Account> accounts{}; // Map to store multiple accounts
};

// Structure to store bank information
struct Bank
{
    std::map<int, Customer> customers{}; // Map to store multiple customers
};

// Function declarations
void add_customer(Bank &bank);
void add_account(Bank &bank);
void delete_customer(Bank &bank);
void delete_account(Bank &bank);
void login_account(Bank &bank);

#endif // BANKING_FUNCTIONS_H
