// game.h
#ifndef GAME_H
#define GAME_H

#include "cell.h"
#include "player.h"
#include <array>

void fill_game_board_randomly(std::array<std::array<Cell, 10>, 10> &game_board, Player &player);
void print_game_board(const std::array<std::array<Cell, 10>, 10> &game_board);
bool is_possible_move(std::size_t x, std::size_t y);
void move_player(Player &player, int dx, int dy, std::array<std::array<Cell, 10>, 10> &game_board);
char get_user_input();
void print_game_instructions();

#endif
