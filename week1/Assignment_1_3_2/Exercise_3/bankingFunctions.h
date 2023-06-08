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

// Function to add money to an account
void addMoney(Customer &customer, int account_number);

// Function to withdraw money from an account
void withdrawMoney(Customer &customer, int account_number);

// Function to display the account balance
void seeAccountBalance(const Customer &customer, int account_number);

// Function to add a new customer
void addCustomer(std::map<int, Customer> &customers);

// Function to add a new account for a customer
void addAccount(std::map<int, Customer> &customers);

// Function to log in to a customer's account
void loginAccount(std::map<int, Customer> &customers);

#endif // BANKING_FUNCTIONS_H
