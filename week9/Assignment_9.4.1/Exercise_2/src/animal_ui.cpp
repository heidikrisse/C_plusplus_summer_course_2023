// animal_ui.cpp
#include "../include/animal_ui.h"
#include "../include/dog.h"
#include "../include/cat.h"
#include "../include/bird.h"

#include <iostream>

void show_animal_info(const Animal &animal)
{
    std::string animal_species;

    // Using dynamic_cast to get the animal species type
    if (dynamic_cast<const Dog *>(&animal))
    {
        animal_species = "dog";
    }
    else if (dynamic_cast<const Cat *>(&animal))
    {
        animal_species = "cat";
    }
    else if (dynamic_cast<const Bird *>(&animal))
    {
        animal_species = "bird";
    }
    else
    {
        animal_species = "unknown animal";
    }

    std::cout << "This animal is a " << animal_species << ".\n";
    if (animal.name.empty())
    {
        std::cout << "The " << animal_species << " says " << animal.make_sound() << "!\n";

        if (animal.is_fluffy())
        {
            std::cout << "The " << animal_species << " is fluffy.\n";
        }
        if (animal.has_wings())
        {
            std::cout << "The " << animal_species << " has wings.\n";
        }
    }
    else
    {
        std::cout << "The name of the " << animal_species << " is " << animal.name << ".\n";
        std::cout << "The " << animal_species << " " << animal.name << " says " << animal.make_sound() << ".\n";

        if (animal.is_fluffy())
        {
            std::cout << "The " << animal_species << " " << animal.name << " is fluffy.\n";
        }
        if (animal.has_wings())
        {
            std::cout << "The " << animal_species << " " << animal.name << " has wings.\n";
        }
    }
}
