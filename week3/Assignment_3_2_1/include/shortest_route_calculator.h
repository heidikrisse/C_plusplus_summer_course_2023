// shortest_route_calculator.h
#ifndef SHORTEST_ROUTE_CALCULATOR_H
#define SHORTEST_ROUTE_CALCULATOR_H

#include <map>
#include <string>
#include <vector>

// Function to calculate the shortest route of all possible routes.
std::pair<std::vector<std::string>, int> calculate_shortest_route(std::vector<std::vector<std::string>> &all_routes, std::map<std::string, std::map<std::string, int>> &distance_matrix);

#endif
