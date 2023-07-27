// animal_ui.cpp
#include "../include/animal_ui.h"
#include "../include/dog.h"
#include "../include/cat.h"
#include "../include/bird.h"

#include <iostream>
#include <typeinfo>

void show_animal_info(const Animal &animal)
{
    std::string animal_species{};

    Dog dog;
    Cat cat;
    Bird bird;

    /* Use typeid() to get the animal species type
     * - typeid(animal) returns the type_info of the animal and it is
     *   compared with the derived class types */
    if (typeid(animal) == typeid(Dog))
    {
        animal_species = "dog";
    }
    else if (typeid(animal) == typeid(Cat))
    {
        animal_species = "cat";
    }
    else if (typeid(animal) == typeid(Bird))
    {
        animal_species = "bird";
    }

    std::cout << "This animal is a " << animal_species << ".\n";
    if (animal.name.empty())
    {
        std::cout << "The " << animal_species << " says " << animal.make_sound() << "!\n";

        // Exercise 2: Demonstrate abstract functions
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

        // Exercise 2: Demonstrate abstract functions
        if (animal.is_fluffy())
        {
            std::cout << "The " << animal_species << " " << animal.name << " is fluffy.\n";
        }
        if (animal.has_wings())
        {
            std::cout << "The " << animal_species << " " << animal.name << " has wings.\n";
        }
    }
    std::cout << '\n';
}
