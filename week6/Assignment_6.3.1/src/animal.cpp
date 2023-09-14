#include "animal.h"

Animal::Animal()
{
    std::cout << "Created an animal\n";
}

Animal::~Animal()
{
    std::cout << "Destroyed an animal\n";
}

void Animal::message()
{
    std::cout << "This is an animal\n";
}

Bird::Bird()
{
    std::cout << "Created a bird\n";
}

Bird::~Bird()
{
    std::cout << "Destroyed a bird\n";
}

void Bird::message()
{
    std::cout << "This is a bird\n";
}

Parrot::Parrot()
{
    std::cout << "Created a parrot\n";
}

Parrot::~Parrot()
{
    std::cout << "Destroyed a parrot\n";
}

void Parrot::message()
{
    std::cout << "This is a parrot\n";
}

Dog::Dog()
{
    std::cout << "Created a dog\n";
}

Dog::~Dog()
{
    std::cout << "Destroyed a dog\n";
}

void Dog::message()
{
    std::cout << "This is a dog\n";
}
