#include <iostream>
#include <iomanip>

const int NUM_MONTHS = 12;

int main() {
    double rainfall[NUM_MONTHS];
    double totalRainfall = 0.0;
    double averageRainfall;
    double highestRainfall = 0.0;
    double lowestRainfall = 0.0;
    int highestMonth = 0;
    int lowestMonth = 0;

    // Input: Get rainfall data for each month
    for (int i = 0; i < NUM_MONTHS; ++i) {
        do {
            std::cout << "Enter rainfall for month " << i + 1 << ": ";
            std::cin >> rainfall[i];

            // Input validation
            if (rainfall[i] < 0.0) {
                std::cout << "Please enter a non-negative value for rainfall." << std::endl;
            }
        } while (rainfall[i] < 0.0);

        // Update total rainfall
        totalRainfall += rainfall[i];

        // Update highest and lowest rainfall
        if (i == 0 || rainfall[i] > highestRainfall) {
            highestRainfall = rainfall[i];
            highestMonth = i;
        }
        if (i == 0 || rainfall[i] < lowestRainfall) {
            lowestRainfall = rainfall[i];
            lowestMonth = i;
        }
    }

    // Calculate average rainfall
    averageRainfall = totalRainfall / NUM_MONTHS;

    // Output results
    std::cout << "\nTotal rainfall for the year: " << totalRainfall << " inches" << std::endl;
    std::cout << "Average monthly rainfall: " << averageRainfall << " inches" << std::endl;
    std::cout << "Month with the highest rainfall: " << highestMonth + 1 << " ("
              << highestRainfall << " inches)" << std::endl;
    std::cout << "Month with the lowest rainfall: " << lowestMonth + 1 << " ("
              << lowestRainfall << " inches)" << std::endl;

    return 0;
}
