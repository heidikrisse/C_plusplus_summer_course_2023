// animal.h
#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <vector>
#include <memory>

class Animal
{
public:
    /* Exercise 1: A virtual member function that returns a string */
    virtual std::string make_sound() const { return "Generic animal sound"; }

    /* Exercise 2: Abstract functions (not pure virtuals) for the Animal
     * base class that Dog, Cat and Bird inherit but do not override them */
    virtual bool is_fluffy() const { return false; }
    virtual bool has_wings() const { return false; }

    virtual ~Animal() = default;

    /* Exercise 4: Adding a name member field for the Animal class
     * - an empty string as a default for animals */
    std::string name{""};

    static std::vector<std::unique_ptr<Animal>> read_animals_from_file(const std::string &filename);
};

#endif
