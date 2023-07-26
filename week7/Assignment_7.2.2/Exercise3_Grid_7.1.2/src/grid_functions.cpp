#include "../include/grid.h"
#include "../include/user_ui.h"

#include <iostream>

void create_and_manage_2d_grid()
{
    std::size_t rows{get_positive_input("Enter number of rows: ")};
    std::size_t cols{get_positive_input("Enter number of columns: ")};
    int grid_init_value{get_input("Enter grid initialization integer value: ")};

    Grid<int, std::size_t, std::size_t> grid2D(rows, cols, grid_init_value);
    grid2D.print_grid();

    while (true)
    {
        std::cout << "\n*** Menu to change grid values: ***\n\n";
        std::cout << "1. Change a value in the grid\n";
        std::cout << "2. Return to Main Menu\n";
        int choice = get_input("Enter your choice: ");

        if (choice == 1)
        {
            std::size_t row{get_positive_input("Enter row number (starting from 1): ")};
            std::size_t col{get_positive_input("Enter column number (starting from 1): ")};
            int value{get_input("Enter new value: ")};
            // Adjusted starting from 1, not 0, so -1 to keep the indexes correct
            grid2D.at(row - 1, col - 1) = value;
            grid2D.print_grid();
        }
        else if (choice == 2)
        {
            break;
        }
        else
        {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void create_and_manage_3d_grid()
{
    std::size_t x{get_positive_input("Enter size of dimension x: ")};
    std::size_t y{get_positive_input("Enter size of dimension y: ")};
    std::size_t z{get_positive_input("Enter size of dimension z: ")};
    int grid_init_value{get_input("Enter grid initialization integer value: ")};

    Grid<int, std::size_t, std::size_t, std::size_t> grid3D(x, y, z, grid_init_value);
    grid3D.print_grid();

    while (true)
    {
        std::cout << "\n*** Menu to change grid values: ***\n\n";
        std::cout << "1. Change a value in the grid\n";
        std::cout << "2. Return to Main Menu\n\n";
        int choice{get_input("Enter your choice: ")};

        if (choice == 1)
        {
            std::size_t x{get_positive_input("Enter x index (starting from 1): ")};
            std::size_t y{get_positive_input("Enter y index (starting from 1): ")};
            std::size_t z{get_positive_input("Enter z index (starting from 1): ")};
            int value{get_input("Enter new value: ")};
            // Adjusted starting from 1
            grid3D.at(x - 1, y - 1, z - 1) = value;
            grid3D.print_grid();
        }
        else if (choice == 2)
        {
            break;
        }
        else
        {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
