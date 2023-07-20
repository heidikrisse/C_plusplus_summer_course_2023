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
};
