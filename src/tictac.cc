// Copyright 2025 Amaya Shabazz
//

#include <TicTacToe/inc/tictac.h>

int main(int arc, char* argv[]) {
    
    cout << "---------------------" << endl;
    cout << "-----TIC-TAC-TOE-----" << endl;
    cout << "---------------------" << endl;

    char player1;
    bool validInput = false;
    while (!validInput) {
        cout << "Player 1 choose your symbol: 'X' or 'O'" << endl;
        cin >> player1;

        player1 = std::toupper(player1);
        if (player1 != 'X' && player1 != 'O') {
            cout << "Invalid input!" << endl;
        } else {
            validInput = true;
        }
    }

    char player2;
    if (player1 == 'X') {
        player2 = 'O';
    } else {
        player2 = 'X';
    }

    bool end = false;
    while (!end) {
        Board board = Reset(player1, player2);
        StartGame(board);

        char choice;
        bool validInput = false;
        while (!validInput) {
            cout << "Enter 'Y' to play again.\nEnter 'N' to quit." << endl;
            cin >> choice;
            if (choice == 'N' || choice == 'n') {
                validInput = true;
                end = true;
            } else if (choice == 'Y' || choice == 'y') {
                validInput = true;
            } else {
                cout << "Invalid input!" << endl;
            }
        }
    }
    
    cout << "---------------------" << endl;
    cout << "-------Goodbye-------" << endl;
    cout << "---------------------" << endl;

    return 0;
}

void Draw(Board gameBoard) {
    //  -------------------
    //      BOARD LAYOUT
    //      1 | 2 | 3
    //      ---+---+---
    //      4 | 5 | 6
    //      ---+---+---
    //      7 | 8 | 9
    //  -------------------
    
    int spotCount = 0;  // the spot number the loop is on
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            spotCount++;

            // Check if player in this spot
            bool spot = CheckBoardForPlayer(gameBoard, i, j);
            if (!spot) {
                cout << spotCount;
            }

            if (j < 2) cout << " | ";
        }

        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }

    cout << "\n";
}

bool CheckBoardForPlayer(Board gameBoard, int row, int col) {
    if (gameBoard.board[row][col] != 0) {
        switch (gameBoard.board[row][col]) {
        case 1:
            cout << gameBoard.player1;
            break;
        case 2:
            cout << gameBoard.player2;
            break;
        default:
            break;
        }
        return true;
    }

    return false;
}

bool IsSpotOccupied(Board gameBoard, int spot) {
    int count = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (count == spot && gameBoard.board[i][j] != 0) {
                return true;
            }
            count++;
        }
    }

    return false;
}

Board Reset(char player1, char player2) {
    Board gameBoard = { 
        {
            0,0,0
        }, 
    player1, player2};

    return gameBoard;
}

void StartGame(Board &gameBoard) {
    bool gameOver = false;

    // Draw board
    Draw(gameBoard);

    while (!gameOver) {
        // Player 1's turn
        gameOver = StartTurn(gameBoard, 1);

        // Player 2's turn
        gameOver = StartTurn(gameBoard, 2);
    }
}

bool StartTurn(Board &gameBoard, int player) {
    int spot;

    // Ensure valid choice
    bool valid = false;
    do {
        cout << "Player " << player << ", enter the number of the spot you want to select: ";

        if (!(cin >> spot)) {
            cout << "Invalid input!" << endl;
            cin.clear(); // Clear the error flags on cin
            // Discard invalid input from the buffer up to the newline character
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (spot <= 0 || spot >= 10) {
            cout << "Invalid input!" << endl;
        } else if (IsSpotOccupied(gameBoard, spot)) {  // spot already taken
            cout << "Spot taken. Invalid input!" << endl;
        } else {
            valid = true;
        }

    } while (!valid);

    // Add the player to their spot
    bool gameOver = UpdateBoard(gameBoard, player, spot);

    return gameOver;
}

bool UpdateBoard(Board &gameBoard, int player, int spot) {
    bool gameOver = false;

    // Loop through board to find spot
    int count = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            
            if (count == spot) {
                gameBoard.board[i][j] = player;
            }
            count ++;
        }
    }

    // Check for gameOver
    gameOver = CheckGameOver(gameBoard);

    Draw(gameBoard);

    return gameOver;
}

bool CheckGameOver(Board gameBoard) {
    // Check if a player has won
    int winner = CheckWin(gameBoard);
    if (winner != 0) {
        cout << "Player " << winner << " wins!" << endl;
        return true;
    }

    // Check if no empty spots left
    int emptySpots = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gameBoard.board[i][j] == 0) {
                emptySpots++;
            }
        }
    }

    if (emptySpots == 0) {
        return true;
    }

    return false;
}

int CheckWin(Board gameBoard) {
    int winner = 0;

    // If a player has 3 in a row...they win
    int player1Counts = 0;
    int player2Counts = 0;
    for (int i = 0; i < 3; i++) {
        // Only have to check it's neighbors
        for (int j = 0; j < 3; j++) {
            
        }
    }

    return winner;
}
