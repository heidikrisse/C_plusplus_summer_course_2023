// tagged_union.h
#ifndef TAGGED_UNION_H
#define TAGGED_UNION_H

#include <iostream>

enum class TaggedUnionType
{
    person,
    robot,
    alien,
};

class TaggedUnion
{
private:
    TaggedUnionType type;

    union
    {
        char first_letter_of_person_name;
        int robot_id;
        float alien_eye_light_wavelength;
    };

public:
    // Setters
    void set_person(const char first_letter);
    void set_robot(const int id);
    void set_alien(const float wavelength);

    // Getters
    char get_person() const;
    int get_robot() const;
    float get_alien() const;

    // Utility functions to check the type
    bool is_person() const;
    bool is_robot() const;
    bool is_alien() const;

    // EXERCISE 1:
    // Overload << operator
    friend std::ostream &operator<<(std::ostream &output_stream, const TaggedUnion &tagged_union);
};

#endif
