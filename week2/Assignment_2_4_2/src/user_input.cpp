// user_input.cpp
#include "../include/modbus_simulator.h"
#include "../include/device.h"

#include <iostream>

// Function to get a slave device id from the user
int get_slave_device_id_from_user()
{
    int slave_id{};
    // Do-while -loop to ask user for slave_id until a valid input is given
    do
    {
        std::cout << "Enter the id of the slave device (1 - 10) you want the master device interact with: ";
        std::cin >> slave_id;
        if (slave_id < 1 && slave_id > 10)
        {
            std::cout << "Slave device " << slave_id << " does not exist. Please try again to give a valid id for a slave device [1 - 10].\n";
        }
    } while (slave_id < 1 && !slave_id > 10); // validate input

    return slave_id;
}

// Function to get a register address from the user
int get_register_address(Device &slave_device, int chosen_action)
{
    // If action 1 or 2 is chosen, print the register addresses
    if (chosen_action == 1 || chosen_action == 2)
    {
        std::cout << "A slave device " << slave_device.id << " has the following register addresses: \n\n";
        for (const auto &reg : slave_device.registers)
        {
            std::cout << reg.first << "\n";
        }
        std::cout << "\nChoose one of the register addresses above: ";
    }

    int register_address{};
    bool valid_choice{false};
    do
    {
        std::cin >> register_address;
        if (slave_device.registers.count(register_address) > 0)
        {
            valid_choice = true;
        }
        else
        {
            std::cout << "Invalid register address. Please try again to give a valid address.\n";
        }
    } while (!valid_choice); // validate input

    return register_address;
}
