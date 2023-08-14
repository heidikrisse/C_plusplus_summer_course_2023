// log.cpp
#include "../include/log.h"

#include <iostream>
#include <atomic>
#include <mutex>
#include <thread>
#include <chrono>

// A vector to store log messages
static std::vector<std::string> log_storage;

// A mutex to ensure thread-safe operations on the log
static std::mutex log_mutex;
// set to true initially
std::atomic<bool> is_running{true};

// Function to add a message to the log storage
void add_to_log(const std::string &message)
{
    // Lock the mutex to ensure thread-safe access to the log
    std::lock_guard<std::mutex> lock(log_mutex);
    // Add the message to the log storage
    log_storage.push_back(message);
}

// Function to add time-specific messages to the log every second
void add_message_to_log()
{
    int seconds{0};
    while (is_running.load())
    {
        // Pause this thread for one second
        std::this_thread::sleep_for(std::chrono::seconds(1));
        ++seconds;
        if (seconds == 1)
        {
            add_to_log("one second passed");
        }
        else
        {
            add_to_log(std::to_string(seconds) + " seconds passed");
        }
    }
}

// Function to print all messages in the log storage
void print_log()
{
    // Lock the mutex to ensure thread-safe access to the log
    std::lock_guard<std::mutex> lock(log_mutex);
    // Loop through each message in the log and print it
    for (const auto &entry : log_storage)
    {
        std::cout << entry << '\n';
    }
}
