// weather_functions.cpp
#include "../include/weather_data.h"
#include <iostream>
#include <fstream>
#include <random>
#include <stdexcept>

// Function to generate random weather data.
WeatherData generate_weather_data()
{
    /* Random number generators for temperature, humidity, wind_speed
     * and pressure. */
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_real_distribution<> temperature_distribution(-30, 30); // -30 - +30 instead of the suggested -20 - +20 to make this more realistic
    std::uniform_real_distribution<> humidity_distribution(0, 100);
    std::uniform_real_distribution<> wind_speed_distribution(0, 150);
    std::uniform_real_distribution<> pressure_distribution(950, 1050);

    // Generate random weather data.
    WeatherData weather_data{};
    weather_data.temperature = temperature_distribution(generator);
    weather_data.humidity = humidity_distribution(generator);
    weather_data.wind_speed = wind_speed_distribution(generator);
    weather_data.atmospheric_pressure = pressure_distribution(generator);

    return weather_data;
}

// Function to get weather data from user input.
WeatherData get_user_input()
{
    WeatherData weather_data;

    std::cout << "Enter temperature in Celsius: ";
    std::cin >> weather_data.temperature;

    std::cout << "Enter humidity in %: ";
    std::cin >> weather_data.humidity;

    std::cout << "Enter wind speed in km/h: ";
    std::cin >> weather_data.wind_speed;

    std::cout << "Enter atmospheric pressure in hPa: ";
    std::cin >> weather_data.atmospheric_pressure;

    return weather_data;
}

// Function to write weather data to a file.
void write_to_file(const WeatherData &weather_data, const std::string &file_name)
{
    /* Open the output file in append mode.
     * std::ios::app is a flag that causes new data written to the file to
     * be added to the end, keeping the existing contents instead
     * of  overwriting them. */
    std::ofstream output_file(file_name, std::ios::app);

    // If couldn't open the file, throw an exception.
    if (!output_file.is_open())
    {
        throw std::runtime_error("Could not open file");
    }

    // Write weather data to the file.
    output_file << "Temperature: " << weather_data.temperature << " C\n"
                << "Humidity: " << weather_data.humidity << " %\n"
                << "Wind Speed: " << weather_data.wind_speed << " km/h\n"
                << "Atmospheric Pressure: " << weather_data.atmospheric_pressure << " hPa\n\n";

    output_file.close();
}
