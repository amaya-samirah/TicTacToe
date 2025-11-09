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
        if (StartTurn(gameBoard, 1)) {
            break;
        }
        
        // Player 2's turn
        if (StartTurn(gameBoard, 2)) {
            break;
        }
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
        cout << "---------------------" << endl;
        cout << "Player " << winner << " wins!" << endl;
        cout << "---------------------" << endl;
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
        cout << "---------------------" << endl;
        cout << "Draw!!" << endl;
        cout << "---------------------" << endl;
        return true;
    }

    return false;
}

int CheckWin(Board gameBoard) {
    int winner = 0;
    cout << "Checking win..." << endl;
    // Check same diagonal
    winner = CheckDiag(gameBoard);
    if (winner > 0) {
        return winner;
    }

    // Check neighbors
    for (int row = 0; row < 3; row++) {
        // Check same row
        if (gameBoard.board[row][0] != 0) {
           winner = CheckRow(gameBoard, row);
           if (winner > 0) {
                break;
           }
        }
        
        for (int col = 0; col < 3; col++) {
            if (gameBoard.board[row][col] != 0) {
                // Check same column
                winner = CheckCol(gameBoard, col);
                if (winner > 0) {
                    break;
                }
            }
        }
    }

    return winner;
}

int CheckDiag(Board gameBoard) {

    // Right diagonal
    if (gameBoard.board[0][0] != 0 
        && gameBoard.board[0][0] == gameBoard.board[1][1] 
        && gameBoard.board[1][1] == gameBoard.board[2][2]) {
            cout << "Checking diagonal..." << endl;

            switch (gameBoard.board[0][0])
            {
            case 1:
                return 1;
                break;
            case 2:
                return 2;
                break;
            default:
                break;
            } 
    }

    // Left diagonal
    if (gameBoard.board[0][2] != 0 
        && gameBoard.board[0][2] == gameBoard.board[1][1] 
        && gameBoard.board[1][1] == gameBoard.board[2][0]) {
            cout << "Checking diagonal..." << endl;
            switch (gameBoard.board[0][2])
            {
            case 1:
                return 1;
                break;
            case 2:
                return 2;;
                break;
            default:
                break;
            } 
    }

    return 0;
}

int CheckCol(Board gameBoard, int col) {
    int player1 = 0, player2 = 0;

    // Check all rows for col's index
    for (int i = 0; i < 3; i++) {
        switch (gameBoard.board[i][col])
        {
        case 1:
            player1++;
            break;
        case 2:
            player2++;
            break;
        default:
            break;
        }
    }

    if (player1 == 3) {
        return 1;
    } else if (player2 == 3) {
        return 2;
    } else {
        return 0;
    }
}

int CheckRow(Board gameBoard, int row) {
    int player1 = 0, player2 = 0;

    for (int j = 0; j < 3; j++) {
        switch (gameBoard.board[row][j])
        {
        case 1:
            player1++;
            break;
        case 2:
            player2++;
            break;
        default:
            break;
        }
    }

    if (player1 == 3) {
        return 1;
    } else if (player2 == 3) {
        return 2;
    } else {
        return 0;
    }
}
