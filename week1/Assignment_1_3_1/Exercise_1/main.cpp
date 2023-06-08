#include <iostream>

void printLocalVariable()
{
    int localVar{1};
    std::cout << "The local variable value is: " << localVar << "\n";
}

int main()
{
    printLocalVariable();

    return 0;
}
