#include "../include/exercise_1.h"

// Private Constructor
ClassWithOptional::ClassWithOptional() {}

std::optional<ClassWithOptional> ClassWithOptional::create_instance(bool should_fail)
{
    // If fail, return std::nullopt (empty optional)
    if (should_fail)
    {
        return std::nullopt;
    }
    // Return class instance wrapped inside optional
    return ClassWithOptional();
}
