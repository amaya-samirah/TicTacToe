// Copyright 2025 Amaya Shabazz
//

#include <TicTacToe/inc/tictac.h>

int main(int arc, char* argv[]) {
    
    cout << "---------------------" << endl;
    cout << "-----TIC-TAC-TOE-----" << endl;
    cout << "---------------------" << endl;

    char player1;
    cout << "Player 1 choose your symbol: 'X' or 'O'" << endl;
    cin >> player1;

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
        cout << "Enter 'Y' to play again.\nEnter 'N' to quit." << endl;
        cin >> choice;

        if (choice == 'N') {
            end = true;
        }
    }
    
    cout << "---------------------" << endl;
    cout << "-------Goodbye-------" << endl;
    cout << "---------------------" << endl;

    return 0;
}

void Draw(Board gameBoard) {
    //      1 | 2 | 3
    //      ---+---+---
    //      4 | 5 | 6
    //      ---+---+---
    //      7 | 8 | 9
    int spotCount = 0;  // the spot number the loop is on
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";

        for (int j = 0; j < 3; j++) {
            spotCount++;
            // Check if player in this spot
            bool spot = CheckBoardForPlayer(gameBoard, i, j);
            if (spot) {
                break;
            }

            cout << spotCount;
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

Board Reset(char player1, char player2) {
    Board gameBoard = { 
        {
            0,0,0
        }, 
    player1, player2};

    return gameBoard;
}

void StartGame(Board &gameBoard) {
    // bool gameOver = false;
    // while (!gameOver) {
    //     Draw(gameBoard);
    // }

    Draw(gameBoard);

}

bool UpdateBoard(Board &board) {
    bool gameOver = false;

    return gameOver;
}

int CheckWin(Board &board) {
    int winner = 0;

    return winner;
}
