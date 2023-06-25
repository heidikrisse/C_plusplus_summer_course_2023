// shortest_route_calculator.cpp
#include "../include/shortest_route_calculator.h"
#include "../include/route_generator.h"
#include <climits>

// Function to calculate the shortest route of all routes.
std::pair<std::vector<std::string>, int> calculate_shortest_route(std::vector<std::vector<std::string>> &all_routes, std::map<std::string, std::map<std::string, int>> &distance_matrix)
{
    /* INT_MAX means max possible value for an integer.
     * Here we initialize the shortest distance with max value so that
     * initially any distance will be smaller/shorter. */
    int shortest_distance{INT_MAX};
    std::vector<std::string> shortest_route{};

    // Loop over all routes.
    for (auto &route : all_routes)
    {
        int current_distance{0};
        // Calculate the distance of the current route.
        for (size_t i{0}; i < route.size() - 1; ++i)
        {
            current_distance += distance_matrix[route[i]][route[i + 1]];
        }
        /* If the current distance is shorter than the shortest distance
         * found so far, update the shortest distance and route. */
        if (current_distance < shortest_distance)
        {
            shortest_distance = current_distance;
            shortest_route = route;
        }
    }

    // Return the shortest route and its distance.
    return {shortest_route, shortest_distance};
}
