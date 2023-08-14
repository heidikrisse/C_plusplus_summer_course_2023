/* exercise2.cpp
 *
 * Multiple threads are accessing and updating a shared global
 * variable at the same time => can lead to "race conditions" where the
 * result is unpredictable (can be sometimes something else than 2000)
 * because threads are "racing" to update the variable. */
#include "../include/exercise2.h"

#include <iostream>
#include <thread>
#include <vector>

// A global static variable
static int global_sum{0};

void add_without_locks(int increment, int times)
{
    for (int i{0}; i < times; ++i)
    {
        global_sum += increment;
    }
}

void run_addition_without_locks()
{
    std::cout << "\nExercise 2:\n\n";

    const int number_of_threads{100};
    const int number_of_repeats{20};

    for (int run{0}; run < number_of_repeats; ++run)
    {
        global_sum = 0;
        std::vector<std::thread> threads;

        for (int i{0}; i < number_of_threads; ++i)
        {
            threads.push_back(std::thread(add_without_locks, 1, 20));
        }

        for (int i{0}; i < number_of_threads; ++i)
        {
            threads[i].join();
        }

        std::cout << run + 1 << ". Global sum without locks: " << global_sum << '\n'; // Should be usually 2000 (100 x 20), but "race condition" can occur
    }
}
