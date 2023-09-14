// grid_tests.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/grid.h"

TEST_CASE("Grid Initialization")
{
    // 2D grid of size 3x3, initialized with 0
    std::size_t row{3};
    std::size_t col{3};
    int grid_init_value{0};
    Grid<int, std::size_t, std::size_t> grid2D(row, col, grid_init_value);
    // Verify width and height
    CHECK(grid2D.size().width == 3);
    CHECK(grid2D.size().height == 3);

    // 3D grid of size 4x4x4, initialized with 0
    std::size_t x{4};
    std::size_t y{4};
    std::size_t z{4};
    grid_init_value = 0; // unnecessary now but put here if wished to change from the 2D grid test
    Grid<int, std::size_t, std::size_t, std::size_t> grid3D(x, y, z, grid_init_value);
    // Verify width and height
    CHECK(grid3D.size().width == 4);
    CHECK(grid3D.size().height == 4);
    CHECK(grid3D.size().depth == 4);
}

TEST_CASE("Grid Access")
{
    // 2D grid of size 3x3, initialized with 0
    std::size_t row{3};
    std::size_t col{3};
    int grid_init_value{0};
    Grid<int, std::size_t, std::size_t> grid2D(row, col, grid_init_value);
    // Adjusted starting from 1, not 0, so -1 to keep the indexes correct
    // Check a value is default-initialized to 0
    row = 2;
    col = 2;
    CHECK(grid2D.at(row - 1, col - 1) == grid_init_value);
    // Set a value 5 at position (2, 2)
    int value{5};
    grid2D.at(row - 1, col - 1) = value;
    // Verify the value is correctly set at position (2,2)
    CHECK(grid2D.at(row - 1, col - 1) == value);

    // 3D grid of size 4x4x4, initialized with 0
    std::size_t x{4};
    std::size_t y{4};
    std::size_t z{4};
    grid_init_value = 0;
    Grid<int, std::size_t, std::size_t, std::size_t> grid3D(x, y, z, grid_init_value);
    // Adjusted starting from 1, not 0, so -1 to keep the indexes correct
    // Check some value in grid is set initially to 0
    x = 3;
    y = 3;
    z = 3;
    CHECK(grid3D.at(x - 1, y - 1, z - 1) == grid_init_value);
    // Set value 2 at position (3, 3, 3)
    value = 2;
    grid3D.at(z - 1, y - 1, z - 1) = value;
    // Verify the value 2 is correctly set at position (3, 3, 3)
    CHECK(grid3D.at(x - 1, y - 1, z - 1) == value);
}

TEST_CASE("Grid Resizing")
{
    // Testing to resize a 2D grid:

    std::size_t row{3};
    std::size_t col{3};
    int grid_init_value{0};
    Grid<int, std::size_t, std::size_t> grid2D(row, col, grid_init_value);
    // Adjusted starting from 1, not 0, so -1 to keep the indexes correct
    // Set the value in the first row and first column, which is position (1, 1) to 2
    row = 1;
    col = 1;
    int value{2};
    grid2D.at(row - 1, col - 1) = value;
    // Resize to 5x5
    grid2D.resize(5, 5);
    // Validate the new size:
    CHECK(grid2D.size().width == 5);
    CHECK(grid2D.size().height == 5);
    // Adjusted starting from 1, not 0, so -1 to keep the indexes correct
    // Check that the set value in the first row and first column actually is
    // still in the same place after resizing
    CHECK(grid2D.at(row - 1, col - 1) == value);
    // Check that other value(s) is(are) uninitialized as 0 (default)
    row = 5;
    col = 5;
    CHECK(grid2D.at(row - 1, col - 1) == grid_init_value);

    // Testing to resize a 3D grid:

    std::size_t x{3};
    std::size_t y{3};
    std::size_t z{3};
    grid_init_value = 0; // unnecessary now put put here if wished to change from the 2D grid test case
    Grid<int, std::size_t, std::size_t, std::size_t> grid3D(x, y, z, grid_init_value);
    // grid3D.print_grid();
    // Adjusted starting from 1, not 0, so -1 to keep the indexes correct
    // Set a value 2 at position (2, 2, 2)
    x = 2;
    y = 2;
    z = 2;
    value = 2;
    grid3D.at(x - 1, y - 1, z - 1) = value;
    // grid3D.print_grid();
    // Resize to 5 x 5 x 5
    grid3D.resize(5, 5, 5);
    // grid3D.print_grid();
    // Validate the new size of the grid
    CHECK(grid3D.size().width == 5);
    CHECK(grid3D.size().height == 5);
    CHECK(grid3D.size().depth == 5);
    // Adjusted starting from 1, not 0, so -1 to keep the indexes correct
    // Check that the set value is still in the same place after resizing
    CHECK(grid3D.at(x - 1, y - 1, z - 1) == value);
    // Other value(s) should be uninitialized as 0 (default)
    x = 4;
    y = 4;
    z = 4;
    CHECK(grid3D.at(x - 1, y - 1, z - 1) == grid_init_value);
}

TEST_CASE("Grid Iteration")
{
    // 2D grid of size 3x3, initialized with value 0
    Grid<int, std::size_t, std::size_t> grid2D(3, 3, 0);
    int sum{0};
    // Calculate the sum of all values in the grid (which are all 0)
    for (int val : grid2D)
    {
        sum += val;
    }
    CHECK(sum == 0);

    // 2D grid of size 3x3, initialized with value 2
    Grid<int, std::size_t, std::size_t> grid2D_2(3, 3, 2);
    sum = 0;
    for (int val : grid2D_2)
    {
        sum += val;
    }
    // The sum should be 2 * 3 * 3 = 18
    CHECK(sum == 18);

    // 3D grid of size 2x2x2, initialized with value 1
    Grid<int, std::size_t, std::size_t, std::size_t> grid3D(2, 2, 2, 1);
    sum = 0;
    // Calculate the sum of all values in the grid (which are all 1)
    for (int val : grid3D)
    {
        sum += val;
    }
    // The sum should be 8 (2x2x2)
    CHECK(sum == 8);
}
