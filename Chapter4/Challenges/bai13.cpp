#include <iostream>

int main() {
    // Get user input for the number of books purchased
    int booksPurchased;

    std::cout << "Enter the number of books purchased this month: ";
    std::cin >> booksPurchased;

    // Calculate points based on the number of books
    int points = 0;

    if (booksPurchased == 1) {
        points = 5;
    } else if (booksPurchased == 2) {
        points = 15;
    } else if (booksPurchased == 3) {
        points = 30;
    } else if (booksPurchased >= 4) {
        points = 60;
    }

    // Display the number of points awarded
    std::cout << "You have earned " << points << " points." << std::endl;

    return 0;
}
