#include <iostream>

namespace OneNamespace
{
    int value{1};
}

void demonstrateVariableScope()
{
    int value{2};
    std::cout << "The value inside the function: " << value << '\n';
    std::cout << "The value in namespace: " << OneNamespace::value << '\n';
}

int main()
{
    demonstrateVariableScope();
    return 0;
}
