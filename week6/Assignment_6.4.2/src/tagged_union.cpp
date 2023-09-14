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
    return first_letter_of_person_name;
}

int TaggedUnion::get_robot() const
{
    assert(type == TaggedUnionType::robot);
    return robot_id;
}

float TaggedUnion::get_alien() const
{
    assert(type == TaggedUnionType::alien);
    return alien_eye_light_wavelength;
}

bool TaggedUnion::is_person() const
{
    return type == TaggedUnionType::person;
}

bool TaggedUnion::is_robot() const
{
    return type == TaggedUnionType::robot;
}

bool TaggedUnion::is_alien() const
{
    return type == TaggedUnionType::alien;
}

// EXERCISE 1:
// Overload the << operator for the class so the contents can be directly outputted with std::cout
std::ostream &operator<<(std::ostream &output_stream, const TaggedUnion &tagged_union)
{
    if (tagged_union.is_person())
    {
        output_stream << "Person: " << tagged_union.get_person();
    }
    else if (tagged_union.is_robot())
    {
        output_stream << "Robot: " << tagged_union.get_robot();
    }
    else if (tagged_union.is_alien())
    {
        output_stream << "Alien: " << tagged_union.get_alien();
    }
    return output_stream;
}
