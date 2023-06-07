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
void addCustomer(std::map<int, Customer> &customers)
{
    std::cout << "Enter customer number: ";
    int customer_number{};
    std::cin >> customer_number;

    // Check if the customer number is already taken
    if (customers.find(customer_number) != customers.end())
    {
        std::cout << "The customer number " << customer_number << " is already taken. Please choose another available customer number.\n";
        return;
    }

    std::cin.ignore(); // Clear the newline character from the input buffer

    Customer new_customer{};

    std::cout << "Enter customer name: ";
    std::getline(std::cin, new_customer.name);

    std::cout << "Enter customer address: ";
    std::getline(std::cin, new_customer.address);

    std::cout << "Enter customer phone number: ";
    std::getline(std::cin, new_customer.phone_number);

    customers[customer_number] = new_customer;

    std::cout << "Customer with number " << customer_number << " added successfully!\n";
}

// Function to add a new account for a customer
void addAccount(std::map<int, Customer> &customers)
{
    std::cout << "Enter customer number: ";
    int customer_number{};
    std::cin >> customer_number;

    // Check if the customer exists
    if (customers.find(customer_number) == customers.end())
    {
        std::cout << "Customer number " << customer_number << " does not exist. Please add the customer first.\n";
        return;
    }

    std::cout << "Enter account number: ";
    int account_number{};
    std::cin >> account_number;

    // Check if the account number is already taken
    if (customers[customer_number].accounts.find(account_number) != customers[customer_number].accounts.end())
    {
        std::cout << "This account number is already taken. Please choose another available account number.\n";
        return;
    }

    customers[customer_number].accounts[account_number] = Account();

    std::cout << "Account with number " << account_number << " created successfully for customer " << customer_number << "!\n";
}

// Function to log in to a customer's account
void loginAccount(std::map<int, Customer> &customers)
{
    int customer_number{};
    std::cout << "Enter customer number: ";
    std::cin >> customer_number;

    // Check if the customer exists
    if (customers.find(customer_number) == customers.end())
    {
        std::cout << "Customer number " << customer_number << " does not exist. Please add the customer first.\n";
        return;
    }

    std::cout << "Enter account number: ";
    int account_number{};
    std::cin >> account_number;

    // Check if the account exists
    if (customers[customer_number].accounts.find(account_number) == customers[customer_number].accounts.end())
    {
        std::cout << "Account number " << account_number << " does not exist for customer " << customer_number << ". Please try again.\n";
        return;
    }

    std::cout << "Logged in to account " << account_number << " for customer " << customer_number << ".\n";

    // Inner menu loop for account operations
    while (true)
    {
        std::cout << "\nAccount menu:\n";
        std::cout << "1. Add money\n";
        std::cout << "2. Withdraw money\n";
        std::cout << "3. See account balance\n";
        std::cout << "4. Log out\n";
        std::cout << "Enter your choice: ";
        int account_choice{};
        std::cin >> account_choice;

        switch (account_choice)
        {
        case 1:
            addMoney(customers[customer_number], account_number);
            break;
        case 2:
            withdrawMoney(customers[customer_number], account_number);
            break;
        case 3:
            seeAccountBalance(customers[customer_number], account_number);
            break;
        case 4:
            std::cout << "Logged out from account " << account_number << " for customer " << customer_number << ".\n";
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

int main()
{
    std::map<int, Customer> customers; // Map to store multiple customers

    // Main menu loop
    while (true)
    {
        std::cout << "\nBanking application menu:\n";
        std::cout << "1. Add a new customer\n";
        std::cout << "2. Add a new account\n";
        std::cout << "3. Log in to account\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice: ";
        int choice{};
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            addCustomer(customers);
            break;
        case 2:
            addAccount(customers);
            break;
        case 3:
            loginAccount(customers);
            break;
        case 4:
            std::cout << "Exiting the banking application..\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
