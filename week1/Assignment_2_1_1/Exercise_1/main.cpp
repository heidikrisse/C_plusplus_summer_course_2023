// A program to create an array with 10 random numbers in it
#include <iostream>
#include <array>
#include <cstdlib> // for rand() and srand()
#include <ctime>

int main()
{
    // Random number generation
    srand(std::time(nullptr));

    // Initializes an array with 10 integers
    std::array<int, 10> arr{};

    for (int &num : arr)
    {
        /* Assigns a random integer between 0-99 to the varaible 'num'.
         * std::rand() generates a pseudo-random number between 0 and RAND_MAX,
         * using % 100 limits the maximum value to 99. */
        num = std::rand() % 100;
    }

    // Print the array
    for (const int &num : arr)
    {
        std::cout << num << "\n";
    }

    return 0;
}
