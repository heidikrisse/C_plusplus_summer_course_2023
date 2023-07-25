#include "include/exercise1.h"
#include "include/exercise2.h"

#include <iostream>

int main()
{
    /*********** Testing exercise 1: **********/

    std::cout << "***** Testing Exercise 1: *****\n\n";

    try
    {
        // Correct usage
        safe_printf("This is a character: %c.\nThis is a number: %d.\nThis is a double: %f.\n\n", 'A', 1, 2.5);
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    try
    {
        // Incorrect usage
        safe_printf("This is a character: %c.\nThis is a number: %d.\n\n", 'A', 1, 2.5);
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Error: " << e.what() << "\n\n";
    }

    try
    {
        safe_printf("This is a character: %c.\nThis is a number: %d.\nThis is a double %f.\n\n", 3, 1, 2.5);
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Error: " << e.what() << "\n\n";
    }

    /********** Testing exercise 2: **********/

    std::cout << "***** Testing Exercise 2: *****\n\n";

    VariadicClass variadic_class(1, 2, 3, 4, 5); //

    std::cout << "Number of arguments: " << variadic_class.number_of_arguments() << "\n\n";

    return 0;
}
