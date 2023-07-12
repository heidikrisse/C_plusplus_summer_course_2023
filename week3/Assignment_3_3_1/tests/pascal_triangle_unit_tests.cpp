// Unit tests: pascal_triangle_tests.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/pascal_triangle.h"

TEST_CASE("Pascal's triangle calculation")
{
    std::vector<std::vector<int>> expected{{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};
    CHECK(calculate_pascal_triangle(5) == expected);
}
