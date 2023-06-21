#include <iostream>
#include <vector>
#include <string>

#include "board.h"
#include "game_functions.h"
#include "ai_functions.h"

// Function to check i a player has won
char check_if_won(const char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i{0}; i < BOARD_SIZE; ++i)
    {
        char first_square{board[i][0]};
        if (first_square == EMPTY_SQUARE)
        {
            continue;
        }
        if (first_square == board[i][1] && first_square == board[i][2])
        {
            return first_square;
        }

        first_square = board[0][i];

        if (first_square == EMPTY_SQUARE)
        {
            continue;
        }
        if (first_square == board[1][i] && first_square == board[2][i])
        {
            return first_square;
        }
    }

    char central_square = board[1][1];

    if (central_square != EMPTY_SQUARE &&
        ((board[0][0] == central_square && board[2][2] == central_square) ||
         (board[0][2] == central_square && board[2][0] == central_square)))
    {
        return central_square;
    }
    return EMPTY_SQUARE;
}

// Function to check if a move is allowed
bool validate_move(const int row, const int column, const char board[][BOARD_SIZE])
{
    // Allows values 0 - 2
    if (row < 0 || row >= BOARD_SIZE || column < 0 || column >= BOARD_SIZE)
    {
        std::cout << "You cannot move out of the board! Please try again!\n\n";
        return false;
    }
    // If a place not empty
    if (board[row][column] != EMPTY_SQUARE)
    {
        std::cout << "The place is already taken! Please try again!\n\n";
        return false;
    }
    return true;
}

// Function to make move
void make_move(const bool player1_turn, char board[][BOARD_SIZE])
{
    int row{};
    int column{};

    while (true)
    {
        if (player1_turn)
        {
            std::cout << "Player1 turn:\n\n";
        }
        else
        {
            std::cout << "Player2 turn:\n\n";
        }
        std::cout << "Enter the row (1 - 3): ";
        std::cin >> row;
        row -= 1;

        std::cout << "Enter the column (1 - 3): ";
        std::cin >> column;
        column -= 1;

        if (!validate_move(row, column, board))
        {
            continue;
        }

        break;
    }

    if (player1_turn)
    {
        board[row][column] = PLAYER1;
    }
    else
    {
        board[row][column] = PLAYER2;
    }
}

void play_game(int mode)
{
    char board[BOARD_SIZE][BOARD_SIZE];

    initialize_board(board);

    // True if PLAYER1 turn
    bool player1_turn{true};

    bool game_over{false};

    int empty_spaces{9};

    char won{};

    // Game loop
    while (!game_over)
    {
        make_move(player1_turn, board);

        print_board(board);

        --empty_spaces;

        won = check_if_won(board);

        if (won == PLAYER1)
        {
            std::cout << "Player 1 won! GAME IS OVER!\n\nReturning to the main Game Menu ..\n\n";
            break;
        }

        // If neither won before the game board is full
        if (empty_spaces == 0)
        {
            std::cout << "It's a draw! GAME IS OVER!\n\nReturning to the main Game Menu ..\n\n";
            break;
        }

        // Changes the player turn
        player1_turn = !player1_turn;

        // If selected to play against AI
        if (mode == 2)
        {
            ai_turn(board, empty_spaces);

            --empty_spaces;

            print_board(board);

            won = check_if_won(board);

            player1_turn = true;
        }

        if (won == PLAYER2)
        {
            std::string player_name{};
            if (mode == 1)
            {
                player_name = "Player 2";
            }
            else if (mode == 2)
            {
                player_name = "AI";
            }

            std::cout << player_name << " won! GAME IS OVER!\n\nReturning to the main Game Menu ..\n\n";

            break;
        }
    }
}
