#include <iostream>
#include <iomanip>

int main() {
    // Constant for the retail price of the package
    const double PACKAGE_PRICE = 99.0;

    // Variables to store user input
    int quantity;

    // Get input for the number of units sold
    std::cout << "Enter the number of units sold: ";
    std::cin >> quantity;

    // Validate the input
    if (quantity <= 0) {
        std::cout << "Error: Number of units must be greater than 0.\n";
        return 1; // Exit the program with an error code
    }

    // Calculate the total cost based on quantity and discounts
    double totalCost;
    if (quantity < 10) {
        totalCost = quantity * PACKAGE_PRICE;
    } else if (quantity >= 10 && quantity <= 19) {
        totalCost = quantity * PACKAGE_PRICE * 0.8; // 20% discount
    } else if (quantity >= 20 && quantity <= 49) {
        totalCost = quantity * PACKAGE_PRICE * 0.7; // 30% discount
    } else if (quantity >= 50 && quantity <= 99) {
        totalCost = quantity * PACKAGE_PRICE * 0.6; // 40% discount
    } else {
        totalCost = quantity * PACKAGE_PRICE * 0.5; // 50% discount
    }

    // Display the result with two decimal places
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total cost of the purchase: $" << totalCost << std::endl;

    return 0;
}
