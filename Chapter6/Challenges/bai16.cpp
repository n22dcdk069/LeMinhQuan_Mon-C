#include <iostream>
#include <iomanip> // For setprecision

// Function prototype
double calculatePopulationSize(double previousPopulation, double birthRate, double deathRate);

int main() {
    // Variables to store input data
    double startingSize, birthRate, deathRate;
    int numYears;

    // Get input data
    do {
        std::cout << "Enter the starting size of the population (must be at least 2): ";
        std::cin >> startingSize;

        if (startingSize < 2) {
            std::cout << "Please enter a valid starting size (at least 2).\n";
        }
    } while (startingSize < 2);

    do {
        std::cout << "Enter the annual birth rate (must be non-negative): ";
        std::cin >> birthRate;

        if (birthRate < 0) {
            std::cout << "Please enter a valid birth rate (non-negative).\n";
        }
    } while (birthRate < 0);

    do {
        std::cout << "Enter the annual death rate (must be non-negative): ";
        std::cin >> deathRate;

        if (deathRate < 0) {
            std::cout << "Please enter a valid death rate (non-negative).\n";
        }
    } while (deathRate < 0);

    do {
        std::cout << "Enter the number of years to display (must be at least 1): ";
        std::cin >> numYears;

        if (numYears < 1) {
            std::cout << "Please enter a valid number of years (at least 1).\n";
        }
    } while (numYears < 1);

    // Display the population size for each year
    double currentPopulation = startingSize;
    std::cout << "\nPopulation Size Over " << numYears << " Years:\n";
    std::cout << "Year\tPopulation Size\n";
    std::cout << "------------------------\n";

    for (int year = 1; year <= numYears; ++year) {
        currentPopulation = calculatePopulationSize(currentPopulation, birthRate, deathRate);
        std::cout << year << "\t" << std::fixed << std::setprecision(2) << currentPopulation << std::endl;
    }

    return 0;
}

// Function to calculate the size of the population for a year
double calculatePopulationSize(double previousPopulation, double birthRate, double deathRate) {
    return previousPopulation + (previousPopulation * birthRate / 100) - (previousPopulation * deathRate / 100);
}
