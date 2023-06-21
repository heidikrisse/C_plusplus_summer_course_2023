// file_handler.h
#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <string>

// Function to check if a directory exists and create it if not.
void ensure_directory_exists(const std::string &directory_path);

// Function to ensure a file exists, creating it if not.
void ensure_file_exists(const std::string &file_path);

#endif // FILE_HANDLER_H
