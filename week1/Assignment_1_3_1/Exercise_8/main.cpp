#include <iostream>

// Function to dynamically allocate memory for an array
int *createDynamicArray(int size)
{
    /* Dynamically allocate memory for an array
     * The lifetime of this array starts here */
    int *arr{new int[size]{}};
    for (int i{0}; i < size; ++i)
    {
        arr[i] = i + 1;
    }
    // Returns the pointer to the dynamically allocated array
    return arr;
}

// Function to print the values in the array
void printArray(int *arr, int size)
{
    for (int i{0}; i < size; ++i)
    {
        std::cout << arr[i] << '\n';
    }
}

int main()
{
    std::cout << "Enter the size of the array: ";
    int size{};
    std::cin >> size;

    // Receive the pointer to the dynamically allocated array
    int *dynamicArray{createDynamicArray(size)};
    printArray(dynamicArray, size);

    /* Deallocate the memory
     * The lifetime of the array ends here */
    delete[] dynamicArray;

    return 0;
}
