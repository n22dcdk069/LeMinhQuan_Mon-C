#include <iostream>

const int SIZE = 3;

bool isLoShuMagicSquare(int square[][SIZE]) {
    // Calculate the sum of the first row to use as a reference
    int sumReference = 0;
    for (int j = 0; j < SIZE; ++j) {
        sumReference += square[0][j];
    }

    // Check the sum of each row
    for (int i = 1; i < SIZE; ++i) {
        int sumRow = 0;
        for (int j = 0; j < SIZE; ++j) {
            sumRow += square[i][j];
        }
        if (sumRow != sumReference) {
            return false;
        }
    }

    // Check the sum of each column
    for (int j = 0; j < SIZE; ++j) {
        int sumCol = 0;
        for (int i = 0; i < SIZE; ++i) {
            sumCol += square[i][j];
        }
        if (sumCol != sumReference) {
            return false;
        }
    }

    // Check the sum of the main diagonal
    int sumDiagonal1 = 0;
    for (int i = 0; i < SIZE; ++i) {
        sumDiagonal1 += square[i][i];
    }
    if (sumDiagonal1 != sumReference) {
        return false;
    }

    // Check the sum of the other diagonal
    int sumDiagonal2 = 0;
    for (int i = 0; i < SIZE; ++i) {
        sumDiagonal2 += square[i][SIZE - 1 - i];
    }
    if (sumDiagonal2 != sumReference) {
        return false;
    }

    // If all checks pass, it is a Lo Shu Magic Square
    return true;
}

int main() {
    // Example Lo Shu Magic Square
    int loShuSquare[SIZE][SIZE] = {
        {4, 9, 2},
        {3, 5, 7},
        {8, 1, 6}
    };

    // Test the function
    if (isLoShuMagicSquare(loShuSquare)) {
        std::cout << "The array is a Lo Shu Magic Square.\n";
    } else {
        std::cout << "The array is not a Lo Shu Magic Square.\n";
    }

    return 0;
}
