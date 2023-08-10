#include "../include/exercise_2.h"

// Private constructor
ClassWithExpected::ClassWithExpected() {}

tl::expected<ClassWithExpected, std::string> ClassWithExpected::create_instance(bool should_fail)
{
    if (should_fail)
    {
        // Report error and return the error message
        return tl::unexpected<std::string>("Creation failed!");
    }

    // Return class instance wrapped inside expected
    return ClassWithExpected();
}
