#ifndef EXERCISE_2_H
#define EXERCISE_2_H

#include "expected/include/tl/expected.hpp"

#include <string>

class ClassWithExpected
{
public:
    // Factory function
    static tl::expected<ClassWithExpected, std::string> create_instance(bool should_fail);

private:
    // Constructor
    ClassWithExpected();
};

#endif
