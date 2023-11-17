#include <iostream>
#include <iomanip>

int main() {
    int startingSize, numDays;
    double dailyIncrease;

    // Get the starting size of the population (with input validation)
    do {
        std::cout << "Enter the starting size of the population (must be 2 or more): ";
        std::cin >> startingSize;

        if (startingSize < 2) {
            std::cout << "Please enter a starting size that is 2 or more.\n";
        }
    } while (startingSize < 2);

    // Get the average daily population increase (with input validation)
    do {
        std::cout << "Enter the average daily population increase as a percentage: ";
        std::cin >> dailyIncrease;

        if (dailyIncrease < 0) {
            std::cout << "Please enter a non-negative number for daily population increase.\n";
        }
    } while (dailyIncrease < 0);

    // Get the number of days they will multiply (with input validation)
    do {
        std::cout << "Enter the number of days they will multiply (must be 1 or more): ";
        std::cin >> numDays;

        if (numDays < 1) {
            std::cout << "Please enter a number of days that is 1 or more.\n";
        }
    } while (numDays < 1);

    // Display the table header
    std::cout << std::setw(10) << "Day" << std::setw(20) << "Population Size" << std::endl;
    std::cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << std::endl;

    // Calculate and display the population size for each day
    double population = startingSize;
    for (int day = 1; day <= numDays; ++day) {
        std::cout << std::setw(10) << day << std::setw(20) << std::fixed << std::setprecision(2) << population << std::endl;
        population *= (1 + dailyIncrease / 100); // Calculate the new population size for the next day
    }

    return 0;
}
