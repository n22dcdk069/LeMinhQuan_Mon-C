#include <iostream>
#include <cstdlib>   // For rand() and srand() functions
#include <ctime>     // For time() function

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Generate a random number between 1 and 100
    int secretNumber = std::rand() % 100 + 1;

    int guess;
    int guessCount = 0;

    std::cout << "Welcome to the Number Guessing Game!\n\n";

    do {
        // Get the user's guess
        std::cout << "Enter your guess (1-100): ";
        std::cin >> guess;

        // Increment the guess count
        guessCount++;

        // Check if the guess is correct
        if (guess == secretNumber) {
            std::cout << "Congratulations! You guessed the correct number in " << guessCount << " guesses!\n";
        } else {
            // Provide feedback to the user and hint for the next guess
            std::cout << "Incorrect guess. ";

            if (guess < secretNumber) {
                std::cout << "Try a higher number.\n";
            } else {
                std::cout << "Try a lower number.\n";
            }
        }

    } while (guess != secretNumber);

    return 0;
}
