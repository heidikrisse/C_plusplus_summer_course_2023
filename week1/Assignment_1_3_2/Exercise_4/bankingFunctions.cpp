#include "bankingFunctions.h"

// Function to add money to an account
void addMoney(Customer &customer, int account_number)
{
    std::cout << "Enter the money amount to be added to account " << account_number << ": ";
    double moneyAmount{};
    std::cin >> moneyAmount;
    customer.accounts[account_number].balance += moneyAmount;
    std::cout << moneyAmount << "e added successfully to the bank account " << account_number << ".\n";
}

// Function to withdraw money from an account
void withdrawMoney(Customer &customer, int account_number)
{
    std::cout << "Enter the money amount to be withdrawn from account " << account_number << ": ";
    double moneyAmount{};
    std::cin >> moneyAmount;

    if (moneyAmount > customer.accounts[account_number].balance)
    {
        std::cout << "Insufficient funds! You cannot withdraw " << moneyAmount << "e from the bank account because there are insufficient funds.\n";
    }
    else
    {
        customer.accounts[account_number].balance -= moneyAmount;
        std::cout << moneyAmount << "e withdrawn successfully!\n";
    }
}

// Function to display the account balance
void seeAccountBalance(const Customer &customer, int account_number)
{
    std::cout << "Account " << account_number << " balance: " << customer.accounts.at(account_number).balance << "e\n";
}

// Function to add a new customer
void addCustomer(Bank &bank)
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

// Function to add a new account for a customer
void addAccount(Bank &bank)
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

// Function to log in to an account
void loginAccount(Bank &bank)
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
            addMoney(bank.customers[customer_number], account_number);
            break;
        case 2:
            withdrawMoney(bank.customers[customer_number], account_number);
            break;
        case 3:
            seeAccountBalance(bank.customers[customer_number], account_number);
            break;
        case 4:
            std::cout << "\nLogging out from the account..\n";
            return;
        default:
            std::cout << "\nInvalid choice. Please try again.\n";
        }
    }
}

// Function to delete a customer
void deleteCustomer(Bank &bank)
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

// Function to delete an account
void deleteAccount(Bank &bank)
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

// Function to save account data to a file
void saveAccountData(const Bank &bank)
{
    std::ofstream outputFile("account_data.txt");

    if (!outputFile)
    {
        std::cout << "Error opening file for writing.\n";
        return;
    }

    for (const auto &[customer_number, customer] : bank.customers)
    {
        outputFile << "Customer Number: " << customer_number << "\n";
        outputFile << "Name: " << customer.name << "\n";
        outputFile << "Address: " << customer.address << "\n";
        outputFile << "Phone Number: " << customer.phone_number << "\n";

        for (const auto &[account_number, account] : customer.accounts)
        {
            outputFile << "Account Number: " << account_number << "\n";
            outputFile << "Balance: " << account.balance << "\n";
        }

        outputFile << "\n";
    }

    std::cout << "Account data saved to file.\n";
}

// Function to load account data from a file and create a new file if it doesn't exist
void loadAccountData(Bank &bank)
{
    std::ifstream inputFile("account_data.txt");

    // If the input file does not exist, the program creates the file
    if (!inputFile)
    {
        std::ofstream outputFile("account_data.txt");
        if (!outputFile)
        {
            std::cout << "Error creating file.\n";
            return;
        }
        else
        {
            std::cout << "Created a file 'account_data.txt' to store the data.\n";
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

    while (std::getline(inputFile, line))
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
