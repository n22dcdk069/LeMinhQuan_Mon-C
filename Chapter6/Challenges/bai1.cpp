#include <iostream>
#include <iomanip> // For setprecision

// Function to calculate the retail price
double calculateRetail(double wholesaleCost, double markupPercentage) {
    // Validate input: Do not accept negative values
    if (wholesaleCost < 0 || markupPercentage < 0) {
        std::cerr << "Error: Wholesale cost and markup percentage must be non-negative.\n";
        return -1.0; // Return an invalid value
    }

    // Calculate retail price
    double retailPrice = wholesaleCost + (wholesaleCost * markupPercentage / 100.0);
    return retailPrice;
}

int main() {
    double wholesaleCost, markupPercentage;

    // Get input from the user
    std::cout << "Enter the wholesale cost of the item: $";
    std::cin >> wholesaleCost;

    // Input validation: Ensure wholesale cost is non-negative
    while (wholesaleCost < 0) {
        std::cout << "Wholesale cost cannot be negative. Please re-enter: $";
        std::cin >> wholesaleCost;
    }

    std::cout << "Enter the markup percentage: ";
    std::cin >> markupPercentage;

    // Input validation: Ensure markup percentage is non-negative
    while (markupPercentage < 0) {
        std::cout << "Markup percentage cannot be negative. Please re-enter: ";
        std::cin >> markupPercentage;
    }

    // Call the calculateRetail function and display the result
    double retailPrice = calculateRetail(wholesaleCost, markupPercentage);

    if (retailPrice != -1.0) {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "The retail price of the item is: $" << retailPrice << std::endl;
    }

    return 0;
}
