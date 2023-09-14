// sensor_functions.cpp
#include "../include/sensor_functions.h"

#include <algorithm>     // for std::sort
#include <unordered_map> // for std::unordered_map
#include <cmath>         // for std::fabs
#include <numeric>       // for std::accumulate
#include <random>        // for std::mt19937 and std::random_device

// Function to compare two SensorData based on their timestamp
bool compare_timestamp(const SensorData &a, const SensorData &b)
{
    return a.timestamp < b.timestamp;
}

// Function to generate a list of sensor readings
std::vector<SensorData> generate_data(size_t num_data)
{
    std::mt19937 mt{std::random_device{}()};
    std::uniform_real_distribution<float> temp_dist{20.0, 25.0};
    std::uniform_int_distribution<> sensor_dist{0, 9};

    std::vector<SensorData> data(num_data);

    for (size_t i{0}; i < num_data; ++i)
    {
        data[i] = {i, "Sensor_" + std::to_string(sensor_dist(mt)), temp_dist(mt)};
    }

    return data;
}

// Function to filter readings from a sensor with a chosen ID
std::vector<SensorData> filter_data(const std::vector<SensorData> &data, const std::string &id)
{
    std::vector<SensorData> filtered;

    for (const auto &item : data)
    {
        if (item.sensor_id == id)
        {
            filtered.push_back(item);
        }
    }

    return filtered;
}

// Function to sort sensor data based on the timestamp
void sort_data(std::vector<SensorData> &data)
{
    std::sort(data.begin(), data.end(), compare_timestamp);
}

// Function to calculate the mean of sensor values in the data vector
float calculate_mean(const std::vector<SensorData> &data)
{
    float sum{0.0f};

    for (const auto &item : data)
    {
        sum += item.sensor_value;
    }

    return sum / data.size();
}

// Function to detect outliers in sensor readings
std::vector<SensorData> detect_outliers(const std::vector<SensorData> &data, float deviation)
{
    std::vector<SensorData> outliers;

    // Using the compute_mean function to calculate the mean
    float mean_value{calculate_mean(data)};

    for (const auto &item : data)
    {
        if (std::fabs(item.sensor_value - mean_value) > deviation)
        {
            outliers.push_back(item);
        }
    }

    return outliers;
}

// Function to find the sensor that has the highest frequency of readings
std::string find_highest_frequency(const std::vector<SensorData> &data)
{
    std::unordered_map<std::string, int> frequency;

    for (const auto &item : data)
    {
        ++frequency[item.sensor_id];
    }

    std::string highest_frequency_sensor_id{};
    int max_freq{0};

    for (const auto &pair : frequency)
    {
        if (pair.second > max_freq)
        {
            max_freq = pair.second;
            highest_frequency_sensor_id = pair.first;
        }
    }

    return highest_frequency_sensor_id;
}
