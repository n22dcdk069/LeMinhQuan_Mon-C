#include <iostream>

int main() {
    // Get user input
    int sideLength;

    do {
        std::cout << "Enter a positive integer (no greater than 15) for the side length of the square: ";
        std::cin >> sideLength;

        if (sideLength <= 0 || sideLength > 15) {
            std::cout << "Please enter a positive integer no greater than 15.\n";
        }
    } while (sideLength <= 0 || sideLength > 15);

    // Display the square
    for (int row = 0; row < sideLength; ++row) {
        for (int col = 0; col < sideLength; ++col) {
            std::cout << "X";
        }
        std::cout << "\n";
    }

    return 0;
}
