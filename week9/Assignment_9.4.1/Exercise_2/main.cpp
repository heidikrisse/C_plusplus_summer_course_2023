#include "include/animal.h"
#include "include/animal_ui.h"
#include "include/dog.h"
#include "include/cat.h"
#include "include/bird.h"

#include <vector>
#include <variant>
#include <iostream>

int main()
{
    // Create a std::variant of the animals and fill a vector with those:

    std::variant<Dog, Cat, Bird> dog_variant{Dog()};
    std::variant<Dog, Cat, Bird> cat_variant{Cat()};
    std::variant<Dog, Cat, Bird> bird_variant{Bird()};

    std::vector<std::variant<Dog, Cat, Bird>> animals = {dog_variant, cat_variant, bird_variant};

    auto print_type = [](auto &&arg)
    {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, Dog>)
            std::cout << "Identified as a dog.\n\n";
        else if constexpr (std::is_same_v<T, Cat>)
            std::cout << "Identified as a cat.\n\n";
        else if constexpr (std::is_same_v<T, Bird>)
            std::cout << "Identified as a bird.\n\n";
        else
            static_assert(always_false_v<T>, "Type not recognized.");
    };

    for (const auto &animal_variant : animals)
    {
        // Using the "void visitor", call the demonstration function of each animal entry
        std::visit(show_animal_info, animal_variant);

        // Using the type-matching visitor to print the type of the animal
        std::visit(print_type, animal_variant);
    }

    return 0;
}
