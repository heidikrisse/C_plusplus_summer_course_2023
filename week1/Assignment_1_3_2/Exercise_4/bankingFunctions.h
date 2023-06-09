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

// Function declarations
void addMoney(Customer &customer, int account_number);
void withdrawMoney(Customer &customer, int account_number);
void seeAccountBalance(const Customer &customer, int account_number);
void addCustomer(std::map<int, Customer> &customers);
void addAccount(std::map<int, Customer> &customers);
void deleteCustomer(std::map<int, Customer> &customers);
void deleteAccount(std::map<int, Customer> &customers);
void loginAccount(std::map<int, Customer> &customers);
void saveAccountData(const std::map<int, Customer> &customers);
void loadAccountData(std::map<int, Customer> &customers);

#endif // BANKING_FUNCTIONS_H
