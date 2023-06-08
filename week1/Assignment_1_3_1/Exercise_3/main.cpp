#include <iostream>

int calculate()
{
    // This variable is local to calculate() function
    int valueInCalculate{1 + 2};
    std::cout << "Value inside calculate(): " << valueInCalculate << "\n";
    return valueInCalculate;
}

int main()
{
    /* This variable is local to main() function
     * The variable receives the return value of calculate() function */
    int valueInMain{calculate()};
    std::cout << "Value inside main(): " << valueInMain << "\n";
    return 0;
}
