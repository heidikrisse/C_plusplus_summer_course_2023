// printer.cpp
#include "../include/file_reader.h"
#include "../include/calculate_file_statistics.h"
#include "../include/printer.h"

#include <iostream>

// Function to print the contents of the file to the console
void print_file_content(const std::string &file_name)
{
    auto file_contents{read_file(file_name)};
    for (const auto &line : file_contents)
    {
        std::cout << line << '\n';
    }
}

// Function to print the number of lines in the file to the console
void print_line_count(const std::string &file_name)
{
    auto file_contents{read_file(file_name)};
    std::cout << "The file contains " << count_lines(file_contents) << " lines.\n";
}

// Function to print the number of words in the file to the console
void print_word_count(const std::string &file_name)
{
    auto file_contents{read_file(file_name)};
    std::cout << "The file contains " << count_words(file_contents) << " words.\n";
}

// Function to print the number of characters in the file to the console
void print_char_count(const std::string &file_name)
{
    auto file_contents{read_file(file_name)};
    std::cout << "The file contains " << count_chars(file_contents) << " characters.\n";
}

// Function to print the total size of all text files in a directory
void print_directory_size(const std::string &dir_path)
{
    unsigned long long total_size{calculate_text_files_size(dir_path)};
    std::cout << "The total size of all text files in the directory is: " << total_size << " bytes.\n";
}

// Function to print usage instructions
void print_usage_instructions()
{
    std::cout << "Use one of the following commands:\n\n";

    std::cout << "\t<file_name> : Prints the contents of the provided file.\n";
    std::cout << "\t-l or --lines <file_name> : Prints the number of lines in the specified text file.\n ";
    std::cout << "\t-w or --words <file_name>: Prints the number of words in the specified text file.\n";
    std::cout << "\t-c or --chars <file_name>: Prints the number of characters in the specified text file.\n";
    std::cout << "\t-s or --size <directory_path>: Prints the total size of all text files in the specified directory.\n\n";

    std::cout << "Example usage:\n\n";
    std::cout << "\t./FileReader myfile.txt\n";
    std::cout << "\t./FileReader --lines myfile.txt\n";
    std::cout << "\t./FileReader --words myfile.txt\n";
    std::cout << "\t./FileReader --chars myfile.txt\n";
    std::cout << "\t./FileReader --size my_directory/\n\n";
}
