#include <iostream>

void demonstrateStaticVariable()
{
    static int count{};
    ++count;

    std::cout << count << ". function call\n";
}

int main()
{
    for (int i{0}; i < 5; ++i)
    {
        demonstrateStaticVariable();
    }

    return 0;
}
