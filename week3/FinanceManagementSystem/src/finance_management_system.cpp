// finance_management_system.cpp
#include "../include/finance_management_system.h"
#include <filesystem>
#include <fstream>
#include <stdexcept> // for std::runtime_error

// Default constructor for the FinanceManagementSystem class
FinanceManagementSystem::FinanceManagementSystem() {}

// Function to add a new transaction to the finance management system
void FinanceManagementSystem::add_transaction(const Transaction &transaction)
{
    // Adding the transaction to the transactions vector
    transactions_.push_back(transaction);
}

// Function to calculate and return the total expense from all transactions
std::vector<Transaction> FinanceManagementSystem::get_transactions() const
{
    // Returns a copy of the transactions vecto
    return transactions_;
}

double FinanceManagementSystem::get_total_expense() const
{
    double total_expense{};
    // Loop through each transaction
    for (const auto &transaction : transactions_)
    {
        // If the transaction is an expense
        if (transaction.type == "Expense")
        {
            // Add the transaction amount to the total expense
            total_expense += transaction.amount;
        }
    }
    return total_expense;
}

// Function to write all transactions to a file
void FinanceManagementSystem::write_transactions_to_file(const std::string &file_name)
{
    // Directory path to write the file to
    std::string directory_path{"../transactions_data"};
    // Create the directory if it doesn't exist
    std::filesystem::create_directories(directory_path);
    // Full path to the file
    std::string full_path{directory_path + "/" + file_name};

    // Open the file for writing
    std::ofstream output_file(full_path);

    // If couldn open, throw an exception
    if (!output_file.is_open())
    {
        throw std::runtime_error("Could not open file to write");
    }

    for (const Transaction &transaction : transactions_)
    {
        output_file << transaction.id << " "
                    << transaction.type << " "
                    << transaction.amount << "\n";
    }

    output_file.close();
}

// Function to read transactions from a file and load them into the system
void FinanceManagementSystem::read_transactions_from_file(const std::string &file_name)
{
    std::string directory_path{"../transactions_data"};
    std::string full_path{directory_path + "/" + file_name};

    // Open the file for reading
    std::ifstream input_file(full_path);

    if (!input_file.is_open())
    {
        throw std::runtime_error("Could not open file to read");
    }

    // Clear any existing transactions
    transactions_.clear();

    // Create a temporary transaction object to store data from the file
    Transaction transaction{};
    // While there is more data to read from input_file, store it to the struct's transaction.id, transaction.type and transaction.amount
    while (input_file >> transaction.id >> transaction.type >> transaction.amount)
    {
        // Add the transaction to the system
        transactions_.push_back(transaction);
    }

    input_file.close();
}
