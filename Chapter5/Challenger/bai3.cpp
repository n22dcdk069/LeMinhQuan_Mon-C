#include <iostream>
#include <iomanip>

int main() {
    const double riseRate = 1.5; // Ocean rise rate in millimeters per year
    const int numYears = 25;     // Number of years to display

    // Display the table header
    std::cout << std::setw(10) << "Year" << std::setw(20) << "Rise (mm)" << std::endl;
    std::cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << std::endl;

    // Display the table content
    for (int year = 1; year <= numYears; ++year) {
        double totalRise = riseRate * year;
        std::cout << std::setw(10) << year << std::setw(20) << std::fixed << std::setprecision(2) << totalRise << std::endl;
    }

    return 0;
}
