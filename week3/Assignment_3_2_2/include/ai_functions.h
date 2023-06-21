// ai_functions.h
#ifndef AI_FUNCTIONS_H
#define AI_FUNCTIONS_H

#include "board.h"

/* Minimax algorithm implementation to determine the best score for the
 * AI player */
int minimax(char board[BOARD_SIZE][BOARD_SIZE], int empty_spaces, bool is_ai_turn);

// Function for the AI's turn to make the best move
void ai_turn(char board[BOARD_SIZE][BOARD_SIZE], int empty_spaces);

#endif
