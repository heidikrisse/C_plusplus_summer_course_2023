#include <iostream>

int main()
{
    /* Declare a variable outside a block
     * The scope of the variable extends to the entire main function */
    int resultOutsideBlock{};

    {
        /* Declare and initialize with direct list initialization a
         * variable inside the block
         * The variable has a local scope that extends to this block only */
        int valueInsideBlock{1};
        std::cout << "Value inside block: " << valueInsideBlock << "\n";

        // Copying the value from inside the block to outside the block
        resultOutsideBlock = valueInsideBlock;
    }

    std::cout << "Value outside block: " << resultOutsideBlock << "\n";

    return 0;
}
