/* A program to create a new program that will create a vector of random
 * size, filled with random numbers between 1 and 100.*/
#include <iostream>
#include <vector>
#include <cstdlib> // for rand() and srand()
#include <ctime>

// Function to generate a vector of random size, filled with random numbers between 1 and 100
std::vector<int> generate_random_vector()
{
    srand(std::time(nullptr));
    // Random size between 1 and 10 to limit the maximum size of the vector
    size_t size{static_cast<size_t>(rand() % 10 + 1)};
    std::vector<int> vec(size);
    for (int &num : vec)
    {
        // Random number between 1 and 100
        num = rand() % 100 + 1;
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
