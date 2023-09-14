// transaction_unit_tests.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/finance_management_system.h"
#include <filesystem>

TEST_CASE("Adding and retrieving transactions")
{
    // FinanceManagementSystem object
    FinanceManagementSystem finance_management{};

    // Creating a transaction
    Transaction transaction1{1, "Income", 100.00};
    // Adding the transaction to the finance management system
    finance_management.add_transaction(transaction1);

    // Checking that there's exactly one transaction in the system
    CHECK(finance_management.get_transactions().size() == 1);
    // .. and it's ID == 1
    CHECK(finance_management.get_transactions()[0].id == 1);
}

TEST_CASE("Calculating total expenses")
{
    FinanceManagementSystem finance_management{};

    // Creating 2 transactions:
    Transaction transaction1{1, "Income", 100.00};
    Transaction transaction2{2, "Expense", 20.00};

    finance_management.add_transaction(transaction1);
    finance_management.add_transaction(transaction2);

    // Checking that the total expense is calculated correctly
    CHECK(finance_management.get_total_expense() == 20.00);

    // Creating 3. transaction and adding the transaction to the system:
    Transaction transaction3{3, "Expense", 20};
    finance_management.add_transaction(transaction3);

    CHECK(finance_management.get_total_expense() == 40.00);
}

TEST_CASE("Writing and reading transactions to/from a file")
{
    FinanceManagementSystem finance_management{};

    Transaction transaction1{1, "Income", 100.00};
    Transaction transaction2{2, "Expense", 20.00};

    finance_management.add_transaction(transaction1);
    finance_management.add_transaction(transaction2);

    std::string file_name{"test_transactions.txt"};
    finance_management.write_transactions_to_file(file_name);

    std::string directory_path{"../transactions_data"};
    std::string full_path{directory_path + "/" + file_name};

    // Checking that the file has been created
    CHECK(std::filesystem::exists(full_path));

    // Creating a new FinanceManagementSystem object
    FinanceManagementSystem finance_management_2{};
    finance_management_2.read_transactions_from_file(file_name);
    // Checking that two transactions have been read from the file
    CHECK(finance_management_2.get_transactions().size() == 2);
}
