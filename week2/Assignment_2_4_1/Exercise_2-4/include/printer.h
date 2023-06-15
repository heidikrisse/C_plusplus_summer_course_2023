// printer.h
#ifndef PRINTER_H
#define PRINTER_H

#include <string>

/* Exercise 1:
 * Print the contents of the file to the console */
void print_file_content(const std::string &file_path);

/* Exercise 2:
 * Print the number of lines in the file to the console */
void print_line_count(const std::string &file_path);

/* Exercise 3:
 * Print the number of words in the file to the console */
void print_word_count(const std::string &file_path);

/* Exercise 4:
 * Print the number of characters in the file to the console*/
void print_char_count(const std::string &file_path);

/* Exercise 5:
 * Function to print the total size of all text files in a directory */
void print_directory_size(const std::string &dir_path);

// Function to print usage instructions
void print_usage_instructions();

#endif
