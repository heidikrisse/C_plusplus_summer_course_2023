// get_array_input.cpp
#include <iostream>

int *get_array_from_user(int &length)
{
    std::cout << "Enter the length of the array: ";
    std::cin >> length;

    int *array{new int[length]};
    for (int i{0}; i < length; ++i)
    {
        std::cout << "Enter the " << i + 1 << ". value of the array: ";
        std::cin >> array[i];
    }

    return array;
}
