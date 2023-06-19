/* user_interface.cpp

 * Defines the user_interface function where a user can choose between
 * the following operations on generated sensor data:
 * 1. Print sensor data by a specific sensor ID
 * 2. Detect and print outliers by sensor ID
 * 3. Find and print the sensor ID with the highest frequency
 * 4. Quit the program
 **/
#include "../include/user_interface.h"
#include "../include/sensor_functions.h"
#include "../include/print_functions.h"

#include <iostream>

/* Function for the user interface. It runs in a loop until the user chooses to exit. */
void user_interface()
{
    int option{0};
    while (option != 4)
    {
        std::cout << "***** TEMPERATURE SENSOR DATA PROGRAM *****\n\n";
        std::cout << "1. Print sensor data by sensor ID\n";
        std::cout << "2. Print outliers by sensor ID\n";
        std::cout << "3. Find the sensor ID with the highest frequency\n";
        std::cout << "4. Quit program\n\n";
        std::cout << "Enter your option: ";
        std::cin >> option;

        if (option == 1)
        {
            std::cout << "Enter the sensor id (e.g. Sensor_1): ";
            std::string sensor_id{};
            std::cin >> sensor_id;

            auto data{generate_data(1000)};
            auto filtered_data{filter_data(data, sensor_id)};
            sort_data(filtered_data);

            std::cout << "Temperature sensor data of the " << sensor_id << "  sorted based on the timestamp in ascending order:\n\n";
            print_data(filtered_data);
        }
        else if (option == 2)
        {
            std::cout << "Enter the sensor id (e.g. Sensor_1): ";
            std::string sensor_id{};
            std::cin >> sensor_id;

            auto data{generate_data(1000)};
            auto filtered_data{filter_data(data, sensor_id)};
            auto outliers{detect_outliers(filtered_data, 1.0)};

            std::cout << "Outliers in the temperature sensor readings for the " << sensor_id << ":\n\n";
            print_data(outliers);
        }
        else if (option == 3)
        {
            auto data{generate_data(1000)};
            auto highest_frequency_sensor_id{find_highest_frequency(data)};
            print_highest_frequency_sensor(highest_frequency_sensor_id);
        }
    }
}
