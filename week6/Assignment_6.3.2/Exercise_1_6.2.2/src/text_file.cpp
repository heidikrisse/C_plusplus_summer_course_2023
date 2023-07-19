// text_file.cpp
#include "text_file.h"

#include <iostream>
#include <stdexcept> // for std::runtime_error

TextFile::TextFile(const char *filename, const char *mode)
{
    std::string data_folder_path{"../data/"};
    std::string file_path{data_folder_path + filename};
    file_handle = fopen(file_path.c_str(), mode);
    if (!file_handle)
    {
        // Create the file if it doesn't exist
        file_handle = fopen(file_path.c_str(), "w");
        if (!file_handle)
        {
            throw std::runtime_error("Failed to create the text file.\n");
        }
    }
}

TextFile::~TextFile()
{
    if (file_handle)
    {
        std::fclose(file_handle);
    }
}

// Function to read the next line of the text file
std::string TextFile::read_next_line()
{
    std::string line{};
    // Stores the symbol read from the file
    int symbol{};

    // Read until the end of line or end of file
    while ((symbol = std::fgetc(file_handle)) != EOF && symbol != '\n')
    {
        line += static_cast<char>(symbol);
    }

    return line;
}

// Function to print the text file size
void TextFile::print_file_size()
{
    // Save current position in file
    long current_position{std::ftell(file_handle)};

    // Go to end of file
    std::fseek(file_handle, 0, SEEK_END);

    // Get position at end of file (file size)
    long size{std::ftell(file_handle)};

    // Return to saved position
    std::fseek(file_handle, current_position, SEEK_SET);

    std::cout << "Text file size: " << size << " bytes\n";
}
