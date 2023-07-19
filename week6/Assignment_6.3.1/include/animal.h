#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
public:
    Animal();
    ~Animal();

    void message();
};

class Wings
{
};

class Eyes
{
};

class Bird : public Animal
{
private:
    Wings wings;
    Eyes eyes;

public:
    Bird();
    ~Bird();

    void message();
};

class Parrot : public Bird
{
public:
    Parrot();
    ~Parrot();

    void message();
};

class Dog : public Animal
{
public:
    Dog();
    ~Dog();

    void message();
};

#endif

