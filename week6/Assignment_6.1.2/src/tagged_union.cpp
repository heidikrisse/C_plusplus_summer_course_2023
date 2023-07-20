// tagged_union.cpp
#include "tagged_union.h"
#include <cassert>
#include <exception>

void TaggedUnion::set_person(char first_letter)
{
    type = TaggedUnionType::person;
    first_letter_of_person_name = first_letter;
}
void TaggedUnion::set_robot(int id)
{
    type = TaggedUnionType::robot;
    robot_id = id;
}

void TaggedUnion::set_alien(float wavelength)
{
    type = TaggedUnionType::alien;
    alien_eye_light_wavelength = wavelength;
}

char TaggedUnion::get_person() const
{
    assert(type == TaggedUnionType::person);
    /* if (type != TaggedUnionType::person)
    {
        throw std::runtime_error("Invalid type access.");
    }
    */
    return first_letter_of_person_name;
}

int TaggedUnion::get_robot() const
{
    assert(type == TaggedUnionType::robot);
    /* if (type != TaggedUnionType::robot)
    {
        throw std::runtime_error("Invalid type access.");
    }
    */
    return robot_id;
}

float TaggedUnion::get_alien() const
{
    assert(type == TaggedUnionType::alien);
    /*
    if (type != TaggedUnionType::alien)
    {
        throw std::runtime_error("Invalid type access.");
    }
    */
    return alien_eye_light_wavelength;
}
