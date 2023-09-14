// bank_unit_tests.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/banking_functions.h"
#include "../include/account_functions.h"
#include "../include/database.h"

#include <iostream>
#include <filesystem>

// Helper function to create test bank
Bank create_test_bank()
{
    Bank bank{};
    Customer customer1{"Aku Ankka", "Paratiisitie 13", "1234567890"};
    customer1.accounts[101] = {500.00};
    Customer customer2{"Super Man", "Clinton Street 344", "0987654321"};
    customer2.accounts[201] = {1000.00};

    bank.customers[1] = customer1;
    bank.customers[2] = customer2;

    return bank;
}

TEST_CASE("Unit Test 1: add_customer")
{
    std::cout << "Unit Test 1: add_customer\n\n";

    Bank bank = create_test_bank();

    std::cout << "To perform the test:\nYou should enter customer number: 3\n";
    // User Interface: Add a customer with customer number = 3 to test this
    add_customer(bank);

    CHECK(bank.customers.count(3) == 1); // Check if customer with customer number 3 exists

    std::cout << '\n';
}

TEST_CASE("Unit Test 2: add_account")
{
    std::cout << "Unit Test 2: add_account\n\n";

    Bank bank = create_test_bank();
    std::cout << "To perform the test:\nYou should enter customer number: 1\nYou should enter account number: 301\n";
    add_account(bank);

    CHECK(bank.customers[1].accounts.count(301) == 1); // Check if account with account number 301 exists for customer with customer number 1

    std::cout << '\n';
}

TEST_CASE("Unit Test 3: delete_account")
{
    std::cout << "Unit Test 3: delete_account\n\n";
    Bank bank = create_test_bank();

    std::cout << "To perform the test:\nYou should enter customer number: 1\nYou should enter account number: 101\n";
    // Should delete account of customer with customer number 1 and with account number 101
    delete_account(bank);

    CHECK(bank.customers[1].accounts.count(101) == 0); // Check if account with account number 101 does not exist for customer with customer number 1

    std::cout << '\n';
}

TEST_CASE("Unit Test 4: delete_customer")
{
    std::cout << "Unit Test 4: delete_customer\n\n";
    Bank bank = create_test_bank();

    std::cout << "To perform the test:\nYou should enter customer number: 1\n";
    // Should delete customer with customer number 1
    delete_customer(bank);

    CHECK(bank.customers.count(1) == 0); // Check if customer with ID 1 does not exist

    std::cout << '\n';
}

TEST_CASE("Unit Test 5: add_money")
{
    std::cout << "Unit Test 5: Test add_money\n\n";
    Bank bank = create_test_bank();

    std::cout << "To perform the test:\nYou should enter: 500";
    // Should add 500 to account number 101 of the customer with customer number 1
    add_money(bank.customers[1], 101);

    CHECK(bank.customers[1].accounts[101].balance == 1000.00); // Check if new balance is 1000

    std::cout << '\n';
}

TEST_CASE("Unit Test 6: withdraw_money")
{
    std::cout << "Unit Test 6: Test withdraw_money\n\n";
    Bank bank = create_test_bank();
    std::cout << "To perform the test:\nYou should withdraw: 200";
    // Should withdraw 200 from account number 101 of customer with customer number 1
    withdraw_money(bank.customers[1], 101);

    CHECK(bank.customers[1].accounts[101].balance == 300.00); // Check if new balance is 300
}

TEST_CASE("Unit Test 7: Test save_account_data")
{
    std::cout << "Unit Test 7: Test save_account_data\n\n";

    Bank bank = create_test_bank();

    save_account_data(bank);

    // Check if file exists after saving data
    CHECK(std::filesystem::exists("../data/account_data.txt"));

    std::cout << '\n';
}

TEST_CASE("Unit Test 8: Test load_account_data")
{
    std::cout << "Unit Test 8: Test load_account_data\n\n";

    Bank bank1 = create_test_bank();
    save_account_data(bank1);

    // Load data into a new bank object
    Bank bank2;
    load_account_data(bank2);

    // Check that the data was correctly loaded when comparing with the original bank
    CHECK(bank1.customers.size() == bank2.customers.size());
    for (const auto &[customer_number, customer] : bank1.customers)
    {
        CHECK(bank2.customers.count(customer_number) == 1);
        CHECK(bank2.customers[customer_number].name == customer.name);
        CHECK(bank2.customers[customer_number].address == customer.address);
        CHECK(bank2.customers[customer_number].phone_number == customer.phone_number);
        CHECK(bank2.customers[customer_number].accounts.size() == customer.accounts.size());

        for (const auto &[account_number, account] : customer.accounts)
        {
            CHECK(bank2.customers[customer_number].accounts.count(account_number) == 1);
            CHECK(bank2.customers[customer_number].accounts[account_number].balance == account.balance);
        }
    }

    std::cout << '\n';
}
