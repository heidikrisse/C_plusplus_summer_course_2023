/* A program that checks if a given number exists in a vector used in
 * the exercise 1 */
#include <iostream>
#include <array>
#include <cstdlib> // for rand() and srand()
#include <ctime>
#include <algorithm> // for std::find

// Function that receives an std::array and a number, checks whether the number is in the array and returns a boolean array
bool contains(const std::array<int, 10> &arr, int number)
{
    return std::find(arr.begin(), arr.end(), number) != arr.end();
}

// Function to print the randomly generated array of 10 integers
void print_array(const std::array<int, 10> &arr)
{
    std::cout << "Array values are: ";
    for (const int &num : arr)
    {
        std::cout << num << ", ";
    }
    std::cout << "\b\b.\n";
}

// Function to ask user input
int ask_number()
{
    std::cout << "Enter a number to search in the array: ";
    int number{};
    std::cin >> number;

    return number;
}

// Function to print results
void print_result(const std::array<int, 10> &arr, int number)
{
    print_array(arr);
    std::cout << (contains(arr, number) ? "Number " + std::to_string(number) + " was found in the array!\n"
                                        : "Number " + std::to_string(number) + " was not found in the array!\n");
}

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

    // Ask the user for a number to search
    int search_number{ask_number()};

    print_result(arr, search_number);

    return 0;
}
