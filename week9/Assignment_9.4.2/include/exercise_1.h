#ifndef EXERCISE_1_H
#define EXERCISE_1_H

#include <optional>

class ClassWithOptional
{
public:
    // Factory function (static member function) to create a class instance
    static std::optional<ClassWithOptional> create_instance(bool should_fail);

private:
    // Constructor
    ClassWithOptional();
};

#endif
