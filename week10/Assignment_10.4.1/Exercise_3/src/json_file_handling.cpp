// json_file_handling.cpp
#include "../include/json_file_handling.h"

#include <iostream>
#include <fstream>

using json = nlohmann::json;

void read_and_print_json()
{
    const std::string filename{"animal-1.json"};
    const std::string filepath{"../data/" + filename};
    std::ifstream input_file(filepath);
    if (!input_file.is_open())
    {
        std::cout << "Unable to open the file: " << filename << '\n';
        return;
    }

    json data;
    input_file >> data;
    input_file.close();

    for (const auto &entry : data)
    {
        std::cout << "Name: " << entry["name"] << '\n';
        std::cout << "Species: " << entry["species"] << '\n';
        std::cout << "Likes: ";
        for (const auto &like : entry["foods"]["likes"])
        {
            std::cout << like << ' ';
        }
        std::cout << '\n';
        std::cout << "Dislikes: ";
        for (const auto &dislike : entry["foods"]["dislikes"])
        {
            std::cout << dislike << ' ';
        }
        std::cout << "\n\n";
    }
}

void write_json_to_file()
{
    // Create a JSON object
    json output_data = {
        {"message", "Hello, JSON!"}};

    std::ofstream output_file("../data/output.json");
    if (!output_file.is_open())
    {
        std::cout << "Unable to open the file for writing.\n";
        return;
    }

    output_file << output_data.dump(4); // Indented output
    output_file.close();
}
