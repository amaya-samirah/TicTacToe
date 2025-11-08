// Copyright 2025 Amaya Shabazz
//

#ifndef TICTACTOE_INC_TICTAC_H_
#define TICTACTOE_INC_TICTAC_H_

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Board {
    int board[3][3];
};

// Draws the board
void Draw();

// Resets the game and board
void Reset(Board &board);

// Start the game loop
void StartGame();

// Updates the board after player turns
// Returns a bool if the game is over
bool UpdateBoard(Board &currBoard);

// Checks if a player has won
// Returns the player's number if they have won, else returns a 0
int CheckWin(Board &currBoard);

#endif  // TICTACTOE_INC_TICTAC_H_
