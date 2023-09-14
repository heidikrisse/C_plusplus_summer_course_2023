// database.cpp
#include "../include/database.h"
#include <filesystem>
#include <fstream>

// Function to save account data to a file
void save_account_data(const Bank &bank)
{
    std::string directory_path_str{"../data"};
    std::filesystem::path directory(directory_path_str);
    std::filesystem::create_directories(directory);

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
// database.cpp
// ...

void load_account_data(Bank &bank)
{
    std::string directory_path_str{"../data"};
    std::filesystem::path directory(directory_path_str);
    std::filesystem::create_directories(directory);
    std::ifstream input_file("../data/account_data.txt");

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
    Customer new_customer;

    while (std::getline(input_file, line))
    {
        if (line.find("Customer Number: ") == 0)
        {
            if (customer_number != 0)
            {
                // Add the previous customer to the map
                bank.customers[customer_number] = new_customer;
            }

            // Reset the new_customer object for the next customer
            new_customer = Customer();

            // Extract the customer number
            customer_number = std::stoi(line.substr(17));
        }
        else if (line.find("Name: ") == 0)
        {
            // Extract the name
            new_customer.name = line.substr(6);
        }
        else if (line.find("Address: ") == 0)
        {
            // Extract the address
            new_customer.address = line.substr(9);
        }
        else if (line.find("Phone Number: ") == 0)
        {
            // Extract the phone number
            new_customer.phone_number = line.substr(14);
        }
        else if (line.find("Account Number: ") == 0)
        {
            // Extract the account number
            account_number = std::stoi(line.substr(16));
        }
        else if (line.find("Balance: ") == 0)
        {
            // Extract the balance
            double balance = std::stod(line.substr(9));

            // Add the account to the current customer
            new_customer.accounts[account_number] = {balance};
        }
    }

    // Add the last customer to the map
    if (customer_number != 0)
    {
        bank.customers[customer_number] = new_customer;
    }

    std::cout << "Account data loaded from file.\n";
}
