#include <iostream>

int calculate()
{
    int valueInCalculate{1 + 2};
    std::cout << "Value inside calculate(): " << valueInCalculate << "\n";
    return valueInCalculate;
}

int main()
{
    int valueInMain{calculate()};
    std::cout << "Value inside main(): " << valueInMain << "\n";
    return 0;
}
