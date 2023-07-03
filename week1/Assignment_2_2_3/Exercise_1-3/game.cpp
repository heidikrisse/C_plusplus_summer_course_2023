// game.cpp
#include "game.h"
#include <iostream>
#include <random>

// Function to fill the game board with random cell types
void fill_game_board_randomly(std::array<std::array<Cell, 10>, 10> &game_board, Player &player)
{
    // Create a random device for seeding
    std::random_device rd{};
    // Create a random number generator engine using the random device as the seed
    std::mt19937 gen(rd());
    // Create a reusable random number generator for numbers 0-9
    std::uniform_int_distribution<> dis(0, 9);

    for (std::size_t i{0}; i < 10; i++)
    {
        for (std::size_t j{0}; j < 10; j++)
        {
            // Generate a random number
            int random_num{dis(gen)};
            // If the random number < 3, set the cell type as O (obstacle)
            if (random_num < 3)
            {
                game_board[i][j].cell_type = 'O';
            }
            else if (random_num < 5) // treasure cells
            {
                game_board[i][j].cell_type = 'T';
            }
            // Otherwise set the cell type as ' ' (empty)
            else
            {
                game_board[i][j].cell_type = ' ';
            }
        }
    }

    // Place the player at the upper-left corner
    game_board[player.y][player.x].cell_type = 'P';

    // Place the goal at the lower-right corner
    game_board[9][9].cell_type = 'G';
}

// Function to print the game board
void print_game_board(const std::array<std::array<Cell, 10>, 10> &game_board)
{
    // Print the top border
    for (std::size_t i{0}; i < game_board.size() * 2 + 2; i++)
    {
        std::cout << "_";
    }
    std::cout << '\n';

    for (std::size_t i{0}; i < game_board.size(); i++)
    {
        // Print left border
        std::cout << "|";
        for (std::size_t j{0}; j < game_board[i].size(); j++)
        {
            std::cout << game_board[i][j].cell_type << ' ';
        }
        // Print right border
        std::cout << "|" << '\n';
    }

    // Print the bottom border
    for (std::size_t i{0}; i < game_board.size() * 2 + 2; i++)
    {
        std::cout << "-";
    }
    std::cout << '\n';
}

// Function to check if the move is within the bounds of the game board
bool is_possible_move(std::size_t x, std::size_t y)
{
    return x < 10 && y < 10;
}

// Function to move the player
void move_player(Player &player, int dx, int dy, std::array<std::array<Cell, 10>, 10> &game_board)
{
    std::size_t new_x{static_cast<std::size_t>(player.x) + static_cast<std::size_t>(dx)};
    std::size_t new_y{static_cast<std::size_t>(player.y) + static_cast<std::size_t>(dy)};

    // Check if the move is valid and not blocked by an obstacle
    if (is_possible_move(new_x, new_y) && game_board[new_y][new_x].cell_type != 'O')
    {
        game_board[player.y][player.x].cell_type = ' ';
        player.x = new_x;
        player.y = new_y;

        // Check if the player found a treasure
        if (game_board[player.y][player.x].cell_type == 'T')
        {
            player.treasure_count++; // Increment treasure count
            std::cout << "You found a treasure! You have now " << player.treasure_count << " treasure(s).\n";
        }

        // Check if the player has reached the goal (lower-right corner)
        // and found at least 5 treasures
        if (player.x == 9 && player.y == 9 && player.treasure_count >= 5)
        {
            std::cout << "\nYou won the game! You have found " << player.treasure_count << " treasures and reached the goal. Congratulations!\n";
            // End the game
            std::exit(0);
        }

        // Place the player in the new position
        game_board[player.y][player.x].cell_type = 'P';
    }
    else
    {
        std::cout << "Invalid move. Try again.\n";
    }
}

char get_user_input()
{
    std::cout << "Enter your move (N for north, S for south, W for west, E for east, Q for exit game): ";
    char input{};
    std::cin >> input;
    // Convert lowercase letters to uppercase in case the user inputs
    // lowercase letters
    input = std::toupper(input);

    return input;
}

// Function to print the game instructions
void print_game_instructions()
{
    std::cout << "ADVENTURE GAME INSTRUCTIONS:\n\n";
    std::cout << "P - Player\n";
    std::cout << "O - Obstacle\n";
    std::cout << "T - Treasure\n";
    std::cout << "G - Goal\n\n";
    std::cout << "The goal is to collect 5 treasures (T) and then navigate the\nplayer (P) to the goal (G) while avoiding obstacles (O).\n\n";
}
