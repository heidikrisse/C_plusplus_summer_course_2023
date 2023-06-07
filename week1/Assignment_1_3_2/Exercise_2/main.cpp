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

int main()
{
    // Create a customer object
    Customer customer;

    // Menu loop
    while (true)
    {
        std::cout << "\nBanking application menu:\n";
        std::cout << "1. Add a new account\n";
        std::cout << "2. Log in to account\n";
        std::cout << "3. Quit\n";
        std::cout << "Enter your choice: ";
        int choice{};
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::cout << "Enter account number: ";
            int account_number{};
            std::cin >> account_number;

            // Check if the account number is already taken
            if (customer.accounts.find(account_number) != customer.accounts.end())
            {
                std::cout << "This account number is already taken. Please choose another available account number.\n";
            }
            else
            {
                customer.accounts[account_number] = Account();
                std::cout << "Account with account number " << account_number << " created successfully!\n";
            }
            break;
        }
        case 2:
        {
            std::cout << "Enter account number: ";
            int account_number{};
            std::cin >> account_number;

            // Check if the account number exists
            if (customer.accounts.find(account_number) != customer.accounts.end())
            {
                std::cout << "Logged in to account " << account_number << "\n";

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
                        addMoney(customer, account_number);
                        break;
                    case 2:
                        withdrawMoney(customer, account_number);
                        break;
                    case 3:
                        seeAccountBalance(customer, account_number);
                        break;
                    case 4:
                        std::cout << "Logged out from account " << account_number << ".\n";
                        break;
                    default:
                        std::cout << "Invalid choice. Please try again.\n";
                    }

                    // Break out of the inner menu loop if log out is selected
                    if (account_choice == 4)
                        break;
                }
            }
            else
            {
                std::cout << "Account number " << account_number << " does not exist. Please try again.\n";
            }
            break;
        }
        case 3:
            std::cout << "Exiting the banking application..\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
