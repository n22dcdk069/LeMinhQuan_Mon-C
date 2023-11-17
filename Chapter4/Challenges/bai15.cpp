#include <iostream>

int main() {
    // Constants for rate per 500 miles
    const double RATE_2KG_OR_LESS = 1.10;
    const double RATE_OVER_2KG_UP_TO_6KG = 2.20;
    const double RATE_OVER_6KG_UP_TO_10KG = 3.70;
    const double RATE_OVER_10KG_UP_TO_20KG = 4.80;
    
    // Input variables
    double weight, distance;

    // Get user input for weight and distance
    std::cout << "Enter the weight of the package in kilograms: ";
    std::cin >> weight;

    // Input validation for weight
    if (weight <= 0 || weight > 20) {
        std::cout << "Invalid weight. Weight must be between 0 and 20 kilograms." << std::endl;
        return 1; // Exit the program with an error code
    }

    std::cout << "Enter the distance to be shipped in miles: ";
    std::cin >> distance;

    // Input validation for distance
    if (distance < 10 || distance > 3000) {
        std::cout << "Invalid distance. Distance must be between 10 and 3000 miles." << std::endl;
        return 1; // Exit the program with an error code
    }

    // Calculate charges based on weight
    double charges;

    if (weight <= 2) {
        charges = (distance / 500) * RATE_2KG_OR_LESS;
    } else if (weight <= 6) {
        charges = (distance / 500) * RATE_OVER_2KG_UP_TO_6KG;
    } else if (weight <= 10) {
        charges = (distance / 500) * RATE_OVER_6KG_UP_TO_10KG;
    } else {
        charges = (distance / 500) * RATE_OVER_10KG_UP_TO_20KG;
    }

    // Display the shipping charges
    std::cout << "Shipping charges: $" << charges << std::endl;

    return 0;
}
