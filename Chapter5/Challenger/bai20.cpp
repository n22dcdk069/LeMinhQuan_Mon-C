#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Generate a random number between 1 and 100
    int randomNumber = std::rand() % 100 + 1;

    // Variables
    int userGuess;
    int attempts = 0;

    // Start the game loop
    do {
        // Get user's guess
        std::cout << "Guess the number (between 1 and 100): ";
        std::cin >> userGuess;

        // Check the user's guess
        if (userGuess > randomNumber) {
            std::cout << "Too high, try again.\n";
        } else if (userGuess < randomNumber) {
            std::cout << "Too low, try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the number in " << attempts + 1 << " attempts.\n";
        }

        // Increment the attempts
        attempts++;

    } while (userGuess != randomNumber);

    return 0;
}
