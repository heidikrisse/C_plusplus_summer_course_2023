// tagged_union_variant.cpp
#include "tagged_union_variant.h"

void TaggedUnionWrapper::set_person(const std::string &full_name)
{
    data_ = full_name;
}

void TaggedUnionWrapper::set_robot(int id)
{
    data_ = id;
}

void TaggedUnionWrapper::set_alien(float wavelength)
{
    data_ = wavelength;
}

std::string TaggedUnionWrapper::get_person() const
{
    if (std::holds_alternative<std::string>(data_))
    {
        return std::get<std::string>(data_);
    }
    throw std::runtime_error("Error: Data is not of type person.");
}

int TaggedUnionWrapper::get_robot() const
{
    if (std::holds_alternative<int>(data_))
    {
        return std::get<int>(data_);
    }
    throw std::runtime_error("Error: Data is not of type robot.");
}

float TaggedUnionWrapper::get_alien() const
{
    if (std::holds_alternative<float>(data_))
    {
        return std::get<float>(data_);
    }
    throw std::runtime_error("Error: Data is not of type alien.");
}
