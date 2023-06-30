/* A program to create a vector with 10 random elements in it and
 * rotate elements to the right by 3 positions with std::rotate.*/
#include <iostream>
#include <vector>
#include <algorithm> // for std::rotate
#include <random>    // for std::mt19937 and std::uniform_int_distribution

// Function to generate a random vector of the given size
std::vector<int> generate_random_vector(size_t size)
{
    std::random_device rd;
    std::mt19937 mt(rd());                          // use Mersenne twister engine seeded with rd()
    std::uniform_int_distribution<int> dist(0, 99); // distribute results between 0 and 99 inclusive

    std::vector<int> vec(size);
    for (int &num : vec)
    {
        num = dist(mt);
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
