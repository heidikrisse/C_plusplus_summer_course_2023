// parrot.h
#ifndef PARROT_H
#define PARROT_H

#include "animal.h"

class Parrot : public Animal
{
public:
    // Exercise 1: Override the make_sound() function
    std::string make_sound() const override { return "Tweet tweet"; }
    // Exercise 2:
    bool has_wings() const override { return true; }
};

#endif
