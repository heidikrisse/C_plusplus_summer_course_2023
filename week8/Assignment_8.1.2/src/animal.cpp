// animal.cpp
#include "../include/animal.h"
#include "../include/dog.h"
#include "../include/cat.h"
#include "../include/parrot.h"

#include <fstream>
#include <iostream>

// Vector to store unique pointers to Animal objects
std::vector<std::unique_ptr<Animal>> Animal::read_animals_from_file(const std::string &filename)
{
    std::vector<std::unique_ptr<Animal>> animals;
    const std::string filepath{"../data/" + filename};
    std::ifstream file(filepath);

    // Check if the file could be opened
    if (!file.is_open())
    {
        std::cerr << "Unable to open file " << filename << ".\n";

        return animals;
    }

    std::string line{};
    // Iterate through each line of the file
    while (std::getline(file, line))
    {
        // Find the position of the comma (between animal type and name)
        size_t position_of_comma{line.find(',')};
        // Check the comma is found
        if (position_of_comma != std::string::npos)
        {
            // Animal type
            std::string type{line.substr(0, position_of_comma)};
            // Animal name (text after comma)
            // +2 to skip both comma and space
            std::string name{line.substr(position_of_comma + 2)};
            std::unique_ptr<Animal> animal = nullptr;

            // Check the type of animal and create a unique pointer to that type of the animal
            if (type == "dog")
            {
                animal = std::make_unique<Dog>();
            }
            else if (type == "cat")
            {
                animal = std::make_unique<Cat>();
            }
            else if (type == "parrot")
            {
                animal = std::make_unique<Parrot>();
            }
            // Otherwise create a general animal pointer
            else
            {
                animal = std::make_unique<Animal>();
            }

            // Set the animal's name
            animal->name = name;
            // Add the unique pointer to the vector
            animals.emplace_back(std::move(animal));
        }
    }

    // Return the vector of unique pointers to Animal objects
    return animals;
}
