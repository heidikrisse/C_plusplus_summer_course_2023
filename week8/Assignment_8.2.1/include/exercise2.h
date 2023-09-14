// exercise2.h
#ifndef EXERCISE2_H
#define EXERCISE2_H

#include <iostream>

template <bool ENABLE_OUTPUT = true>
class DebugClass
{
private:
    static int default_constructor_count;
    static int copy_constructor_count;
    static int move_constructor_count;
    static int destructor_count;

public:
    // Default constructor
    DebugClass()
    {
        ++default_constructor_count;
        // Check if output is enabled
        if constexpr (ENABLE_OUTPUT)
        {
            std::cout << "Default constructor called.\n";
        }
    }

    // Copy constructor
    DebugClass(const DebugClass &)
    {
        ++copy_constructor_count;
        if constexpr (ENABLE_OUTPUT)
        {
            std::cout << "Copy constructor called.\n";
        }
    }

    // Move constructor
    DebugClass(DebugClass &&) noexcept
    {
        ++move_constructor_count;
        if constexpr (ENABLE_OUTPUT)
        {
            std::cout << "Move constructor called.\n";
        }
    }

    // Destructor
    ~DebugClass()
    {
        ++destructor_count;
        if constexpr (ENABLE_OUTPUT)
        {
            std::cout << "Destructor called.\n";
        }
    }
};

// Initialize static member variables for the DebugClass template
template <bool ENABLE_OUTPUT>
int DebugClass<ENABLE_OUTPUT>::default_constructor_count = 0;

template <bool ENABLE_OUTPUT>
int DebugClass<ENABLE_OUTPUT>::copy_constructor_count = 0;

template <bool ENABLE_OUTPUT>
int DebugClass<ENABLE_OUTPUT>::move_constructor_count = 0;

template <bool ENABLE_OUTPUT>
int DebugClass<ENABLE_OUTPUT>::destructor_count = 0;

#endif
