// pascal_triangle.h
#ifndef PASCAL_TRIANGLE_H
#define PASCAL_TRIANGLE_H

#include <vector>

// Function to calculate Pascal's Triangle for a given number of rows
std::vector<std::vector<int>> calculate_pascal_triangle(int rows);

// Function to print Pascal's Triangle
void print_pascal_triangle(const std::vector<std::vector<int>> &triangle);

// Function to run the Pascal's Triangle
void run_pascal_triangle();

#endif // PASCAL_TRIANGLE_H
