/* A program to create a new program that will create a vector of random
 * size, filled with random numbers between 1 and 100 and
 * add a function that will output the smallest and largest number in the array.*/
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>
#include <algorithm> // for std::minmax_element

// Function to generate a random array of the given size, filled with random numbers between 1 and 100
int *generate_random_array(size_t size)
{
    srand(std::time(nullptr));
    int *arr{new int[size]};
    for (size_t i{0}; i < size; ++i)
    {
        arr[i] = rand() % 100 + 1; // Random number between 1 and 100
    }
    return arr;
}

// Function to print the array
void print_array(const int *arr, size_t size)
{
    std::cout << "Array values: ";
    for (size_t i{0}; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

// Function to find the smallest and largest numbers in the array
void find_min_max_values(const int *arr, size_t size)
{
    int min_value{arr[0]};
    int max_value{arr[0]};

    for (size_t i{1}; i < size; ++i)
    {
        if (arr[i] < min_value)
        {
            min_value = arr[i];
        }
        else if (arr[i] > max_value)
        {
            max_value = arr[i];
        }
    }

    std::cout << "Smallest number in the array: " << min_value << "\n";
    std::cout << "Largest number in the array: " << max_value << "\n";
}

int main()
{
    // Random size between 1 and 10
    size_t size{static_cast<size_t>(rand() % 10 + 1)};
    int *arr{generate_random_array(size)};

    print_array(arr, size);
    find_min_max_values(arr, size);

    delete[] arr; // Deallocate the dynamic memory

    return 0;
}
