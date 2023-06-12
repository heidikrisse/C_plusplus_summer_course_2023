#include <iostream>

// Function to modify the value of the variable passed by reference
void modifyValue(int &value)
{
    value = 2;
}

void printValue()
{
    int value{1}; // Local variable to the function printValue()

    std::cout << "Value before function call: " << value << "\n";
    // Passing the local variable by reference to another function
    modifyValue(value);
    std::cout << "Value after function call: " << value << "\n";
}

int main()
{
    printValue();
    return 0;
}
