#include "include/animal.h"
#include "include/dog.h"
#include "include/cat.h"
#include "include/bird.h"
#include "include/animal_ui.h"

#include <vector>
#include <iostream>

int main()
{
    // Exercise 1: Create a couple of classes deriving the Animal class
    Dog dog;
    Cat cat;
    Bird bird;

    // Exercise 3:
    show_animal_info(dog);
    show_animal_info(cat);
    show_animal_info(bird);

    // Exercise 4: Adding a name member field
    dog.name = "Mörri Mörökölli";
    cat.name = "Misuantti";
    bird.name = "Kaija-Papukaija";

    /* Exercise 5: Loop to iterate through the vector and call
     * show_animal_info function */
    std::vector<Animal *> animals = {&dog, &cat, &bird};
    for (const auto animal : animals)
    {
        /* Exercise 3: Function takes animal reference as a parameter
         * and demonstrates the functions of the object */
        show_animal_info(*animal);
    }

    return 0;
}
