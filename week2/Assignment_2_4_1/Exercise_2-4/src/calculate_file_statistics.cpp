// calculate_file_statistics.cpp
#include "../include/calculate_file_statistics.h"
#include <filesystem>
#include <sstream>

/* Exercise 2:
 *
 * Function to count the number of lines in the file */
int count_lines(const std::vector<std::string> &file_contents)
{
    // The number of lines is equivalent to the size of the vector
    int line_count{static_cast<int>(file_contents.size())};
    return line_count;
}

/* Exercise 3:
 *
 * Function to count the number of words in the file */
int count_words(const std::vector<std::string> &file_contents)
{
    int word_count{0};

    // Iterate over each line in the file
    for (const auto &line : file_contents)
    {
        std::istringstream line_stream{line};
        std::string word{};

        // Count every word in the line
        while (line_stream >> word)
        {
            ++word_count;
        }
    }

    return word_count;
}

/* Exercise 4:
 *
 * Function to count the number of characters in the file */
int count_chars(const std::vector<std::string> &file_contents)
{
    int char_count{0};

    // Iterate over each line in the file
    for (const auto &line : file_contents)
    {
        // Add the number of characters in the line to the total count
        char_count += line.length();
    }

    return char_count;
}

/* Exercise 5:
 *
 * Function to calculate the total size of all text files in a directory */
unsigned long long calculate_text_files_size(const std::string &dir_path)
{
    unsigned long long total_size{0};

    // Iterate over each entry in the directory
    for (const auto &entry : std::filesystem::directory_iterator("../" + dir_path))
    {
        // If the entry is a file and its extension is .txt
        if (std::filesystem::is_regular_file(entry.status()) && entry.path().extension() == ".txt")
        {
            // Add the size of the file to the total size
            total_size += std::filesystem::file_size(entry.path());
        }
    }

    return total_size;
}
