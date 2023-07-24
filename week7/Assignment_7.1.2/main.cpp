// main.cpp
#include "include/grid.h"
#include <iostream>

int main()
{
    std::cout << "Enter grid width: ";
    std::size_t width{};
    std::cin >> width;

    std::cout << "Enter grid height: ";
    std::size_t height{};
    std::cin >> height;

    std::cout << "Enter grid initialization integer value: ";
    int grid_init_value{};
    std::cin >> grid_init_value;
    // The type of the grid is integers
    Grid<int> grid(width, height, grid_init_value);

    grid.print(); // Should show a grid initialized with zeros

    return 0;
}
