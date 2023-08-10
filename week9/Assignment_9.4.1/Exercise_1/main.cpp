// main.cpp
#include "include/tagged_union_variant.h"

int main()
{
    TaggedUnionWrapper tagged_union_wrapper;

    // Set to "robot" and identifier to "1234"
    tagged_union_wrapper.set_robot(1234);
    std::cout << "Robot ID: " << tagged_union_wrapper.get_robot() << '\n';

    // Set to 'person' and full name to 'Hercule Poirot'
    tagged_union_wrapper.set_person("Hercule Poirot");
    std::cout << "Full name of person: " << tagged_union_wrapper.get_person() << '\n';

    // Example of exception handling if wrong type
    try
    {
        std::cout << "Approximate light wavelength emitted by alien's eyes: " << tagged_union_wrapper.get_alien() << '\n';
    }
    catch (std::runtime_error &e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}
