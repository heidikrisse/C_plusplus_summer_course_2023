// grid_tests.cpp
// Exercise 5:
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/grid.h"

TEST_CASE("Grid Initialization")
{
    Grid<int> grid(3, 3, 0);
    CHECK(grid.size().width == 3);
    CHECK(grid.size().height == 3);
}

TEST_CASE("Grid Access")
{
    Grid<int> grid(3, 3, 0);
    CHECK(grid.at(1, 1) == 0);
    grid.at(1, 1) = 5;
    CHECK(grid.at(1, 1) == 5);
}

TEST_CASE("Grid Resizing")
{
    Grid<int> grid(3, 3, 0);
    grid.at(1, 1) = 5;
    grid.resize(5, 5);
    CHECK(grid.size().width == 5);
    CHECK(grid.size().height == 5);
    CHECK(grid.at(1, 1) == 5);
    CHECK(grid.at(4, 4) == 0); // it should be uninitialized
}

TEST_CASE("Grid Iteration")
{
    Grid<int> grid(3, 3, 0);
    int sum{0};
    for (int val : grid)
    {
        sum += val;
    }
    CHECK(sum == 0);
}
