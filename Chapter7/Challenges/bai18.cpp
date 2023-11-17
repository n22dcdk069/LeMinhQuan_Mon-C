#include <iostream>

const int BOARD_SIZE = 3;

void initializeBoard(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = '*';
        }
    }
}

void displayBoard(const char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

bool isValidMove(const char board[][BOARD_SIZE], int row, int col) {
    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == '*');
}

bool checkWin(const char board[][BOARD_SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool isBoardFull(const char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == '*') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int row, col;
    char currentPlayer = 'X';

    // Initialize the board
    initializeBoard(board);

    // Game loop
    while (true) {
        // Display the current state of the board
        displayBoard(board);

        // Get the player's move
        do {
            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            std::cin >> row >> col;
        } while (!isValidMove(board, row, col));

        // Make the move
        board[row][col] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            // Display the final state of the board
            displayBoard(board);

            // Declare the winner
            std::cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        // Check for a tie
        if (isBoardFull(board)) {
            // Display the final state of the board
            displayBoard(board);

            // Declare a tie
            std::cout << "It's a tie!\n";
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
