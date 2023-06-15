// file_reader.cpp
#include <fstream>
#include <iostream>
#include "../include/file_reader.h"

// Read a file and return its contents as a vector of strings
std::vector<std::string> read_file(const std::string &file_name)
{
    std::vector<std::string> content{};

    // Create an ifstream object
    std::ifstream input_file{};
    std::string file_path{"../" + file_name};
    input_file.open(file_path);

    // Check if the file was opened successfully
    if (!input_file.is_open())
    {
        std::cout << "Could not open the file.\n";

        return content;
    }

    std::string line{};

    // Read the file line by line
    while (getline(input_file, line))
    {
        content.push_back(line);
    }

    // Close the file
    input_file.close();

    return content;
}
