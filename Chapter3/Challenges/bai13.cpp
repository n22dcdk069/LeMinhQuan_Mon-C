#include <iostream>
#include <iomanip> // For setting precision

int main() {
    // Constants for conversion factors
    const double YEN_PER_DOLLAR = 98.93;
    const double EUROS_PER_DOLLAR = 0.74;

    // Variable to store the dollar amount entered by the user
    double dollarAmount;

    // Get user input for the dollar amount
    std::cout << "Enter the dollar amount: $";
    std::cin >> dollarAmount;

    // Calculate the equivalent amounts in yen and euros
    double yenAmount = dollarAmount * YEN_PER_DOLLAR;
    double eurosAmount = dollarAmount * EUROS_PER_DOLLAR;

    // Display the results with fixed-point notation and two decimal places
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nEquivalent amount in Japanese Yen: " << yenAmount << " Yen\n";
    std::cout << "Equivalent amount in Euros: " << eurosAmount << " Euros\n";

    return 0;
}
