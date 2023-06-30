// hanoi_tower.cpp
#include <iostream>
#include <vector>
#include "../include/hanoi_tower.h"

// Function to move a disk from the source tower to the destination tower
void move_disk(std::vector<int> &source_tower, std::vector<int> &destination_tower)
{
    destination_tower.push_back(source_tower.back());
    source_tower.pop_back();
}

// Function to display the current state of the towers
void display_towers(const std::vector<int> &tower_a, const std::vector<int> &tower_b, const std::vector<int> &tower_c)
{
    std::cout << "\nCurrent state of towers:\n";
    std::cout << "Tower A: ";
    for (const auto &disk : tower_a)
    {
        std::cout << disk << ' ';
    }
    std::cout << "\nTower B: ";
    for (const auto &disk : tower_b)
    {
        std::cout << disk << ' ';
    }
    std::cout << "\nTower C: ";
    for (const auto &disk : tower_c)
    {
        std::cout << disk << ' ';
    }
    std::cout << '\n';
}

// Recursive function to solve the Hanoi Tower puzzle
void solve_towers_of_hanoi(int number_of_disks, std::vector<int> &source_tower, std::vector<int> &temp_helper_tower, std::vector<int> &target_tower)
{
    if (number_of_disks == 1)
    {
        move_disk(source_tower, target_tower);
        display_towers(source_tower, temp_helper_tower, target_tower);
        return;
    }

    solve_towers_of_hanoi(number_of_disks - 1, source_tower, target_tower, temp_helper_tower);
    move_disk(source_tower, target_tower);
    display_towers(source_tower, temp_helper_tower, target_tower);
    solve_towers_of_hanoi(number_of_disks - 1, temp_helper_tower, source_tower, target_tower);
}

// Function to play the Tower of Hanoi game
void play_towers_of_hanoi(int number_of_disks)
{
    std::vector<int> tower_a, tower_b, tower_c;

    for (int i{number_of_disks}; i > 0; --i)
    {
        tower_a.push_back(i);
    }

    std::cout << "Do you want to see the solved puzzle? (Y/N): ";
    char choice{};
    std::cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        display_towers(tower_a, tower_b, tower_c);
        solve_towers_of_hanoi(number_of_disks, tower_a, tower_b, tower_c);
    }
    else
    {
        display_towers(tower_a, tower_b, tower_c);

        while (tower_c.size() < number_of_disks)
        {
            std::cout << "\nEnter the source tower (A, B, or C), or 'Q' to quit: ";
            char source{};
            std::cin >> source;

            // Check if the user wants to quit
            if (source == 'Q' || source == 'q')
                break;

            std::cout << "Enter the destination tower (A, B, or C), or 'Q' to quit: ";
            char destination{};
            std::cin >> destination;

            // Check if the user wants to quit
            if (destination == 'Q' || destination == 'q')
                break;

            std::vector<int> *source_tower;
            std::vector<int> *destination_tower;

            switch (source)
            {
            case 'A':
            case 'a':
                source_tower = &tower_a;
                break;
            case 'B':
            case 'b':
                source_tower = &tower_b;
                break;
            case 'C':
            case 'c':
                source_tower = &tower_c;
                break;
            case 'Q':
            case 'q':
                std::exit(0); // Quit the program
            default:
                std::cout << "Invalid tower! Please try again.\n";
                continue;
            }

            switch (destination)
            {
            case 'A':
            case 'a':
                destination_tower = &tower_a;
                break;
            case 'B':
            case 'b':
                destination_tower = &tower_b;
                break;
            case 'C':
            case 'c':
                destination_tower = &tower_c;
                break;
            case 'Q':
            case 'q':
                std::exit(0); // Quit the program
            default:
                std::cout << "Invalid tower! Please try again.\n";
                continue;
            }

            // Check if the move is valid
            if (source_tower->empty() || (!destination_tower->empty() && destination_tower->back() < source_tower->back()))
            {
                std::cout << "Invalid move! Please try again.\n";
            }
            else
            {
                move_disk(*source_tower, *destination_tower);
                display_towers(tower_a, tower_b, tower_c);
            }
        }
    }

    std::cout << "\nExiting game ..\n";
}
