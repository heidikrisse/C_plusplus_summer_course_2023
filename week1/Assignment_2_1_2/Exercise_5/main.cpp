/* A program to create a new program that will create a vector of random
 * size, filled with random numbers between 1 and 100.*/
#include <iostream>
#include <vector>
#include <random> // for std::mt19937 and std::uniform_int_distribution

// Function to generate a vector of random size, filled with random numbers between 1 and 100
std::vector<int> generate_random_vector()
{
    std::random_device rd;                               // Will be used to obtain a seed for the random number engine
    std::mt19937 rng(rd());                              // Mersenne Twister 19937 generator, seeded with rd()
    std::uniform_int_distribution<int> size_dist(1, 10); // uniform distribution between 1 and 10, inclusive
    std::uniform_int_distribution<int> num_dist(1, 100); // uniform distribution between 1 and 100, inclusive

    // Random size between 1 and 10 to limit the maximum size of the vector
    size_t size = static_cast<size_t>(size_dist(rng));
    std::vector<int> vec(size);
    for (int &num : vec)
    {
        // Random number between 1 and 100
        num = num_dist(rng);
    }
    return vec;
}

// Function to print the vector
void print_vector(const std::vector<int> &vec)
{
    std::cout << "Vector size is: " << vec.size() << ".\n";
    std::cout << "Vector values are: ";
    for (const int &num : vec)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::vector<int> vec{generate_random_vector()};
    print_vector(vec);

    return 0;
}
