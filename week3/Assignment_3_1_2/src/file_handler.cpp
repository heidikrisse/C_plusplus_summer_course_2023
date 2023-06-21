// file_handler.cpp

#include "../include/file_handler.h"
#include <filesystem>
#include <fstream>

// Function to check if a directory exists and create it if not.
void ensure_directory_exists(const std::string &directory_path)
{
    if (!std::filesystem::exists(directory_path))
    {
        std::filesystem::create_directory(directory_path);
    }
}

// Function to ensure a file exists, creating it if not.
void ensure_file_exists(const std::string &file_path)
{
    if (!std::filesystem::exists(file_path))
    {
        std::ofstream output_file(file_path);
    }
}
