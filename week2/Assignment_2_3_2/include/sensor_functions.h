// sensor_functions.h
#ifndef SENSOR_FUNCTIONS_H
#define SENSOR_FUNCTIONS_H

#include <vector>
#include <string>

// SensorData struct (= a sensor reading) that contains a timestamp, a sensor ID and a sensor value.
struct SensorData
{
    size_t timestamp{};
    std::string sensor_id{};
    float sensor_value{};
};

/* Exercise 1:
 *
 * Function to generate a vector of SensorData struct: a vector or sensor
 * data readings */
std::vector<SensorData> generate_data(size_t num_data);

/* Exercise 2:
 *
 * Function to filter readings from a specified sensor */
std::vector<SensorData> filter_data(const std::vector<SensorData> &data, const std::string &id);

/* Exercise 3:
 *
 * Function to sort sensor data based on the timestamp in ascending order */
void sort_data(std::vector<SensorData> &data);

// Function to calculate the mean of sensor values in the data vector
float calculate_mean(const std::vector<SensorData> &data);

/* Exercise 4:
 *
 * Function to detect outliers in sensor readings */
std::vector<SensorData> detect_outliers(const std::vector<SensorData> &data, float deviation);

/* Exercise 5:
 *
 * Function to find the sensor that has the highest frequency of readings */
std::string find_highest_frequency(const std::vector<SensorData> &data);

#endif
