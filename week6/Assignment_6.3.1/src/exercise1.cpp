#include "exercise1.h"

#include <iostream>

ClassWithStaticMemberFunction ClassWithStaticMemberFunction::create_instance()
{
    std::cout << "Returning an object of type of the class ClassWithStaticMemberFunction using static member function.\n";
    return ClassWithStaticMemberFunction();
}
