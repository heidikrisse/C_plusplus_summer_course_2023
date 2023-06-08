#include <iostream>

void modifyValue()
{
    int value{1};
    std::cout << "Value before if statement: " << value << "\n";

    if (true)
    {
        value = 2;
    }

    std::cout << "Value after if statement: " << value << "\n";
}

int main()
{
    modifyValue();
    return 0;
}
