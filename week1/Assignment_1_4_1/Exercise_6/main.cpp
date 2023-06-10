// #define NDEBUG
#include <iostream>
#include <cassert>

// Function to check if the input number is within a range of 1 to 100 (inclusive)
void play_game(int number)
{
    assert((number >= 1 && number <= 100) && "Error: The number is out of range");
    std::cout << "Your number is within the range of 1 and 100 (inclusive).\n";
}

int main()
{
    std::cout << "PLAY THE GAME\n\nPlease enter a number: ";
    int number{};
    std::cin >> number;
    play_game(number);

    return 0;
}
