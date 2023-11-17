#include <iostream>

int main() {
    // Constant for acceleration due to gravity
    const double gravity = 9.8;

    // Variables to store mass and weight
    double mass, weight;

    // Get input for the mass of the object
    std::cout << "Enter the mass of the object in kilograms: ";
    std::cin >> mass;

    // Calculate the weight using the formula: weight = mass * gravity
    weight = mass * gravity;

    // Display the calculated weight
    std::cout << "The weight of the object is: " << weight << " newtons\n";

    // Check if the object is too heavy or too light and display a message accordingly
    if (weight > 1000) {
        std::cout << "The object is too heavy.\n";
    } else if (weight < 10) {
        std::cout << "The object is too light.\n";
    }

    return 0;
}
