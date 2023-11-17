#include <iostream>

// Function prototype
double kineticEnergy(double mass, double velocity);

int main() {
    // Get user input for mass and velocity
    double mass, velocity;

    std::cout << "Enter the mass of the object (in kilograms): ";
    std::cin >> mass;

    std::cout << "Enter the velocity of the object (in meters per second): ";
    std::cin >> velocity;

    // Calculate kinetic energy using the function
    double energy = kineticEnergy(mass, velocity);

    // Display the result
    std::cout << "The kinetic energy of the object is: " << energy << " joules\n";

    return 0;
}

// Function to calculate kinetic energy
double kineticEnergy(double mass, double velocity) {
    // Formula: KE = 0.5 * mass * velocity^2
    return 0.5 * mass * velocity * velocity;
}
