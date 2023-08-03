// exercise3.h
// Continuation of the Assignment 6.2.1 Exercise 3
#ifndef EXERCISE3_H
#define EXERCISE_H

#include <string>

class CountedInstance
{
private:
    static int instance_count;
    std::string instance_name;

public:
    CountedInstance(const std::string &name);
    // Delete the copy constructor
    CountedInstance(const CountedInstance &) = delete;
    // Move constructor
    CountedInstance(CountedInstance &&) noexcept;
    ~CountedInstance();

    static void print_count();
};

#endif
