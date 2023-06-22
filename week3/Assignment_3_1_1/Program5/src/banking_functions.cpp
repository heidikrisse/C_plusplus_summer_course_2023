// banking_functions.cpp
#include "../include/banking_functions.h"
#include "../include/account_functions.h"

// Case 1: Function to add a new customer
void add_customer(Bank &bank)
{
    std::cout << "Enter customer number: ";
    int customer_number{};
    std::cin >> customer_number;

    // Check if the customer number is already taken
    if (bank.customers.find(customer_number) != bank.customers.end())
    {
        std::cout << "The customer number " << customer_number << " is already taken. Please choose another available customer number.\n";
        return;
    }

    std::cin.ignore(); // Clear the newline character from the input buffer
    Customer new_customer;

    std::cout << "Enter customer name: ";
    std::getline(std::cin, new_customer.name);

    std::cout << "Enter customer address: ";
    std::getline(std::cin, new_customer.address);

    std::cout << "Enter customer phone number: ";
    std::getline(std::cin, new_customer.phone_number);

    bank.customers[customer_number] = new_customer;

    std::cout << "Customer with number " << customer_number << " added successfully!\n";
}

// Case 2: Function to add a new account for a customer
void add_account(Bank &bank)
{
    std::cout << "Enter customer number: ";
    int customer_number{};
    std::cin >> customer_number;

    // Check if the customer exists
    if (bank.customers.find(customer_number) == bank.customers.end())
    {
        std::cout << "Customer number " << customer_number << " does not exist. Please add the customer first.\n";
        return;
    }

    std::cout << "Enter account number: ";
    int account_number{};
    std::cin >> account_number;

    // Check if the account number is already taken
    if (bank.customers[customer_number].accounts.find(account_number) != bank.customers[customer_number].accounts.end())
    {
        std::cout << "This account number is already taken. Please choose another available account number.\n";
        return;
    }

    bank.customers[customer_number].accounts[account_number] = Account();

    std::cout << "Account with number " << account_number << " created successfully for customer " << customer_number << "!\n";
}

// Case 3: Function to log in to an account
void login_account(Bank &bank)
{
    std::cout << "Enter customer number: ";
    int customer_number{};
    std::cin >> customer_number;

    // Check if the customer exists
    if (bank.customers.find(customer_number) == bank.customers.end())
    {
        std::cout << "Customer number " << customer_number << " does not exist.\n";
        return;
    }

    std::cout << "Enter account number: ";
    int account_number{};
    std::cin >> account_number;

    // Check if the account exists
    if (bank.customers[customer_number].accounts.find(account_number) == bank.customers[customer_number].accounts.end())
    {
        std::cout << "Account number " << account_number << " does not exist.\n";
        return;
    }

    // Account menu loop
    while (true)
    {
        std::cout << "\nAccount menu:\n";
        std::cout << "1. Add money to the account\n";
        std::cout << "2. Withdraw money from the account\n";
        std::cout << "3. See account balance\n";
        std::cout << "4. Log out from the account\n";
        std::cout << "Enter your choice: ";
        int choice{};
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            add_money(bank.customers[customer_number], account_number);
            break;
        case 2:
            withdraw_money(bank.customers[customer_number], account_number);
            break;
        case 3:
            see_account_balance(bank.customers[customer_number], account_number);
            break;
        case 4:
            std::cout << "\nLogging out from the account..\n";
            return;
        default:
            std::cout << "\nInvalid choice. Please try again.\n";
        }
    }
}

// Case 4: Function to save account data to a file
void save_account_data(const Bank &bank)
{
    std::ofstream output_file("../data/account_data.txt");

    if (!output_file)
    {
        throw std::runtime_error("Error opening file for writing.\n");
    }

    for (const auto &[customer_number, customer] : bank.customers)
    {
        output_file << "Customer Number: " << customer_number << "\n";
        output_file << "Name: " << customer.name << "\n";
        output_file << "Address: " << customer.address << "\n";
        output_file << "Phone Number: " << customer.phone_number << "\n";

        for (const auto &[account_number, account] : customer.accounts)
        {
            output_file << "Account Number: " << account_number << "\n";
            output_file << "Balance: " << account.balance << "\n";
        }

        output_file << "\n";
    }

    std::cout << "Account data saved to file.\n";
}

// Function to load account data from a file and create a new file if it doesn't exist
void load_account_data(Bank &bank)
{
    std::ifstream input_file("../data/account_data.txt");

    // If the input file does not exist, the program creates the file
    if (!input_file)
    {
        std::ofstream output_file("../data/account_data.txt");
        if (!output_file)
        {
            throw std::runtime_error("Error creating file.\n");
        }
        else
        {
            std::cout << "\nCreated a file 'account_data.txt' to store the data.\n";
        }
        return;
    }

    bank.customers.clear();

    std::string line{};
    int customer_number{};
    int account_number{};
    std::string name{};
    std::string address{};
    std::string phone_number{};
    double balance{};

    while (std::getline(input_file, line))
    {
        if (line.find("Customer Number: ") == 0)
        {
            if (customer_number != 0)
            {
                // Add the previous customer to the map
                bank.customers[customer_number] = {name, address, phone_number};
            }

            // Extract the customer number
            customer_number = std::stoi(line.substr(17));
        }
        else if (line.find("Name: ") == 0)
        {
            // Extract the name
            name = line.substr(6);
        }
        else if (line.find("Address: ") == 0)
        {
            // Extract the address
            address = line.substr(9);
        }
        else if (line.find("Phone Number: ") == 0)
        {
            // Extract the phone number
            phone_number = line.substr(14);
        }
        else if (line.find("Account Number: ") == 0)
        {
            // Extract the account number
            account_number = std::stoi(line.substr(16));
        }
        else if (line.find("Balance: ") == 0)
        {
            // Extract the balance
            balance = std::stod(line.substr(9));

            // Add the account to the current customer
            bank.customers[customer_number].accounts[account_number] = {balance};
        }
    }

    // Add the last customer to the map
    if (customer_number != 0)
    {
        bank.customers[customer_number] = {name, address, phone_number};
    }

    std::cout << "Account data loaded from file.\n";
}

// Case 5: Function to delete a customer
void delete_customer(Bank &bank)
{
    std::cout << "Enter customer number: ";
    int customer_number{};
    std::cin >> customer_number;

    // Check if the customer exists
    if (bank.customers.find(customer_number) == bank.customers.end())
    {
        std::cout << "Customer number " << customer_number << " does not exist.\n";
        return;
    }

    bank.customers.erase(customer_number);
    std::cout << "Customer with number " << customer_number << " deleted successfully!\n";
}

// Case 6: Function to delete an account
void delete_account(Bank &bank)
{
    std::cout << "Enter customer number: ";
    int customer_number{};
    std::cin >> customer_number;

    // Check if the customer exists
    if (bank.customers.find(customer_number) == bank.customers.end())
    {
        std::cout << "Customer number " << customer_number << " does not exist.\n";
        return;
    }

    std::cout << "Enter account number: ";
    int account_number{};
    std::cin >> account_number;

    // Check if the account exists
    if (bank.customers[customer_number].accounts.find(account_number) == bank.customers[customer_number].accounts.end())
    {
        std::cout << "Account number " << account_number << " does not exist.\n";
        return;
    }

    bank.customers[customer_number].accounts.erase(account_number);
    std::cout << "Account with number " << account_number << " deleted successfully!\n";
}
