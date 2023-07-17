// main.cpp
#include "tagged_union.h"

int main()
{
    TaggedUnion tagged_union;

    // Set type to "robot" and identifier to "1234"
    tagged_union.set_robot(1234);

    // If the type is 'robot', access the value
    if (tagged_union.type == TaggedUnionType::robot)
    {
        std::cout << "Robot ID: " << tagged_union.get_robot() << "\n";
    }

    // Set type to 'person' and first letter to 'A'
    tagged_union.set_person('H');

    // If the type is "person", access the value
    if (tagged_union.type == TaggedUnionType::person)
    {
        std::cout << "First letter of person's name: " << tagged_union.get_person() << "\n";
    }

    // Not set type to 'alien'

    // Throws an exception as the type is not set to 'alien'
    try
    {
        std::cout << "Approximate light wavelength emitted by alien's eyes: " << tagged_union.get_alien() << "\n";
    }
    catch (std::runtime_error &e)
    {
        std::cout << e.what() << "\n";
    }

    return 0;
}
