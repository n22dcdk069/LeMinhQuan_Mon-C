#include <iostream>
#include <cstdlib> // For rand() function

class Coin {
private:
    std::string sideUp; // "Heads" or "Tails"

public:
    // Constructor
    Coin() {
        // Initialize with a random side
        toss();
    }

    // Member function to simulate a coin toss
    void toss() {
        // Generate a random number (0 or 1)
        int randNum = rand() % 2;

        // Set sideUp based on the random number
        if (randNum == 0) {
            sideUp = "Heads";
        } else {
            sideUp = "Tails";
        }
    }

    // Accessor function to get the current side facing up
    std::string getSideUp() const {
        return sideUp;
    }
};

int main() {
    // Seed the random number generator
    srand(time(0));

    // Create instances of the Coin class
    Coin quarter;
    Coin dime;
    Coin nickel;

    double balance = 0.0;

    // Game loop
    while (balance < 1.0) {
        // Toss each coin
        quarter.toss();
        dime.toss();
        nickel.toss();

        // Display the results of the coin tosses
        std::cout << "Quarter: " << quarter.getSideUp() << std::endl;
        std::cout << "Dime: " << dime.getSideUp() << std::endl;
        std::cout << "Nickel: " << nickel.getSideUp() << std::endl;

        // Update the balance based on the coin toss results
        if (quarter.getSideUp() == "Heads") {
            balance += 0.25;
        }
        if (dime.getSideUp() == "Heads") {
            balance += 0.10;
        }
        if (nickel.getSideUp() == "Heads") {
            balance += 0.05;
        }

        // Display the current balance
        std::cout << "Current Balance: $" << balance << std::endl;
        std::cout << "------------------------\n";

        // Check if the game is over
        if (balance >= 1.0) {
            if (balance == 1.0) {
                std::cout << "Congratulations! You win!\n";
            } else {
                std::cout << "Sorry, you lose. Your balance exceeded $1.\n";
            }
        }
    }

    return 0;
}
