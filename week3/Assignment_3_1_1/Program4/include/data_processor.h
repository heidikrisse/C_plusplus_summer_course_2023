// data_rpcessor.h
#ifndef DATA_PROCESSOR_H
#define DATA_PROCESSOR_H

// Function to get an integer from user input
int get_number(const std::string &prompt);

// Function to get a string from user input
std::string get_string(const std::string &prompt);

// Function overload (named same):

// Function to process an integer
void process_data(int number);

// Function to process a string
void process_data(const std::string &str);

#endif
