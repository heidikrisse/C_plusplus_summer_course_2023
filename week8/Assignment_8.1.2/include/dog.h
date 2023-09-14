// dog.h
#ifndef DOG_H
#define DOG_H

#include "animal.h"

class Dog : public Animal
{
public:
    // Exercise 1: Override the make_sound() function
    std::string make_sound() const override { return "Woof woof"; }
    // Exercise 2:
    bool is_fluffy() const override { return true; }
};

#endif
