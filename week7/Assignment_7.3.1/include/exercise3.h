// exercise3.h
#ifndef EXERCISE3_H
#define EXERCISE3_H

#include "exercise1.h"
#include "exercise2.h"

#include <iostream>
#include <type_traits>
#include <cxxabi.h> // for abi

// TypePrinter class template
template <typename T>
class TypePrinter
{
public:
    /*
    void print_type() const
    {
        std::cout << "Type name: " << typeid(T).name() << "\n";
    }
    */

    // Function to print the type of the class it's instantiated with
    void print_type() const
    {
        // A variable that will hold the status code returned by the abi::__cxa_demangle function
        int status_code{};
        char *demangled_name = abi::__cxa_demangle(typeid(T).name(), 0, 0, &status_code);

        // If succeeded
        if (status_code == 0)
        {
            std::cout << "\nType name: " << demangled_name << '\n';
            free(demangled_name);
        }
        else
        {
            std::cerr << "\nError demangling type name.\n";
        }
    }
};

// MyType class template inherits both ValueType and TypePrinter functionality
template <typename T>
class MyType : public ValueType<T>, public TypePrinter<MyType<T>>
{
public:
    MyType(T value) : ValueType<T>(value) {}
};

#endif
