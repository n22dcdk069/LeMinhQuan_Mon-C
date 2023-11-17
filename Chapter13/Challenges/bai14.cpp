#include <iostream>
#include <cstdlib> // for rand() function
#include <ctime>   // for time() function

// Die class for simulating a six-sided die
class Die {
public:
    int roll() const {
        return rand() % 6 + 1;
    }
};

// FishingGame class to manage the fishing game
class FishingGame {
private:
    Die die;          // Die object for rolling
    int totalPoints;  // Total fishing points

public:
    // Constructor initializes totalPoints to 0
    FishingGame() : totalPoints(0) {
        // Seed the random number generator
        srand(static_cast<unsigned int>(time(0)));
    }

    // Function to simulate a fishing round
    void fish() {
        char choice;
        do {
            std::cout << "Do you want to fish? (y/n): ";
            std::cin >> choice;

            if (choice == 'y' || choice == 'Y') {
                int rollResult = die.roll();
                int points = getPoints(rollResult);
                totalPoints += points;

                std::cout << "You caught ";
                displayItem(rollResult);
                std::cout << " (" << points << " points)\n\n";
            }

        } while (choice == 'y' || choice == 'Y');
    }

    // Function to display the item based on the roll result
    void displayItem(int rollResult) const {
        switch (rollResult) {
            case 1:
                std::cout << "a huge fish";
                break;
            case 2:
                std::cout << "an old shoe";
                break;
            case 3:
                std::cout << "a little fish";
                break;
            // Add more cases for other items as needed
            default:
                std::cout << "something unexpected";
        }
    }

    // Function to determine points based on the roll result
    int getPoints(int rollResult) const {
        switch (rollResult) {
            case 1:
                return 10; // Points for a huge fish
            case 2:
                return 1;  // Points for an old shoe
            case 3:
                return 5;  // Points for a little fish
            // Add more cases for other items as needed
            default:
                return 0;  // No points for something unexpected
        }
    }

    // Function to display the total points and a congratulatory message
    void displayResult() const {
        std::cout << "\nTotal fishing points: " << totalPoints << "\n";

        if (totalPoints >= 15) {
            std::cout << "Congratulations! You are a master fisher!\n";
        } else if (totalPoints >= 5) {
            std::cout << "Nice fishing! You caught some good items.\n";
        } else {
            std::cout << "Better luck next time! Keep practicing.\n";
        }
    }
};

int main() {
    FishingGame game;
    game.fish();         // Simulate the fishing game
    game.displayResult(); // Display the result

    return 0;
}
