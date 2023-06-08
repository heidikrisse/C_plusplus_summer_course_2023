#include <iostream>

void modifyValue(int &value)
{
    value = 2;
}

void printValue()
{
    int value{1};

    std::cout << "Value before function call: " << value << "\n";
    modifyValue(value);
    std::cout << "Value after function call: " << value << "\n";
}

int main()
{
    printValue();
    return 0;
}
