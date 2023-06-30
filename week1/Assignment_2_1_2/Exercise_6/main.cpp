/* A program to create a new program that will create a vector of random
 * size, filled with random numbers between 1 and 100 and
 * add a function that will output the smallest and largest number in the array.*/
#include <iostream>
#include <random> // for std::mt19937 and std::uniform_int_distribution

// Function to generate a random array of the given size, filled with random numbers between 1 and 100
int *generate_random_array(size_t size)
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> num_dist(1, 100); // uniform distribution between 1 and 100

    int *arr{new int[size]};
    for (size_t i{0}; i < size; ++i)
    {
        arr[i] = num_dist(rng); // Random number between 1 and 100
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
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> size_dist(1, 10);

    size_t size = static_cast<size_t>(size_dist(rng));
    int *arr{generate_random_array(size)};

    print_array(arr, size);
    find_min_max_values(arr, size);

    delete[] arr; // Deallocate the dynamic memory

    return 0;
}
