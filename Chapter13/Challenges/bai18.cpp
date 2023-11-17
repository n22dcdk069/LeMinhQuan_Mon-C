#include <iostream>
#include <cstdlib> // for rand() function
#include <ctime>   // for time() function

class Die {
public:
    int roll() const {
        return rand() % 6 + 1;
    }
};

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    Die die; // Create a Die object

    int computerTotal = 0;
    int userTotal = 0;

    char rollAgain;
    do {
        // Computer's turn
        int computerRoll1 = die.roll();
        int computerRoll2 = die.roll();
        computerTotal = computerRoll1 + computerRoll2;

        // User's turn
        int userRoll1 = die.roll();
        int userRoll2 = die.roll();
        userTotal += userRoll1 + userRoll2;

        // Display results
        std::cout << "Computer rolls: " << computerRoll1 << " and " << computerRoll2 << "\n";
        std::cout << "User rolls: " << userRoll1 << " and " << userRoll2 << "\n";

        std::cout << "Computer's total: " << computerTotal << "\n";
        std::cout << "User's total: " << userTotal << "\n";

        // Ask the user if they want to roll again
        std::cout << "Do you want to roll again? (y/n): ";
        std::cin >> rollAgain;

    } while (rollAgain == 'y' || rollAgain == 'Y' && userTotal <= 21);

    // Display the winner
    if (userTotal <= 21 && (userTotal > computerTotal || computerTotal > 21)) {
        std::cout << "Congratulations! You win!\n";
    } else {
        std::cout << "Computer wins. Better luck next time!\n";
    }

    return 0;
}
