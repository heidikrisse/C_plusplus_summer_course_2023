// route_generator.h
#ifndef ROUTE_GENERATOR_H
#define ROUTE_GENERATOR_H

#include <map>
#include <string>
#include <vector>

// Function to initialize the distance matrix.
std::map<std::string, std::map<std::string, int>> initialize_distance_matrix();

// Helper function to generate all possible routes.
void generate_all_routes_helper(std::string start, std::vector<std::string> &temp_route, std::vector<std::vector<std::string>> &all_routes, std::map<std::string, std::map<std::string, int>> &distance_matrix);

// Function to generate all routes starting from a given city.
std::vector<std::vector<std::string>> generate_all_routes(std::string start, std::map<std::string, std::map<std::string, int>> &distance_matrix);

#endif
