#include <iostream>

void printLocalVariable()
{
    /* Declaring a variable localVar with a local scope. This variable can
     * only be accessed inside this function. */
    int localVar{1};
    std::cout << "The local variable value is: " << localVar << "\n";
}

int main()
{
    printLocalVariable();

    return 0;
}
