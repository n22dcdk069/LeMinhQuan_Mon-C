#include <iostream>
#include <cstdlib> // For rand() and srand() functions
#include <ctime>   // For time() function

// Function prototypes
int generateComputerChoice();
std::string getUserChoice();
std::string getComputerChoice(int computerChoice);
void determineWinner(const std::string& userChoice, const std::string& computerChoice);

int main() {
    // Seed for random number generation
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Get user input and play the game
    std::string userChoice = getUserChoice();
    int computerChoice = generateComputerChoice();
    std::string computerChoiceStr = getComputerChoice(computerChoice);

    // Display choices and determine the winner
    std::cout << "\nUser chose: " << userChoice << std::endl;
    std::cout << "Computer chose: " << computerChoiceStr << "\n\n";

    determineWinner(userChoice, computerChoiceStr);

    return 0;
}

// Function to generate a random computer choice (1: Rock, 2: Paper, 3: Scissors)
int generateComputerChoice() {
    return rand() % 3 + 1;
}

// Function to get user choice
std::string getUserChoice() {
    std::string userChoice;
    std::cout << "Enter your choice (rock, paper, or scissors): ";
    std::cin >> userChoice;

    // Convert user input to lowercase for case-insensitive comparison
    for (char& ch : userChoice) {
        ch = tolower(ch);
    }

    return userChoice;
}

// Function to convert computer's numeric choice to string
std::string getComputerChoice(int computerChoice) {
    switch (computerChoice) {
        case 1:
            return "rock";
        case 2:
            return "paper";
        case 3:
            return "scissors";
        default:
            return ""; // Should not reach here
    }
}

// Function to determine the winner
void determineWinner(const std::string& userChoice, const std::string& computerChoice) {
    if (userChoice == computerChoice) {
        std::cout << "It's a tie! Play again.\n";
    } else if ((userChoice == "rock" && computerChoice == "scissors") ||
               (userChoice == "scissors" && computerChoice == "paper") ||
               (userChoice == "paper" && computerChoice == "rock")) {
        std::cout << "You win! " << userChoice << " beats " << computerChoice << ".\n";
    } else {
        std::cout << "You lose! " << computerChoice << " beats " << userChoice << ".\n";
    }
}
