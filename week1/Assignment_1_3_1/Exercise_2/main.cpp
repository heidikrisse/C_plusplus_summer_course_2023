#include <iostream>

int main()
{
    // i is a loop variable with a local scope, it only exists inside this loop.
    for (int i{0}; i < 5; ++i)
    {
        std::cout << "Loop variable value: " << i << "\n";
    }
    // Attempting to access the variable i here would result in a compile error

    return 0;
}
