// calculate_file_statistics.h
#ifndef CALCULATE_FILE_STATISTICS_H
#define CALCULATE_FILE_STATISTICS_H

#include <vector>
#include <string>

// Calculate the number of lines in the file
int count_lines(const std::vector<std::string> &file_contents);

// Calculate the number of words in the file
int count_words(const std::vector<std::string> &file_contents);

// Calculate the number of characters in the file
int count_chars(const std::vector<std::string> &file_contents);

// Calculate the total size of all text files in a directory
unsigned long long calculate_text_files_size(const std::string &dir_path);

#endif
