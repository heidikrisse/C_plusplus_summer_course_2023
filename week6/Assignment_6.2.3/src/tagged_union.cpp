// tagged_union.cpp
#include "../include/tagged_union.h"

#include <cassert>
#include <cstring> // for strlen()

TaggedUnion::TaggedUnion(int value) : type(TaggedUnionType::robot), robot_ID(value)
{
}

TaggedUnion::TaggedUnion(const char *value) : type(TaggedUnionType::person), first_letter_of_person_name('\0')
{
    if (value != nullptr && std::strlen(value) > 0)
    {
        first_letter_of_person_name = value[0];
    }
}

TaggedUnion::TaggedUnion(double value) : type(TaggedUnionType::alien), alien_eye_light_wavelength(static_cast<float>(value))
{
}

TaggedUnion::~TaggedUnion()
{
}

void TaggedUnion::set_person(char first_letter)
{
    type = TaggedUnionType::person;
    first_letter_of_person_name = first_letter;
}

void TaggedUnion::set_robot(int ID)
{
    type = TaggedUnionType::robot;
    robot_ID = ID;
}

void TaggedUnion::set_alien(float wavelength)
{
    type = TaggedUnionType::alien;
    alien_eye_light_wavelength = wavelength;
}

char TaggedUnion::get_person() const
{
    assert(type == TaggedUnionType::person);
    return first_letter_of_person_name;
}

int TaggedUnion::get_robot() const
{
    assert(type == TaggedUnionType::robot);
    return robot_ID;
}

float TaggedUnion::get_alien() const
{
    assert(type == TaggedUnionType::alien);
    return alien_eye_light_wavelength;
}
