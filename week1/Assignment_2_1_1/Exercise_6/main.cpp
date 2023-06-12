// A program that calculates the smallest and the largest number of a
// randomly created list
#include <iostream>
#include <list>
#include <cstdlib> // for rand() and srand()
#include <ctime>

// Function to find and print the smallest and the largest values of the list
void find_min_max_values(const std::list<int> &lst)
{
    int min_value{lst.front()}; // alustetaan listan ensimmäisellä alkiolla
    int max_value{lst.front()};

    for (const int &num : lst)
    {
        if (num < min_value)
            min_value = num;
        if (num > max_value)
            max_value = num;
    }

    std::cout << "Smallest number in the list: " << min_value << "\n";
    std::cout << "Largest number in the list: " << max_value << "\n";
}

// Function to ask the user for the size of the list
std::list<int>::size_type ask_size()
{
    std::cout << "Enter the size of the random list: ";
    size_t size{};
    std::cin >> size;

    return size;
}

// Function to create a list with random numbers
std::list<int> generate_random_list(int size)
{
    srand(std::time(nullptr));
    std::list<int> lst(size);
    for (int &num : lst)
    {
        num = rand() % 100;
    }
    return lst;
}

// Function to print the list
void print_list(const std::list<int> &lst)
{
    std::cout << "List values are: ";
    for (const int &num : lst)
    {
        std::cout << num << ", ";
    }
    // uses '\b\b' to move the cursor two places back to remove the last ","
    std::cout << "\b\b.\n";
}

int main()
{
    size_t size{ask_size()};
    std::list<int> lst{generate_random_list(size)};
    print_list(lst);
    find_min_max_values(lst);

    return 0;
}
