#include <iostream>
#include <iomanip>
#include <climits>

const int numRows = 3;
const int numCols = 4;

// Function prototypes
int getTotal(const int array[][numCols]);
double getAverage(const int array[][numCols]);
int getRowTotal(const int array[][numCols], int row);
int getColumnTotal(const int array[][numCols], int col);
int getHighestInRow(const int array[][numCols], int row);
int getLowestInRow(const int array[][numCols], int row);

int main() {
    // Test data initialization
    int testData[numRows][numCols] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Display the array
    std::cout << "Array:\n";
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            std::cout << std::setw(4) << testData[i][j];
        }
        std::cout << std::endl;
    }

    // Test the functions
    std::cout << "\nTotal of all values: " << getTotal(testData) << std::endl;
    std::cout << "Average of all values: " << getAverage(testData) << std::endl;

    int rowToTest = 1;
    std::cout << "Total of row " << rowToTest << ": " << getRowTotal(testData, rowToTest) << std::endl;

    int colToTest = 2;
    std::cout << "Total of column " << colToTest << ": " << getColumnTotal(testData, colToTest) << std::endl;

    std::cout << "Highest value in row " << rowToTest << ": " << getHighestInRow(testData, rowToTest) << std::endl;
    std::cout << "Lowest value in row " << rowToTest << ": " << getLowestInRow(testData, rowToTest) << std::endl;

    return 0;
}

int getTotal(const int array[][numCols]) {
    int total = 0;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            total += array[i][j];
        }
    }
    return total;
}

double getAverage(const int array[][numCols]) {
    return static_cast<double>(getTotal(array)) / (numRows * numCols);
}

int getRowTotal(const int array[][numCols], int row) {
    int total = 0;
    for (int j = 0; j < numCols; ++j) {
        total += array[row][j];
    }
    return total;
}

int getColumnTotal(const int array[][numCols], int col) {
    int total = 0;
    for (int i = 0; i < numRows; ++i) {
        total += array[i][col];
    }
    return total;
}

int getHighestInRow(const int array[][numCols], int row) {
    int highest = INT_MIN;
    for (int j = 0; j < numCols; ++j) {
        if (array[row][j] > highest) {
            highest = array[row][j];
        }
    }
    return highest;
}

int getLowestInRow(const int array[][numCols], int row) {
    int lowest = INT_MAX;
    for (int j = 0; j < numCols; ++j) {
        if (array[row][j] < lowest) {
            lowest = array[row][j];
        }
    }
    return lowest;
}
