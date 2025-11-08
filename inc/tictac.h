// Copyright 2025 Amaya Shabazz
//

#ifndef TICTACTOE_INC_TICTAC_H_
#define TICTACTOE_INC_TICTAC_H_

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// The game board
// 0 = Empty, 1 = Player 1, 2 = Player 2
struct Board {
    int board[3][3];
    char player1;
    char player2;
};

// Draws the board
void Draw(Board gameBoard);

// Checks to see if a board space is occupied by a player
// Returns if a player was in the spot
bool CheckBoardForPlayer(Board gameBoard, int row, int col);

// Resets the players and creates a new board
// Returns the newly created board
Board Reset(char player1, char player2);

// Start the game loop
void StartGame(Board &gameBoard);

// Updates the board after player turns
// Returns a bool if the game is over
bool UpdateBoard(Board &currBoard);

// Checks if a player has won
// Returns the player's number if they have won, else returns a 0
int CheckWin(Board &currBoard);

#endif  // TICTACTOE_INC_TICTAC_H_
