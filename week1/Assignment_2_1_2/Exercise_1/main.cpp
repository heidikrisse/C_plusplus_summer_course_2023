/* A program to create a vector<int> with 10 numbers in it and
 * use std::partition to separate the even and odd numbers*/
#include <iostream>
#include <vector>
#include <algorithm> // for std::partition
#include <random>    // for std::mt19937 and std::uniform_int_distribution

// Function to generate a random vector of the given size
std::vector<int> generate_random_vector(size_t size)
{
    std::random_device rd; // to seed the Mersenne twister engine
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 99); // uniformly distributed in [0, 99]

    std::vector<int> vec(size);
    for (int &num : vec)
    {
        num = dist(mt);
    }
    return vec;
}

// Function to partition even and odd numbers in the vector
void partition_even_odd(std::vector<int> &vec)
{
    auto partition_point{std::partition(vec.begin(), vec.end(), [](int num)
                                        { return num % 2 == 0; })};
}

// Function to print the vector
void print_vector(const std::vector<int> &vec)
{
    for (const int &num : vec)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main()
{
    size_t size{10}; // vector size = 10
    std::vector<int> vec{generate_random_vector(size)};
    std::cout << "Vector values before partitioning: ";
    print_vector(vec);

    partition_even_odd(vec);
    std::cout << "Vector values after partitioning: ";
    print_vector(vec);

    return 0;
}
