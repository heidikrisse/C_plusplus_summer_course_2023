// file_handler.h
#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <vector>
#include "device.h"

// Function to ensure the data directory exists
void ensure_data_directory_exists();

// Function to write devices data to a CSV file
void write_devices_data_to_file(const std::vector<Device> &devices);
// Function to read devices data from a CSV file
std::vector<Device> read_devices_data_from_file();

// Function to write registers data to a CSV file
void write_registers_data_to_file(const std::map<int, std::map<int, int>> &registers);
// Function to read registers data from a CSV file
std::map<int, std::map<int, int>> read_registers_data_from_file();

#endif
