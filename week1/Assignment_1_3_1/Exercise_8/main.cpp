#include <iostream>

// Function to dynamically allocate memory for an array
int *createDynamicArray(int size)
{
    int *arr{new int[size]{}};
    for (int i{0}; i < size; ++i)
    {
        arr[i] = i + 1;
    }
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

    int *dynamicArray{createDynamicArray(size)};
    printArray(dynamicArray, size);

    delete[] dynamicArray;
    return 0;
}
