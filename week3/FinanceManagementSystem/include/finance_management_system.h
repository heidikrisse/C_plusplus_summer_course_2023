#ifndef FINANCE_MANAGEMENT_SYSTEM_H
#define FINANCE_MANAGEMENT_SYSTEM_H

#include "transaction.h"
#include <vector>

// Definition of the FinanceManagementSystem class
class FinanceManagementSystem
{
public:
    // Default constructor declaration
    FinanceManagementSystem();
    // Function to add a transaction to the finance management system
    void add_transaction(const Transaction &transaction);
    // Function to get transactions from the finance management system and return a copy of them as a vector
    std::vector<Transaction> get_transactions() const;
    // Function to calculate the total expense
    double get_total_expense() const;
    // Function to write transactions to a file
    void write_transactions_to_file(const std::string &file_name);
    // Function to read transactions from a file and add them to the transactions vector
    void read_transactions_from_file(const std::string &file_name);

private:
    // A vector to store Transaction objects
    std::vector<Transaction> transactions_;
};

#endif
