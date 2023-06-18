// A program that asks the user for the size of a randomly generated vector
#include <iostream>
#include <vector>
#include <cstdlib> // for rand() and srand()
#include <ctime>

// Function to ask the user for the size of the vector
std::vector<int>::size_type ask_size()
{
    std::cout << "Enter the size of the vector: ";
    size_t size{};
    std::cin >> size;

    return size;
}

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

// Function to print the size and values of the vector
void print_vector(const std::vector<int> &vec)
{
    std::cout << "Vector size is: " << vec.size() << ".\n";
    std::cout << "Vector values are: ";
    for (const int &num : vec)
    {
        std::cout << num << ", ";
    }
    // uses '\b\b' to move the cursor two places back to remove the last ","
    std::cout << "\b\b.\n";
}

int main()
{
    size_t size{ask_size()};
    std::vector<int> vec{generate_random_vector(size)};
    print_vector(vec);

    return 0;
}
