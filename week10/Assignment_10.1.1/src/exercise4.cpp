/* exercise4.cpp
 *
 * std::atomic ensures operations on the shared global variable are
 * "atomic" (indivisible and uninterruptible) => increments are done safely
 * without "race conditions" => result always 2000
 */
#include "../include/exercise4.h"
#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

static std::atomic<int> global_sum_atomic{0}; // An atomic global variable

void add_with_atomic(int increment, int times)
{
    for (int i{0}; i < times; ++i)
    {
        global_sum_atomic.fetch_add(increment, std::memory_order_relaxed);
    }
}

void run_addition_with_atomic()
{
    std::cout << "\nExercise 4:\n\n";

    const int number_of_threads{100};
    const int number_of_repeats{20};

    for (int run{0}; run < number_of_repeats; ++run)
    {
        global_sum_atomic = 0;
        std::vector<std::thread> threads;

        for (int i{0}; i < number_of_threads; ++i)
        {
            threads.push_back(std::thread(add_with_atomic, 1, 20));
        }

        for (int i{0}; i < number_of_threads; ++i)
        {
            threads[i].join();
        }

        std::cout << "Global sum with atomic: " << global_sum_atomic.load(std::memory_order_relaxed) << '\n'; // Should be always 2000 (100 x 20)
    }
}
