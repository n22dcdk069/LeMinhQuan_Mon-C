#include <iostream>
#include <iomanip>

class Population {
private:
    double population;
    double numBirths;
    double numDeaths;

public:
    // Constructor
    Population(double pop, double births, double deaths) : population(pop), numBirths(births), numDeaths(deaths) {
        // Input validation
        if (population < 1 || numBirths < 0 || numDeaths < 0) {
            std::cerr << "Invalid input. Population should be at least 1, and birth and death numbers should be non-negative.\n";
            exit(1); // Exit program with an error code
        }
    }

    // Mutator functions
    void setPopulation(double pop) {
        if (pop < 1) {
            std::cerr << "Invalid input. Population should be at least 1.\n";
            exit(1); // Exit program with an error code
        }
        population = pop;
    }

    void setNumBirths(double births) {
        if (births < 0) {
            std::cerr << "Invalid input. Birth number should be non-negative.\n";
            exit(1); // Exit program with an error code
        }
        numBirths = births;
    }

    void setNumDeaths(double deaths) {
        if (deaths < 0) {
            std::cerr << "Invalid input. Death number should be non-negative.\n";
            exit(1); // Exit program with an error code
        }
        numDeaths = deaths;
    }

    // Accessor functions
    double getPopulation() const {
        return population;
    }

    double getNumBirths() const {
        return numBirths;
    }

    double getNumDeaths() const {
        return numDeaths;
    }

    // Member functions to calculate birth rate and death rate
    double calculateBirthRate() const {
        return numBirths / population;
    }

    double calculateDeathRate() const {
        return numDeaths / population;
    }
};

int main() {
    double population, numBirths, numDeaths;

    // Get user input for population, number of births, and number of deaths
    std::cout << "Enter the population: ";
    std::cin >> population;

    std::cout << "Enter the number of births: ";
    std::cin >> numBirths;

    std::cout << "Enter the number of deaths: ";
    std::cin >> numDeaths;

    // Create an instance of the Population class
    Population myPopulation(population, numBirths, numDeaths);

    // Display the birth rate and death rate
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nBirth Rate: " << myPopulation.calculateBirthRate() << std::endl;
    std::cout << "Death Rate: " << myPopulation.calculateDeathRate() << std::endl;

    return 0;
}
