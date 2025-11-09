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

// Checks if board space occupied by player then draws the player in that spot
// Returns if a player was in the spot
bool CheckBoardForPlayer(Board gameBoard, int row, int col);

// Checks a specific spot to see if occupied
// Returns if the spot is occupied
bool IsSpotOccupied(Board gameBoard, int spot);

// Checks a row to see if all spots are filled by 1 player
// Returns 0 if no player wins, or the player number that won
int CheckRow(Board gameBoard, int row);

// Checks a column to see if all spots are filled by 1 player
// Returns 0 if no player wins, or the player number that won
int CheckCol(Board gameBoard, int col);

// Checks the diagonal to see if all spots are filled by 1 player
// Returns 0 if no player wins, or the player number that won
int CheckDiag(Board gameBoard);

// Resets the players and creates a new board
// Returns the newly created board
Board Reset(char player1, char player2);

// Start the game loop
void StartGame(Board &gameBoard);

// Starts the player's turn
// Returns if the game is over
bool StartTurn(Board &gameBoard, int player);

// Updates the board after player turns
// Returns a bool if the game is over
bool UpdateBoard(Board &gameBoard, int player, int spot);

// Checks to see if there are no spaces open or if a player has one
bool CheckGameOver(Board gameBoard);

// Checks if a player has won
// Returns the player's number if they have won, else returns a 0
int CheckWin(Board gameBoard);

#endif  // TICTACTOE_INC_TICTAC_H_
