// tagged_union_variant.h
#ifndef TAGGED_UNION_VARIANT_H
#define TAGGED_UNION_VARIANT_H

#include <variant>
#include <iostream>
#include <stdexcept>

// The variant will hold either a person's full name (std::string), a robot's id (int) or the alien's light wavelength (float)
using TaggedUnionVariant = std::variant<std::string, int, float>;

// Enum to represent the types
enum class TaggedUnionTypeVariant
{
    person,
    robot,
    alien,
};

class TaggedUnionWrapper
{
public:
    // Setters
    void set_person(const std::string &full_name);
    void set_robot(int id);
    void set_alien(float wavelength);

    // Getters
    std::string get_person() const;
    int get_robot() const;
    float get_alien() const;

private:
    TaggedUnionVariant data_;
};

#endif // TAGGED_UNION_VARIANT_H
