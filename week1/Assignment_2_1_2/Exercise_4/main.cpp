/* A program to create a std::list<int> with 10 elements and
 * use std::adjacent_find to find the first two adjacent elements that
 * are equal*/
#include <iostream>
#include <list>
#include <algorithm> // for std::adjacent_find
#include <cstdlib>   // for rand() and srand()
#include <ctime>

// Function to generate a list with 10 random elements
std::list<int> generate_random_list()
{
    srand(std::time(nullptr));
    std::list<int> lst;
    for (int i{0}; i < 10; ++i)
    {
        lst.push_back(rand() % 100);
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
        std::cout << "First two adjacent elements that are equal are: " << *it << " " << *(++it) << "\n";
    }
    else
    {
        std::cout << "No adjacent elements were found in the list.\n";
    }

    return 0;
}
