// exercise1.cpp
#include "exercise1.h"
#include <iostream>

namespace exercise1_namespace
{
    void function_in_namespace()
    {
        std::cout << "A function inside the namespace 'exercise1_namespace'.\n";
    }
}

void TypeInGlobalNamespace::static_member_function()
{
    std::cout << "A static member function of TypeInGlobalNamespace.\n";
}
