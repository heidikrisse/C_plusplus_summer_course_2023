// pascal_triangle.cpp

#include "../include/pascal_triangle.h"
#include <iostream>

// Function to calculate Pascal's Triangle for a given number of rows
std::vector<std::vector<int>> calculate_pascal_triangle(int rows)
{
    std::vector<std::vector<int>> pascal_triangle(rows);

    // Iterate over each row
    for (int i{0}; i < rows; i++)
    {
        pascal_triangle[i].resize(i + 1);

        // The first and last element of every row = 1
        pascal_triangle[i][0] = pascal_triangle[i][i] = 1;

        // Calculate the between values
        for (int j = 1; j < i; j++)
            pascal_triangle[i][j] = pascal_triangle[i - 1][j - 1] + pascal_triangle[i - 1][j];
    }

    return pascal_triangle;
}

// Function to print Pascal's Triangle
void print_pascal_triangle(const std::vector<std::vector<int>> &pascal_triangle)
{
    // Total rows
    std::size_t rows{pascal_triangle.size()};

    for (std::size_t i{0}; i < rows; i++)
    {
        // Spaces
        for (std::size_t space{1}; space <= rows - i; space++)
            std::cout << "  ";

        // Print each number with a space
        for (std::size_t j{0}; j <= i; j++)
            std::cout << pascal_triangle[i][j] << "   ";

        std::cout << "\n";
    }
}

// Function to run the Pascal's Triangle
void run_pascal_triangle()
{
    std::cout << "Enter the number of rows for Pascal's Triangle: ";
    int rows{};
    std::cin >> rows;

    auto pascal_triangle{calculate_pascal_triangle(rows)};
    print_pascal_triangle(pascal_triangle);
}
