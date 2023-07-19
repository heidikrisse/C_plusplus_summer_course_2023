// main.cpp
#include "include/tagged_union.h"

#include <iostream>

int main()
{

    TaggedUnion a(42); // stores integer, sets the state accordingly
    std::cout << "Robot ID: " << a.get_robot() << "\n";

    TaggedUnion b("BlahBlah"); // stores initial (char), sets the state
    std::cout << "First letter of person's name: " << b.get_person() << "\n";

    // Testing to pass a double value directly without an explicit conversion
    // => error
    // TaggedUnion d = (5.28);

    // Explicitly convert double to TaggedUnion
    TaggedUnion c(5.28); // stores double...
    std::cout << "Approximate light wavelength emitted by alien's eyes: " << c.get_alien() << "\n";

    return 0;
}
