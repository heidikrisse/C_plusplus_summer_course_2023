#ifndef BANKING_FUNCTIONS_H
#define BANKING_FUNCTIONS_H

#include <iostream>
#include <string>
#include <map>
#include <fstream>

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
void addMoney(Customer &customer, int account_number);
void withdrawMoney(Customer &customer, int account_number);
void seeAccountBalance(const Customer &customer, int account_number);
void addCustomer(Bank &bank);
void addAccount(Bank &bank);
void deleteCustomer(Bank &bank);
void deleteAccount(Bank &bank);
void loginAccount(Bank &bank);
void saveAccountData(const Bank &bank);
void loadAccountData(Bank &bank);

#endif // BANKING_FUNCTIONS_H
