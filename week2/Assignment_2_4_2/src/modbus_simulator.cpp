// modbus_simulation.cpp
#include "../include/modbus_simulator.h"
#include "../include/data_generator.h"
#include "../include/file_handler.h"
#include "../include/user_input.h"

#include <iostream>
#include <map>
#include <algorithm> // for std::find_if

// Function to print a current register address
void print_current_register_address(std::map<int, std::map<int, int>> &registers, int slave_id, int register_address)
{
    // Check if the slave device exists and the register exists
    auto slave_register{registers.find(slave_id)};
    if (slave_register != registers.end())
    {
        auto address_value{slave_register->second.find(register_address)};
        if (address_value != slave_register->second.end())
        {
            // The master device reads the value of the slave device's register
            int value{address_value->second};
            std::cout << "The current value at register address " << register_address << " on the slave device " << slave_id << " is " << value << "\n";
        }
        else
        {
            std::cout << "Register address " << register_address << " does not exist on the slave device " << slave_id << "\n";
        }
    }
}

// Function to simulate Modbus communication
void simulate_modbus_communication()
{
    // Read devices data from the file
    auto devices{read_devices_data_from_file()};

    // Read registers data from the file
    auto registers{read_registers_data_from_file()};

    /* Look for the master device
     * -    The lambda function searches the devices for a Device
     *      object where the is_master attribute is true. If such a
     *      Device object is found, master will be an iterator pointing to
     *      it. If no such Device is found, master will be devices.end() */
    auto master{std::find_if(devices.begin(), devices.end(), [](Device &device)
                             { return device.is_master; })};

    // If master device is founded
    if (master != devices.end())
    {
        // Loop until a user choses to quit
        while (true)
        {
            std::cout << "\n*** Modbus communication program ***\n\n";
            int slave_id{get_slave_device_id_from_user()};

            /* Find the slave device in the devices list
             * -    slave_it means slave device iterator
             * -    The lambda function searches the devices for a Device
             *      object with an id that matches slave_id. If such a
             *      Device object is found, slave_it will be an
             *      iterator pointing to it. If no such Device is
             *      found, slave_it will be devices.end() */
            auto slave_it{std::find_if(devices.begin(), devices.end(), [slave_id](const Device &device)
                                       { return device.id == slave_id; })};

            if (slave_it == devices.end())
            {
                std::cerr << "Slave device with ID " << slave_id << " does not exist.\n";
                continue;
            }

            // Reference to the found slave device
            Device &slave_device = *slave_it;

            std::cout << "\nChoose an action:\n\n1 - Read a register value of a slave device\n2 - Write a new value into a register of a slave device\n3 - Quit\n\nChoose an action (1, 2 or 3): ";

            int chosen_action{};
            std::cin >> chosen_action;

            switch (chosen_action)
            {
            case 1: // Read a register value
            {
                int register_address{get_register_address(slave_device, chosen_action)};
                print_current_register_address(registers, slave_id, register_address);
                break;
            }
            case 2: // Write a value into a register
            {
                int register_address{get_register_address(slave_device, chosen_action)};
                print_current_register_address(registers, slave_id, register_address);

                std::cout << "Enter a new value into a slave device's register: ";
                int new_value{};
                std::cin >> new_value;

                // Update the chosen register with the new value
                registers[slave_id][register_address] = new_value;

                // Write the updated registers data back to the file
                write_registers_data_to_file(registers);

                std::cout << "The register of the slave device " << slave_id << " at register address " << register_address << " has been successfully updated with the new value of " << new_value << "\n";
                break;
            }
            case 3: // Quit program
            {
                std::cout << "Program will exit.. \n";
                return;
            }
            default:
            {
                std::cerr << "Invalid action entered. Please try again.\n";
                break;
            }
            }
        }
    }
    else
    {
        std::cerr << "Master device does not exist.\n";
    }
}
