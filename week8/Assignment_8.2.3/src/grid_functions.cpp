// grid_functions.cpp
#include "../include/grid_functions.h"
#include "../include/grid.h"
#include "../include/user_ui.h"

#include <iostream>
#include <cstddef>

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
        std::cout << "2. Copy and move Grid\n";
        std::cout << "3. Return to Main Menu\n";
        int choice = get_input("Enter your choice: ");

        if (choice == 1)
        {
            change_2d_grid_value(grid2D);
        }
        else if (choice == 2)
        {
            copy_and_move_2d_grid(grid2D);
        }
        else if (choice == 3)
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
        std::cout << "\n*** Grid Operations Menu: ***\n\n";
        std::cout << "1. Change a value in the grid\n";
        std::cout << "2. Copy and move Grid\n";
        std::cout << "3. Return to Main Menu\n\n";
        int choice{get_input("Enter your choice: ")};

        if (choice == 1)
        {
            change_3d_grid_value(grid3D);
        }
        else if (choice == 2)
        {
            copy_and_move_3d_grid(grid3D);
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

// Function to change 2D grid values
void change_2d_grid_value(Grid<int, std::size_t, std::size_t> &grid2D)
{
    std::size_t row{get_positive_input("Enter row number (starting from 1): ")};
    std::size_t col{get_positive_input("Enter column number (starting from 1): ")};
    int value{get_input("Enter new value: ")};
    // Adjusted starting from 1, not 0, so -1 to keep the indexes correct
    grid2D.at(row - 1, col - 1) = value;
    grid2D.print_grid();
}

// Function to change 3D grid values
void change_3d_grid_value(Grid<int, std::size_t, std::size_t, std::size_t> grid3D)
{
    std::size_t x{get_positive_input("Enter x index (starting from 1): ")};
    std::size_t y{get_positive_input("Enter y index (starting from 1): ")};
    std::size_t z{get_positive_input("Enter z index (starting from 1): ")};
    int value{get_input("Enter new value: ")};
    // Adjusted starting from 1
    grid3D.at(x - 1, y - 1, z - 1) = value;
    grid3D.print_grid();
}

void copy_and_move_2d_grid(Grid<int, std::size_t, std::size_t> &grid2D)
{
    std::cout << "\n*** Copy and Move 2D Grid Menu: ***\n\n";
    std::cout << "1. Copy grid\n";
    std::cout << "2. Move grid\n";
    std::cout << "3. Return to Operations Menu\n\n";
    int choice = get_input("Enter your choice: ");

    switch (choice)
    {
    case 1:
    {
        // To copy:
        Grid<int, std::size_t, std::size_t> grid2D_copy = grid2D;
        std::cout << "Grid copied.\n\n";
        std::cout << "Original 2D grid:\n";
        grid2D.print_grid();
        std::cout << '\n';
        std::cout << "Copied 2D grid:\n";
        grid2D_copy.print_grid();

        break;
    }
    case 2:
    {
        // To move
        Grid<int, std::size_t, std::size_t> grid2D_moved = std::move(grid2D);
        std::cout << "Grid moved. (Original grid is now empty.)\n\n";
        // std::cout << "Original 2D grid:\n";
        // grid2D.print_grid(); // Segmentation fault because the grid is moved
        std::cout << "Moved 2D grid:\n";
        grid2D_moved.print_grid();

        break;
    }
    case 3:
    {

        return;
    }
    default:
    {
        std::cout << "Invalid choice. Please try again.\n";

        break;
    }
    }
}

void copy_and_move_3d_grid(Grid<int, std::size_t, std::size_t, std::size_t> grid3D)
{
    std::cout << "\n*** Copy and Move 3D Grid Menu: ***\n\n";
    std::cout << "1. Copy grid\n";
    std::cout << "2. Move grid\n";
    std::cout << "3. Return to Grid Operations Menu\n\n";
    int choice = get_input("Enter your choice: ");

    switch (choice)
    {
    case 1:
    {
        // To copy:
        Grid<int, std::size_t, std::size_t, std::size_t> grid3D_copy = grid3D;
        std::cout << "Grid copied.\n\n";
        std::cout << "Original 3D grid:\n";
        grid3D.print_grid();
        std::cout << '\n';
        std::cout << "Copied 3D grid:\n";
        grid3D_copy.print_grid();

        break;
    }
    case 2:
    {
        // To move
        Grid<int, std::size_t, std::size_t, std::size_t> grid3D_moved = std::move(grid3D);
        std::cout << "Grid moved. (Original grid is now empty.)\n\n";
        // std::cout << "Original 3D grid:\n";
        // grid3D.print_grid(); // Segmentation fault as it is moved
        std::cout << "Moved 3D grid:\n";
        grid3D_moved.print_grid();

        break;
    }
    case 3:
    {

        return;
    }
    default:
    {
        std::cout << "Invalid choice. Please try again.\n";

        break;
    }
    }
}
