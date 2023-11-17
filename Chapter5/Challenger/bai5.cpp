#include <iostream>
#include <iomanip>

int main() {
    const double initialFee = 2500.0; // Initial membership fee
    const double increaseRate = 0.04; // 4% increase rate per year
    const int numYears = 6;           // Number of years to project

    // Display the table header
    std::cout << std::setw(10) << "Year" << std::setw(20) << "Membership Fee ($)" << std::endl;
    std::cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << std::endl;

    // Display the projected fees for the next six years
    double currentFee = initialFee;
    for (int year = 1; year <= numYears; ++year) {
        std::cout << std::setw(10) << year << std::setw(20) << std::fixed << std::setprecision(2) << currentFee << std::endl;
        currentFee += currentFee * increaseRate; // Calculate the new fee for the next year
    }

    return 0;
}
