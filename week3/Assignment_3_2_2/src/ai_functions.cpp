#include <iostream>

#include "board.h"
#include "ai_functions.h"
#include "game_functions.h"

/* Minimax algorithm implementation to determine the best score for the
 * AI player */
int minimax(char board[BOARD_SIZE][BOARD_SIZE], int empty_spaces, bool is_ai_turn)
{
    /* Check if the game has been won
     * - Function check_if_won returns a char */
    char result{check_if_won(board)};
    if (result == PLAYER1)
    {
        return -10;
    }
    if (result == PLAYER2)
    {
        return 10;
    }
    if (empty_spaces == 0)
    {
        return 0;
    }

    if (is_ai_turn)
    {
        int best_score{-1000};
        for (int x{0}; x < BOARD_SIZE; ++x)
        {
            for (int y{0}; y < BOARD_SIZE; ++y)
            {
                if (board[x][y] == EMPTY_SQUARE)
                {
                    // Try AI's move
                    board[x][y] = PLAYER2;
                    int score = minimax(board, empty_spaces - 1, false);
                    best_score = std::max(score, best_score);
                    // Undo the AI's move
                    board[x][y] = EMPTY_SQUARE;
                }
            }
        }
        return best_score;
    }
    else
    {
        int best_score{1000};
        for (int x{0}; x < BOARD_SIZE; ++x)
        {
            for (int y{0}; y < BOARD_SIZE; ++y)
            {
                if (board[x][y] == EMPTY_SQUARE)
                {
                    // Try Player1's move
                    board[x][y] = PLAYER1;
                    int score{minimax(board, empty_spaces - 1, true)};
                    best_score = std::min(score, best_score);
                    // Undo the move
                    board[x][y] = EMPTY_SQUARE;
                }
            }
        }
        return best_score;
    }
}

// Function for the AI's turn
void ai_turn(char board[BOARD_SIZE][BOARD_SIZE], int empty_spaces)
{
    std::cout << "AI turn:\n";
    int best_score{-1000};
    int best_x{};
    int best_y{};

    for (int x{0}; x < BOARD_SIZE; ++x)
    {
        for (int y{0}; y < BOARD_SIZE; ++y)
        {
            if (board[x][y] == EMPTY_SQUARE)
            {
                // Try AI's move
                board[x][y] = PLAYER2;
                int score{minimax(board, empty_spaces - 1, false)};
                if (score > best_score)
                {
                    best_score = score;
                    best_x = x;
                    best_y = y;
                }
                // Undo the move
                board[x][y] = EMPTY_SQUARE;
            }
        }
    }
    // Make the best move for the AI
    board[best_x][best_y] = PLAYER2;
}
