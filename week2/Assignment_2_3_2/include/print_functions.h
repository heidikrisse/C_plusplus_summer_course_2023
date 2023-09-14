// print_functions.h
#ifndef PRINT_FUNCTIONS_H
#define PRINT_FUNCTIONS_H

#include "sensor_functions.h"

// Function to print a single SensorData
void print_data(const std::vector<SensorData> &data);
// Function to print a list of SensorData
void print_sensor(const SensorData &sensor);
// Function to print the sensor ID with the highest frequency of readings
void print_highest_frequency_sensor(const std::string &sensor_id);

#endif
