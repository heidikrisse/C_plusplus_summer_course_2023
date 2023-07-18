// tagged_union.h
// Exercise 1
#ifndef TAGGED_UNION_H
#define TAGGED_UNION_H

#include <iostream>
#include <stdexcept>
#include <string>

enum class TaggedUnionType
{
    person,
    robot,
    alien,
};

class TaggedUnion
{
public:
    TaggedUnionType type;

    union
    {
        char first_letter_of_person_name;
        int robot_ID;
        float alien_eye_light_wavelength;
    };

    // Constructors with explicit specifier
    explicit TaggedUnion(int value);
    explicit TaggedUnion(const char *value);
    explicit TaggedUnion(double value);

    // Destructor
    ~TaggedUnion();

    // Setters
    void set_person(char first_letter);
    void set_robot(int ID);
    void set_alien(float wavelength);

    // Getters
    char get_person() const;
    int get_robot() const;
    float get_alien() const;
};

#endif
