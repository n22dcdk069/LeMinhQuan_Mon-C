#include <iostream>

int main() {
    // Variables
    int numYears;
    double totalRainfall = 0;
    const int numMonths = 12;

    // Get the number of years with validation
    do {
        std::cout << "Enter the number of years: ";
        std::cin >> numYears;

        if (numYears < 1) {
            std::cout << "Please enter a number of years greater than 0.\n";
        }
    } while (numYears < 1);

    // Outer loop for each year
    for (int year = 1; year <= numYears; ++year) {
        // Inner loop for each month
        for (int month = 1; month <= numMonths; ++month) {
            double monthlyRainfall;

            // Get monthly rainfall with validation
            do {
                std::cout << "Enter inches of rainfall for Year " << year << ", Month " << month << ": ";
                std::cin >> monthlyRainfall;

                if (monthlyRainfall < 0) {
                    std::cout << "Please enter a non-negative value for rainfall.\n";
                }
            } while (monthlyRainfall < 0);

            // Accumulate total rainfall
            totalRainfall += monthlyRainfall;
        }
    }

    // Calculate average rainfall per month
    double averageRainfall = totalRainfall / (numYears * numMonths);

    // Display results
    std::cout << "\nOver a period of " << numYears << " years:\n";
    std::cout << "Number of months: " << numYears * numMonths << std::endl;
    std::cout << "Total inches of rainfall: " << totalRainfall << std::endl;
    std::cout << "Average rainfall per month: " << averageRainfall << " inches\n";

    return 0;
}
