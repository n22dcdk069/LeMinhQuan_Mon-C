#include <iostream>
#include <cmath>

// Function prototype for population projection
double calculatePopulation(int startingSize, double birthRate, double deathRate, int arrivals, int departures, int numYears);

int main() {
    // Input variables
    int startingSize, numYears, arrivals, departures;
    double birthRate, deathRate;

    // Get input from the user
    std::cout << "Enter the starting population size: ";
    std::cin >> startingSize;

    // Input validation: Do not accept numbers less than 2 for the starting size
    while (startingSize < 2) {
        std::cout << "Invalid input. Please enter a starting population size greater than or equal to 2: ";
        std::cin >> startingSize;
    }

    std::cout << "Enter the annual birth rate (as a percentage): ";
    std::cin >> birthRate;

    // Input validation: Do not accept negative numbers for birth rate
    while (birthRate < 0) {
        std::cout << "Invalid input. Please enter a non-negative annual birth rate: ";
        std::cin >> birthRate;
    }

    std::cout << "Enter the annual death rate (as a percentage): ";
    std::cin >> deathRate;

    // Input validation: Do not accept negative numbers for death rate
    while (deathRate < 0) {
        std::cout << "Invalid input. Please enter a non-negative annual death rate: ";
        std::cin >> deathRate;
    }

    std::cout << "Enter the number of individuals who typically move into the area each year: ";
    std::cin >> arrivals;

    // Input validation: Do not accept negative numbers for arrivals
    while (arrivals < 0) {
        std::cout << "Invalid input. Please enter a non-negative number for arrivals: ";
        std::cin >> arrivals;
    }

    std::cout << "Enter the number of individuals who typically leave the area each year: ";
    std::cin >> departures;

    // Input validation: Do not accept negative numbers for departures
    while (departures < 0) {
        std::cout << "Invalid input. Please enter a non-negative number for departures: ";
        std::cin >> departures;
    }

    std::cout << "Enter the number of years for the population projection: ";
    std::cin >> numYears;

    // Input validation: Do not accept numbers less than 1 for the projection years
    while (numYears < 1) {
        std::cout << "Invalid input. Please enter a number of years greater than or equal to 1 for projection: ";
        std::cin >> numYears;
    }

    // Calculate and display the projected population
    double projectedPopulation = calculatePopulation(startingSize, birthRate, deathRate, arrivals, departures, numYears);
    std::cout << "The projected population after " << numYears << " years is: " << static_cast<int>(projectedPopulation) << std::endl;

    return 0;
}

// Function definition for population projection
double calculatePopulation(int startingSize, double birthRate, double deathRate, int arrivals, int departures, int numYears) {
    double netMigrationRate = (arrivals - departures) / 100.0;
    double growthRate = (birthRate - deathRate) / 100.0;
    
    // Calculate the projected population using the formula: P = P0 * e^(rt)
    double projectedPopulation = startingSize * exp(numYears * (growthRate + netMigrationRate));

    return projectedPopulation;
}
