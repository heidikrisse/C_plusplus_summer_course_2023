// bird.h
#ifndef BIRD_H
#define BIRD_H

#include "animal.h"

class Bird : public Animal
{
public:
    // Exercise 1: Override the make_sound() function
    std::string make_sound() const override { return "Tweet tweet"; }
    // Exercise 2:
    bool has_wings() const override { return true; }
};

#endif
