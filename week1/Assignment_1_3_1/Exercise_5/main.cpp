#include <iostream>

void modifyValue()
{
    int value{1}; // Local variable to the function modyfyValue()
    std::cout << "Value before if statement: " << value << "\n";

    if (true)
    {
        value = 2; // Modifying the local variable inside an if statement
    }

    std::cout << "Value after if statement: " << value << "\n";
}

int main()
{
    modifyValue();
    return 0;
}
