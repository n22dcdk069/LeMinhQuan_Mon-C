#include <iostream>
#include <iomanip>

const int NUM_MONTHS = 12;

// Structure to store weather data for a month
struct WeatherData {
    double totalRainfall;
    double highTemperature;
    double lowTemperature;
    double averageTemperature;
};

// Function to input weather data for a specific month
void inputWeatherData(WeatherData& monthData) {
    do {
        std::cout << "Enter total rainfall for the month: ";
        std::cin >> monthData.totalRainfall;
        if (monthData.totalRainfall < 0) {
            std::cout << "Please enter a non-negative value for total rainfall.\n";
        }
    } while (monthData.totalRainfall < 0);

    do {
        std::cout << "Enter high temperature for the month: ";
        std::cin >> monthData.highTemperature;
        if (monthData.highTemperature < -100 || monthData.highTemperature > 140) {
            std::cout << "Please enter a temperature between -100 and 140 degrees Fahrenheit.\n";
        }
    } while (monthData.highTemperature < -100 || monthData.highTemperature > 140);

    do {
        std::cout << "Enter low temperature for the month: ";
        std::cin >> monthData.lowTemperature;
        if (monthData.lowTemperature < -100 || monthData.lowTemperature > 140) {
            std::cout << "Please enter a temperature between -100 and 140 degrees Fahrenheit.\n";
        }
    } while (monthData.lowTemperature < -100 || monthData.lowTemperature > 140);

    // Calculate average temperature
    monthData.averageTemperature = (monthData.highTemperature + monthData.lowTemperature) / 2;
}

int main() {
    WeatherData yearData[NUM_MONTHS];

    // Input weather data for each month
    for (int i = 0; i < NUM_MONTHS; ++i) {
        std::cout << "\nEnter weather data for Month " << i + 1 << ":\n";
        inputWeatherData(yearData[i]);
    }

    // Calculate and display results
    double totalYearlyRainfall = 0;
    double highestTemperature = yearData[0].highTemperature;
    double lowestTemperature = yearData[0].lowTemperature;
    int highestTempMonth = 1;
    int lowestTempMonth = 1;
    double totalAverageTemperature = 0;

    for (int i = 0; i < NUM_MONTHS; ++i) {
        totalYearlyRainfall += yearData[i].totalRainfall;
        totalAverageTemperature += yearData[i].averageTemperature;

        // Check for highest temperature
        if (yearData[i].highTemperature > highestTemperature) {
            highestTemperature = yearData[i].highTemperature;
            highestTempMonth = i + 1;
        }

        // Check for lowest temperature
        if (yearData[i].lowTemperature < lowestTemperature) {
            lowestTemperature = yearData[i].lowTemperature;
            lowestTempMonth = i + 1;
        }
    }

    // Display results
    std::cout << "\nAverage Monthly Rainfall: " << totalYearlyRainfall / NUM_MONTHS << " inches\n";
    std::cout << "Total Yearly Rainfall: " << totalYearlyRainfall << " inches\n";
    std::cout << "Highest Temperature: " << highestTemperature << " degrees Fahrenheit (Month " << highestTempMonth << ")\n";
    std::cout << "Lowest Temperature: " << lowestTemperature << " degrees Fahrenheit (Month " << lowestTempMonth << ")\n";
    std::cout << "Average of Monthly Average Temperatures: " << totalAverageTemperature / NUM_MONTHS << " degrees Fahrenheit\n";

    return 0;
}