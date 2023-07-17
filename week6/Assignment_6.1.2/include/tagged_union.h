// tagged_union.h
// Exercise 1
#include <iostream>

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

    // Setters
    void set_person(char first_letter);
    void set_robot(int ID);
    void set_alien(float wavelength);

    // Getters
    char get_person() const;
    int get_robot() const;
    float get_alien() const;
};
