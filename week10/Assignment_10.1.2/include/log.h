// log.h
#ifndef LOG_H
#define LOG_H

#include <string>
#include <vector>
#include <atomic>

extern std::atomic<bool> is_running;

// Function to add a message to the log
void add_to_log(const std::string &message);

// Function to add a time-specific message to the log every second
void add_message_to_log();

// Function to print the log
void print_log();

#endif
