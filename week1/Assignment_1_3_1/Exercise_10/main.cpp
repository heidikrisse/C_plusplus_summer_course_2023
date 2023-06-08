#include <iostream>

namespace OneNamespace
{
    /* Variable inside a namespace
     * Its scope can be accessed using the namespace */
    int value{1};
}

void demonstrateVariableScope()
{
    int value{2}; // Local variable inside the function
    std::cout << "The value inside the function: " << value << '\n';
    // Access the variable in the namespace using scope resolution
    std::cout << "The value in namespace: " << OneNamespace::value << '\n';
}

int main()
{
    demonstrateVariableScope();

    return 0;
}
