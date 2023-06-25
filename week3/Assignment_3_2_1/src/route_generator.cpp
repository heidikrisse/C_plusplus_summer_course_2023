// route_generator.cpp
#include "../include/route_generator.h"
#include <algorithm>

// Function to initialize the distance matrix.
std::map<std::string, std::map<std::string, int>> initialize_distance_matrix()
{
    return {
        {"Panama", {{"Panama", 0}, {"New York", 4460}, {"Amsterdam", 8440}, {"Helsinki", 9240}, {"Durban", 12950}}},
        {"New York", {{"Panama", 4460}, {"New York", 0}, {"Amsterdam", 5700}, {"Helsinki", 6620}, {"Durban", 12700}}},
        {"Amsterdam", {{"Panama", 8440}, {"New York", 5700}, {"Amsterdam", 0}, {"Helsinki", 1520}, {"Durban", 9760}}},
        {"Helsinki", {{"Panama", 9240}, {"New York", 6620}, {"Amsterdam", 1520}, {"Helsinki", 0}, {"Durban", 10480}}},
        {"Durban", {{"Panama", 12950}, {"New York", 12700}, {"Amsterdam", 9760}, {"Helsinki", 10480}, {"Durban", 0}}}};
}

// Helper function to recursively generate all possible routes.
void generate_all_routes_helper(std::string start, std::vector<std::string> &temp_route, std::vector<std::vector<std::string>> &all_routes, std::map<std::string, std::map<std::string, int>> &distance_matrix)
{
    // Push the current city to the temporary route.
    temp_route.push_back(start);

    if (temp_route.size() == distance_matrix.size())
    {
        // If all cities have been visited, add the current route to all possible routes.
        all_routes.push_back(temp_route);
    }
    else
    {
        // If not all cities have been visited, recursively call this function for the unvisited cities.
        for (auto &city : distance_matrix)
        {
            if (std::find(temp_route.begin(), temp_route.end(), city.first) == temp_route.end())
            {
                generate_all_routes_helper(city.first, temp_route, all_routes, distance_matrix);
            }
        }
    }
    // After visiting all possible routes from the current city, remove it from the current route.
    temp_route.pop_back();
}

// Function to generate all possible routes starting from a given city.
std::vector<std::vector<std::string>> generate_all_routes(std::string start, std::map<std::string, std::map<std::string, int>> &distance_matrix)
{
    std::vector<std::vector<std::string>> all_routes{};
    std::vector<std::string> temp_route{};

    generate_all_routes_helper(start, temp_route, all_routes, distance_matrix);

    return all_routes;
}
