// file_handler.cpp
#include "../include/file_handler.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

// Function to ensure the data directory exists
void ensure_data_directory_exists()
{
    std::filesystem::path dir("../data");

    // Check if the data directory already exists
    if (!std::filesystem::exists(dir))
    {
        // If not, attempt to create it
        if (!std::filesystem::create_directory(dir))
        {
            std::cerr << "Failed to create the data directory.\n";
        }
    }
}

// Function to write the data from devices to a CSV file
void write_devices_data_to_file(const std::vector<Device> &devices)
{
    // Ensure the data directory exists before trying to write to a file
    ensure_data_directory_exists();
    std::ofstream devices_file{"../data/devices.csv"};

    if (devices_file.is_open())
    {
        // Iterate over each device to write each device's data to the file
        for (const auto &device : devices)
        {
            /* Each line represents one device, with 'id' and
             * 'is_master' attribute separated by comma */
            devices_file << device.id << ","
                         << (device.is_master ? "1" : "0") << "\n";
        }

        devices_file.close();
    }
    else
    {
        std::cerr << "Unable to open devices.csv for writing.\n";
    }
}

/* Function to read devices data from a CSV file and return a vector of
 * Device objects */
std::vector<Device> read_devices_data_from_file()
{
    ensure_data_directory_exists();
    std::vector<Device> devices;
    std::ifstream devices_file{"../data/devices.csv"};
    std::string line{};

    // Read data from registers.csv file and store it in a map
    auto registers = read_registers_data_from_file();

    if (devices_file.is_open())
    {
        // Read each line from the file until end
        while (std::getline(devices_file, line))
        {
            if (line.empty())
                continue;

            std::istringstream line_stream{line};
            Device device{};

            std::string id_str{};
            std::getline(line_stream, id_str, ',');
            device.id = std::stoi(id_str);

            std::string is_master_str{};
            std::getline(line_stream, is_master_str, ',');
            device.is_master = std::stoi(is_master_str) == 1;

            /* If the id of device exists in the registers, set the
             * registers to the device object */
            if (registers.count(device.id) > 0)
            {
                device.registers = registers[device.id];
            }

            // Add the device object to the devices vector
            devices.push_back(device);
        }

        devices_file.close();
    }
    else
    {
        std::cerr << "Unable to open devices.csv for reading.\n";
    }

    return devices;
}

// Function to write registers data to a CSV file
void write_registers_data_to_file(const std::map<int, std::map<int, int>> &registers)
{
    ensure_data_directory_exists();
    std::ofstream registers_file{"../data/registers.csv"};

    if (registers_file.is_open())
    {
        // Iterate over each register to write each register's data to the file
        for (const auto &[device_id, register_map] : registers)
        {
            for (const auto &[register_address, register_value] : register_map)
            {
                registers_file << device_id << ","
                               << register_address << ","
                               << register_value << "\n";
            }
        }

        registers_file.close();
    }
    else
    {
        std::cerr << "Unable to open devices.csv for writing.\n";
    }
}

// Function to read registers data from a CSV file
std::map<int, std::map<int, int>> read_registers_data_from_file()
{
    ensure_data_directory_exists();

    std::map<int, std::map<int, int>> registers;
    std::ifstream registers_file{"../data/registers.csv"};
    std::string line{};

    if (registers_file.is_open())
    {
        // Read each line from the registers file
        while (std::getline(registers_file, line))
        {
            if (line.empty())
                continue;

            std::istringstream line_stream{line};

            std::string device_id_str{};
            std::getline(line_stream, device_id_str, ',');
            int device_id = std::stoi(device_id_str);

            std::string register_address_str{};
            std::getline(line_stream, register_address_str, ',');
            int register_address = std::stoi(register_address_str);

            std::string register_value_str{};
            std::getline(line_stream, register_value_str, ',');
            int register_value = std::stoi(register_value_str);

            registers[device_id][register_address] = register_value;
        }

        registers_file.close();
    }
    else
    {
        std::cerr << "Unable to open registers.csv for reading.\n";
    }

    return registers;
}
