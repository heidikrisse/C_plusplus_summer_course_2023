/* A program to create a std::list<int> with 10 elements and
 * use std::adjacent_find to find the first two adjacent elements that
 * are equal*/
#include <iostream>
#include <list>
#include <algorithm> // for std::adjacent_find
#include <random>    // for std::mt19937 and std::uniform_int_distribution

// Function to generate a list with 10 random elements
std::list<int> generate_random_list()
{
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 rng(rd()); // Initialize Mersenne Twister pseudorandom number generator

    std::uniform_int_distribution<int> dist(0, 99); // Uniform distribution between 0 and 99

    std::list<int> lst;
    for (int i{0}; i < 10; ++i)
    {
        lst.push_back(dist(rng)); // Generate random numbers with the uniform distribution
    }
    return lst;
}

// Function to print the list
void print_list(const std::list<int> &lst)
{
    std::cout << "List values: ";
    for (const int &num : lst)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::list<int> lst{generate_random_list()};
    print_list(lst);

    // Find the first two adjacent elements that are equal
    auto it{std::adjacent_find(lst.begin(), lst.end())};
    if (it != lst.end())
    {
        std::cout << "First two adjacent elements that are equal are: " << *it << " " << *(std::next(it)) << "\n";
    }
    else
    {
        std::cout << "No adjacent elements were found in the list.\n";
    }

    return 0;
}
