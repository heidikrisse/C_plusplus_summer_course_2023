// A program that calculates the sum of elements in a vector which is automatically filled with 10 random numbers
#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate
#include <cstdlib> // for rand() and srand()
#include <ctime>

std::vector<int> generate_random_vector()
{
    // Random number generator
    srand(std::time(nullptr));
    // Initialize vector of size 10
    std::vector<int> vec(10);
    // Fills the vector with random numbers between 0-99
    for (int &num : vec)
    {
        num = rand() % 100;
    }
    return vec;
}

// Function to calculate the sum of elements in the vector
int sum_of_elements(const std::vector<int> &vec)
{
    return std::accumulate(vec.begin(), vec.end(), 0);
}

// Function to print
void print_sum_calculation(const std::vector<int> &vec)
{
    std::cout << "Sum of all elements in a random array is:\n";

    for (size_t i{0}; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i != vec.size() - 1)
        {
            std::cout << " + ";
        }
    }
    std::cout << " = " << sum_of_elements(vec) << "\n";
}

int main()
{
    std::vector<int> vec{generate_random_vector()};
    print_sum_calculation(vec);

    return 0;
}
