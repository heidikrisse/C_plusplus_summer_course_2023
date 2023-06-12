/* A program to create two std::vector<int> and fill them with random amount
 * of random numbers. Use std::set_intersection to find common elements
 * between them.*/
#include <iostream>
#include <vector>
#include <algorithm> // for std::set_intersection
#include <cstdlib>   // for rand() and srand()
#include <ctime>

// Function to ask the size of the vector
size_t ask_size()
{
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

// Function to print the vector
void print_vector(const std::vector<int> &vec)
{
    std::cout << "Vector values are: ";
    for (const int &num : vec)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

// Function to print common elements
void print_common_elements(const std::vector<int> &vec)
{
    std::cout << "Common elements are: ";
    if (vec.empty())
    {
        std::cout << "No common elements found!\n";
    }
    else
    {
        for (const int &num : vec)
        {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }
}

// Function to find common elements between two vectors
std::vector<int> find_common_elements(const std::vector<int> &vec1, const std::vector<int> &vec2)
{
    std::vector<int> common_elements{};
    std::set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), std::back_inserter(common_elements));
    return common_elements;
}

int main()
{
    std::cout << "Enter the size of the vector 1: ";
    size_t size1{ask_size()};
    // Generate a random vector 1
    std::vector<int> vec1{generate_random_vector(size1)};

    std::cout << "Enter the size of the vector 2: ";
    size_t size2{ask_size()};
    // Generate a randon vector 2
    std::vector<int> vec2{generate_random_vector(size2)};

    // Print the vectors
    std::cout << "Vector 1: ";
    print_vector(vec1);
    std::cout << "Vector 2: ";
    print_vector(vec2);

    // Find the common elements
    std::vector<int> common_elements{find_common_elements(vec1, vec2)};
    // Print the common elements
    print_common_elements(common_elements);

    return 0;
}
