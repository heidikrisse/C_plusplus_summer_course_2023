#include <iostream>

int main()
{
    // Declare a variable outside a block
    int resultOutsideBlock{};

    {
        // Declare and initialize with direct list initialization a variable inside the block
        int valueInsideBlock{1};
        std::cout << "Value inside block: " << valueInsideBlock << "\n";

        resultOutsideBlock = valueInsideBlock;
    }

    std::cout << "Value outside block: " << resultOutsideBlock << "\n";

    return 0;
}
