/* A program to create a vector with 10 random elements in it and
 * rotate elements to the right by 3 positions with std::rotate.*/
#include <iostream>
#include <vector>
#include <algorithm> // for std::rotate
#include <cstdlib>   // for rand() and srand()
#include <ctime>

// Function to generate a random vector of the given size
std::vector<int> generate_random_vector(size_t size)
{
    srand(std::time(nullptr));
    std::vector<int> vec(size);
    for (int &num : vec)
    {
        num = rand() % 100;
    }
    return vec;
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

    std::cout << "Vector values before rotation: ";
    print_vector(vec);

    std::cout << "Vector values after rotation: ";
    // Rotate elements to the right by 3 positions
    std::rotate(vec.rbegin(), vec.rbegin() + 3, vec.rend());
    print_vector(vec);

    return 0;
}
