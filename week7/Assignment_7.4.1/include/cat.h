// cat.h
#ifndef CAT_H
#define CAT_H

#include "animal.h"

class Cat : public Animal
{
public:
    // Exercise 1: Override the make_sound() function
    std::string make_sound() const override { return "Meow meow"; }
    // Exercise 2:
    bool is_fluffy() const override { return true; }
};

#endif
