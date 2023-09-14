// main.cpp
#include "game.h"
#include <array>
#include <iostream>

int main()
{
    std::array<std::array<Cell, 10>, 10> game_board{};
    Player player;
    player.x = 0;
    player.y = 0;

    print_game_instructions();

    fill_game_board_randomly(game_board, player);

    bool game_over{false};
    while (!game_over)
    {
        print_game_board(game_board);

        char input{get_user_input()};

        switch (input)
        {
        case 'N':
            move_player(player, 0, -1, game_board);
            break;
        case 'S':
            move_player(player, 0, 1, game_board);
            break;
        case 'W':
            move_player(player, -1, 0, game_board);
            break;
        case 'E':
            move_player(player, 1, 0, game_board);
            break;
        case 'Q':
            std::exit(0);
        default:
            std::cout << "Invalid input. Try again.\n";
        }
    }

    return 0;
}
