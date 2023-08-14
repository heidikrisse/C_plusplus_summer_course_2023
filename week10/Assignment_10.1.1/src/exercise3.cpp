/* exercise3.cpp
 *
 * Mutex is used to ensure that only one thread can access the shared
 * variable at a time => prevents "race conditions" => result always 2000 */
#include "../include/exercise3.h"
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

// A global static variable
static int global_sum_mutex{0};
static std::mutex sum_mutex;

void add_with_mutex(int increment, int times)
{
    for (int i{0}; i < times; ++i)
    {
        std::lock_guard<std::mutex> sum_lock(sum_mutex);
        global_sum_mutex += increment;
    }
}

void run_addition_with_mutex()
{
    std::cout << "\nExercise 3:\n\n";

    const int number_of_threads{100};
    const int number_of_repeats{20};

    for (int run{0}; run < number_of_repeats; ++run)
    {
        global_sum_mutex = 0;
        std::vector<std::thread> threads;

        for (int i{0}; i < number_of_threads; ++i)
        {
            threads.push_back(std::thread(add_with_mutex, 1, 20));
        }

        for (int i{0}; i < number_of_threads; ++i)
        {
            threads[i].join();
        }

        std::cout << "Global sum with mutex: " << global_sum_mutex << '\n'; // Should be always 2000 (100 x 20)
    }
}
