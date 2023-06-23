// main.cpp
#include "include/finance_management_system.h"
#include "include/transaction.h"
#include <iostream>

int main()
{
    FinanceManagementSystem finance_management{};

    /* // Testing code:
    Transaction transaction1{1, "Income", 100.00};
    Transaction transaction2{2, "Expense", 20.00};
    Transaction transaction3{3, "Expense", 20.00};

    finance_management.add_transaction(transaction1);
    finance_management.add_transaction(transaction2);

    std::cout << "Total expenses: " << finance_management.get_total_expense() << "\n";

    std::string file_name{"transactions.txt"};
    finance_management.write_transactions_to_file(file_name);
    */

    int choice{0};
    while (choice != 3)
    {
        std::cout << "***** FINANCE MANAGEMENT SYSTEM *****\n\n";

        std::cout << "Please choose an option:\n\n"
                  << "1. Add a transaction\n"
                  << "2. View total expenses\n"
                  << "3. Quit\n";
        std::cin >> choice;

        if (choice == 1)
        {
            int id{};
            std::string type{};
            double amount{};
            std::cout << "Enter transaction id: ";
            std::cin >> id;
            std::cout << "Enter transaction type (Income/Expense): ";
            std::cin >> type;
            std::cout << "Enter transaction amount: ";
            std::cin >> amount;

            // Creating a new transaction
            Transaction new_transaction{id, type, amount};
            // Adding the transaction to the finance management system
            finance_management.add_transaction(new_transaction);
            std::string file_name{"transactions.txt"};
            // Writing the transaction to the file
            finance_management.write_transactions_to_file(file_name);
        }
        else if (choice == 2)
        {
            std::cout << "Total expenses: " << finance_management.get_total_expense() << "\n";
        }
        else
        {
            std::cout << "Invalid choice! Please choose alternatives 1-3.\n";
        }
    }

    return 0;
}
