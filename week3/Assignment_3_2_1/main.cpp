/* main.cpp*/
#include <iostream>
#include <vector>
#include <map>
#include "include/route_generator.h"
#include "include/shortest_route_calculator.h"

int main()
{
    // Initialize the distance matrix.
    auto distance_matrix{initialize_distance_matrix()};

    std::cout << "Generating all possible routes starting from Panama...\n";

    std::string departure_city{"Panama"};
    // Generate all possible routes starting from a given city.
    auto all_possible_routes{generate_all_routes(departure_city, distance_matrix)};

    // Calculate and retrieve the shortest route and its corresponding distance.
    auto [shortest_route, shortest_distance] = calculate_shortest_route(all_possible_routes, distance_matrix);

    std::cout << "Shortest route is: ";
    for (size_t i{0}; i < shortest_route.size(); ++i)
    {
        std::cout << shortest_route[i];
        if (i != shortest_route.size() - 1)
        {
            std::cout << " -> ";
        }
    }
    std::cout << "\nShortest distance is: " << shortest_distance << " km.\n";

    return 0;
}
