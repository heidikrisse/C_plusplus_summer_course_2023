// weather_data.h
#ifndef WEATHER_DATA_H
#define WEATHER_DATA_H

#include <string>

// Struct to hold weather data.
struct WeatherData
{
    double temperature{};
    double humidity{};
    double wind_speed{};
    double atmospheric_pressure{};
};

// Function to generate random weather data.
WeatherData generate_weather_data();

// Function to get weather data from user input.
WeatherData get_user_input();

// Function to write weather data to a file.
void write_to_file(const WeatherData &weather_data, const std::string &file_name);

#endif // WEATHER_DATA_H
