// data_generator.cpp
#include "../include/data_generator.h"
#include "../include/file_handler.h"
#include "../include/random_number_generator.h"

#include <iostream>
#include <vector>

// Function to generate a master device and 10 slave devices with data registers
void generate_devices_and_registers()
{
    std::vector<Device> devices;
    // Declare registers
    std::map<int, std::map<int, int>> registers;

    // Create master device with ID = 0
    devices.push_back(Device{0, true});

    int number_of_slaves{10};
    // Create slave devices with IDs 1-10 and their data registers
    for (int id{1}; id <= number_of_slaves; ++id)
    {
        Device slave{id, false};

        // Assign random numbers to address and value of each slave's register
        for (int i{0}; i < 5; i++) // Add 5 registers to each device
        {
            /* A register address of a slave device is given a random number
             * of 1 - 10000 and a register value is given a random value of
             * 1 - 100 */
            int register_address{generate_random_number(1, 10000)};
            int register_value{generate_random_number(1, 100)};
            slave.registers[register_address] = register_value;
            registers[id][register_address] = register_value;
        }
        devices.push_back(slave);
    }

    // Write the devices and registers to files
    write_devices_data_to_file(devices);
    write_registers_data_to_file(registers);
}
