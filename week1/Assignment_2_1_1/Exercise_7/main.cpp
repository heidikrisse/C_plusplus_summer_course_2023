// A program that removes all instances of a value from a vector
#include <iostream>
#include <vector>
#include <algorithm> // for std::remove
#include <cstdlib>   // for rand() and srand()
#include <ctime>

// Function to generate a random vector with size 10 and values between 0-10
std::vector<int> generate_random_vector()
{
    srand(std::time(nullptr));
    std::vector<int> vec(10);
    for (int &num : vec)
    {
        num = rand() % 10; // limited to 10
    }
    return vec;
}

// FUnction to remove the given value
void remove_value(std::vector<int> &vec, int value)
{
    auto new_end = std::remove(vec.begin(), vec.end(), value);
    if (new_end != vec.end())
    {
        vec.erase(new_end, vec.end());
        std::cout << "Value " << value << " was removed.\n";
    }
    else
    {
        std::cout << "Value " << value << " was not found.\n";
    }
}

// Function to print the vector
void print_vector(const std::vector<int> &vec)
{
    for (size_t i{0}; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i != vec.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "\n";
}

// Function to ask the user the number to be removed
int ask_number_to_remove()
{
    std::cout << "Enter the number you want to remove: ";
    int number{};
    std::cin >> number;
    return number;
}

int main()
{
    std::vector<int> vec{generate_random_vector()};
    std::cout << "Randomly generated vector: \n";
    print_vector(vec);

    int number_to_remove{ask_number_to_remove()};
    remove_value(vec, number_to_remove);

    std::cout << "Vector after removal: \n";
    print_vector(vec);

    return 0;
}
