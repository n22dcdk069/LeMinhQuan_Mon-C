#include <iostream>
#include <iomanip>

const int NUM_PLAYERS = 12;

// Structure to store soccer player data
struct SoccerPlayer {
    std::string playerName;
    int playerNumber;
    int pointsScored;
};

// Function to input data for a specific player
void inputPlayerData(SoccerPlayer& player) {
    do {
        std::cout << "Enter player's name: ";
        std::getline(std::cin, player.playerName);
    } while (player.playerName.empty());

    do {
        std::cout << "Enter player's number: ";
        std::cin >> player.playerNumber;
        if (player.playerNumber < 0) {
            std::cout << "Please enter a non-negative value for player's number.\n";
        }
    } while (player.playerNumber < 0);

    do {
        std::cout << "Enter points scored by the player: ";
        std::cin >> player.pointsScored;
        if (player.pointsScored < 0) {
            std::cout << "Please enter a non-negative value for points scored.\n";
        }
    } while (player.pointsScored < 0);
}

// Function to display player information and calculate total points
void displayPlayerInfo(const SoccerPlayer players[], int numPlayers) {
    int totalPoints = 0;
    int maxPointsIndex = 0;

    // Display table header
    std::cout << std::setw(10) << "Number" << std::setw(20) << "Name" << std::setw(15) << "Points Scored" << std::endl;
    std::cout << std::string(45, '-') << std::endl;

    // Display player information and calculate total points
    for (int i = 0; i < numPlayers; ++i) {
        std::cout << std::setw(10) << players[i].playerNumber
                  << std::setw(20) << players[i].playerName
                  << std::setw(15) << players[i].pointsScored << std::endl;

        totalPoints += players[i].pointsScored;

        // Check for the player with the maximum points
        if (players[i].pointsScored > players[maxPointsIndex].pointsScored) {
            maxPointsIndex = i;
        }
    }

    // Display total points and player with the most points
    std::cout << std::string(45, '-') << std::endl;
    std::cout << "Total Points: " << totalPoints << std::endl;
    std::cout << "Player with the most points: " << players[maxPointsIndex].playerName
              << " (Number " << players[maxPointsIndex].playerNumber << ") with "
              << players[maxPointsIndex].pointsScored << " points.\n";
}

int main() {
    SoccerPlayer team[NUM_PLAYERS];

    // Input data for each player
    for (int i = 0; i < NUM_PLAYERS; ++i) {
        std::cout << "\nEnter data for Player " << i + 1 << ":\n";
        inputPlayerData(team[i]);
    }

    // Display player information and calculate total points
    displayPlayerInfo(team, NUM_PLAYERS);

    return 0;
}
