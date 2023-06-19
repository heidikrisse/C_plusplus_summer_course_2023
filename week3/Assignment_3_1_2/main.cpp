// main.cpp
#include "include/weather_data.h"
#include "include/file_handler.h"
#include <iostream>
#include <string>

int main()
{
    // Directory and file to write weather data to.
    std::string directory_path{"../data"};
    std::string file_path{"../data/weather_log.txt"};

    // Ensure the directory and file exist.
    ensure_directory_exists(directory_path);
    ensure_file_exists(file_path);

    try
    {
        // Ask user if they want to enter weather data manually.
        std::cout << "Would you like to enter weather data manually? (y/n): ";
        char response{};
        std::cin >> response;

        if (response == 'y' || response == 'Y')
        {
            // Get weather data from user input.
            WeatherData weather_data = get_user_input();

            if (weather_data.temperature < -273.15 || weather_data.humidity > 100)
            {
                throw std::runtime_error("Generated temperature is < - 273.1C or generated humidity > 100%.");
            }

            // Write the weather data to the file.
            write_to_file(weather_data, file_path);
            std::cout << "Successfully logged manually entered weather data.\n";
        }
        else
        {
            int hours{24}; // 24h

            // Generate and log weather data for given hours.
            for (int i{0}; i < hours; ++i)
            {
                WeatherData weather_data{generate_weather_data()};

                if (weather_data.temperature < -273.15 || weather_data.humidity > 100)
                {
                    throw std::runtime_error("Generated temperature is < - 273.1C or generated humidity > 100%.");
                }

                write_to_file(weather_data, file_path);
            }

            std::cout << "Successfully logged weather data in " << file_path << " for " << hours << " hours.\n";
        }
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "An error occurred: " << e.what() << "\n";
    }

    return 0;
}
