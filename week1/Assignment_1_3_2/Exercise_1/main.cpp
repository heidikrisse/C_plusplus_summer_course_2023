#include <iostream>
#include <string>

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
    Account account{};
};

// Function to add money to the account
void addMoney(Customer &customer)
{
    std::cout << "Enter the money amount to be added to the bank account: ";
    double moneyAmount{};
    std::cin >> moneyAmount;
    customer.account.balance += moneyAmount;
    std::cout << moneyAmount << "e added successfully to the bank account!\n";
}

// Function to withdraw money from the account
void withdrawMoney(Customer &customer)
{
    std::cout << "Enter the money amount to be withdrawn from the bank account: ";
    double moneyAmount{};
    std::cin >> moneyAmount;

    if (moneyAmount > customer.account.balance)
    {
        std::cout << "Insufficient funds! You cannot withdraw " << moneyAmount << "e from the bank account because there are insufficient funds.\n";
    }
    else
    {
        customer.account.balance -= moneyAmount;
        std::cout << moneyAmount << "e withdrawn successfully!\n";
    }
}

// Function to display the account balance
void seeAccountBalance(const Customer &customer)
{
    std::cout << "Account balance: " << customer.account.balance << "e\n";
}

int main()
{
    // Create a customer object
    Customer customer;

    // Get customer information from the user
    std::cout << "Enter customer name: ";
    std::getline(std::cin, customer.name);
    std::cout << "Enter customer address: ";
    std::getline(std::cin, customer.address);
    std::cout << "Enter customer phone number: ";
    std::getline(std::cin, customer.phone_number);

    // Menu loop
    while (true)
    {
        std::cout << "\nBanking application menu:\n";
        std::cout << "1. Add money\n";
        std::cout << "2. Withdraw money\n";
        std::cout << "3. See account balance\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice: ";
        int choice{};
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            addMoney(customer);
            break;
        case 2:
            withdrawMoney(customer);
            break;
        case 3:
            seeAccountBalance(customer);
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
