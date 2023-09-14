// exercise1.cpp
#include "../include/exercise1.h"

#include <iostream>
#include <thread>

// Function to print "Hello, "
void print_hello()
{
    std::cout << "Hello, ";
}

// Function to print "world!\n"
void print_world()
{
    std::cout << "world!\n";
}

void print_hello_world()
{
    std::cout << "Exercise 1:\n\n";

    const int number_of_repeats{20};
    for (int i{0}; i < number_of_repeats; ++i)
    {
        std::cout << '\n'
                  << i + 1 << ". ";
        std::thread thread1(print_hello);
        std::thread thread2(print_world);

        thread1.join();
        thread2.join();
    }

    std::cout << '\n';
}
