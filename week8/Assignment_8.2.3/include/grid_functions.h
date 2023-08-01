// grid_functions.h
#ifndef GRID_FUNCTIONS_H
#define GRID_FUNCTIONS_H

#include "grid.h"
#include <cstddef>

// Function to create and manage 2D Grid
void create_and_manage_2d_grid();

// Function to create and manage 3D Grid
void create_and_manage_3d_grid();

// Function to change a value in the 2D grid
void change_2d_grid_value(Grid<int, std::size_t, std::size_t> &grid2D);

// Function to change a value in the 3D grid
void change_3d_grid_value(Grid<int, std::size_t, std::size_t, std::size_t> grid3D);

// Function to copy and move for 2D grid
void copy_and_move_2d_grid(Grid<int, std::size_t, std::size_t> &grid2D);

// Function to copy and move for 3D grid
void copy_and_move_3d_grid(Grid<int, std::size_t, std::size_t, std::size_t> grid3D);

#endif
