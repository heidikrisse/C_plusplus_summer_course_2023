// print_functions.cpp
#include "../include/print_functions.h"

#include <iostream>

// Function to print a single SensorData
void print_sensor(const SensorData &sensor)
{
    std::cout << "Timestamp: " << sensor.timestamp
              << ", sensor ID: " << sensor.sensor_id
              << ", temperature: " << sensor.sensor_value << "°C"
              << "\n";
}

// Function to print a list of SensorData
void print_data(const std::vector<SensorData> &data)
{
    std::cout << "\n";
    for (const auto &item : data)
    {
        print_sensor(item);
    }
    std::cout << "\n";
}

// Function to print the sensor ID with the highest frequency of readings
void print_highest_frequency_sensor(const std::string &sensor_id)
{
    std::cout << "Sensor with the highest frequency of readings: " << sensor_id << "\n\n";
}
