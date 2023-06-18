/* A program that calculates the product of elements in a randomly generated
 * array */
#include <iostream>
#include <array>
#include <numeric> // for std::accumulate
#include <cstdlib> // for rand() and srand()
#include <ctime>

std::array<int, 10> generate_random_array()
{
    srand(std::time(nullptr));
    std::array<int, 10> arr;
    for (int &num : arr)
    {
        num = rand() % 10 + 1; // possible random numbers: 1-10
    }
    return arr;
}

// Function to calculate the product of the elements in the array
int product_of_elements(const std::array<int, 10> &arr)
{
    return std::accumulate(arr.begin(), arr.end(), 1, std::multiplies<int>());
}

// Function to prints the result
void print_product_calculation(const std::array<int, 10> &arr)
{
    std::cout << "Product of all elements in a random array is:\n";
    for (size_t i{0}; i < arr.size(); ++i)
    {
        std::cout << arr[i];
        if (i != arr.size() - 1)
        {
            std::cout << " * ";
        }
    }
    std::cout << " = " << product_of_elements(arr) << "\n";
}

int main()
{
    std::array<int, 10> arr{generate_random_array()};
    print_product_calculation(arr);

    return 0;
}
