// main.cpp
#include "include/grid.h"
#include "include/user_ui.h"
#include <iostream>

int main()
{
    std::size_t width{get_positive_input("Enter grid width: ")};
    std::size_t height{get_positive_input("Enter grid height: ")};
    int grid_init_value{get_input("Enter grid initialization integer value: ")};

    // The type of the grid is integers
    Grid<int> grid(width, height, grid_init_value);

    grid.print(); // Should show a grid initialized with zeros

    return 0;
}
