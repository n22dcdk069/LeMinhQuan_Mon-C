#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    // Read teams from Teams.txt
    std::ifstream teamsFile("Teams.txt");
    if (!teamsFile) {
        std::cerr << "Error opening Teams.txt\n";
        return 1;
    }

    std::cout << "List of Major League Baseball Teams:\n";
    std::string team;
    while (std::getline(teamsFile, team)) {
        std::cout << team << "\n";
    }

    // Prompt the user to enter a team name
    std::cout << "\nEnter the name of a team to see the number of World Series wins: ";
    std::string userTeam;
    std::getline(std::cin, userTeam);

    // Read World Series winners from WorldSeriesWinners.txt
    std::ifstream winnersFile("WorldSeriesWinners.txt");
    if (!winnersFile) {
        std::cerr << "Error opening WorldSeriesWinners.txt\n";
        return 1;
    }

    std::vector<std::string> winners;
    while (std::getline(winnersFile, team)) {
        winners.push_back(team);
    }

    // Count the number of times the user's team has won the World Series
    int count = 0;
    for (const auto& winner : winners) {
        if (winner == userTeam) {
            ++count;
        }
    }

    // Display the result
    std::cout << "\n" << userTeam << " has won the World Series " << count << " times from 1903 to 2012.\n";

    return 0;
}
