// main.cpp
#include <iostream>
#include "include/hanoi_tower.h"

int main()
{
    std::cout << "Welcome to the Tower of Hanoi game!\n\n";

    std::cout << "The Tower of Hanoi is a mathematical puzzle consisting of three towers and a set of disks of different sizes.\n";
    std::cout << "The goal of the game is to move the entire stack of disks from one tower to another, following the rules:\n\n";
    std::cout << "1. Only one disk can be moved at a time.\n";
    std::cout << "2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack.\n";
    std::cout << "3. No disk may be placed on top of a smaller disk.\n\n";
    std::cout << "You can quit the game anytime by giving choice 'Q'.\n\n";

    std::cout << "Enter the number of disks: ";
    int number_of_disks{};
    std::cin >> number_of_disks;

    play_towers_of_hanoi(number_of_disks);

    return 0;
}
