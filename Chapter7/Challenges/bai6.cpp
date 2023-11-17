#include <iostream>
#include <fstream>

const int MONTHS = 3;
const int DAYS_PER_MONTH = 30;

void readWeatherData(char weatherData[][DAYS_PER_MONTH], const std::string& fileName) {
    std::ifstream inputFile(fileName);

    if (!inputFile) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        exit(1);
    }

    for (int i = 0; i < MONTHS; ++i) {
        for (int j = 0; j < DAYS_PER_MONTH; ++j) {
            inputFile >> weatherData[i][j];
        }
    }

    inputFile.close();
}

void generateWeatherReport(const char weatherData[][DAYS_PER_MONTH]) {
    int rainyCount, cloudyCount, sunnyCount;
    int maxRainyDays = 0;
    int maxRainyMonth = 0;

    // Display header
    std::cout << "Weather Report\n";

    // Display monthly and overall counts
    for (int i = 0; i < MONTHS; ++i) {
        rainyCount = cloudyCount = sunnyCount = 0;

        for (int j = 0; j < DAYS_PER_MONTH; ++j) {
            switch (weatherData[i][j]) {
                case 'R':
                    ++rainyCount;
                    break;
                case 'C':
                    ++cloudyCount;
                    break;
                case 'S':
                    ++sunnyCount;
                    break;
            }
        }

        std::cout << "Month " << i + 1 << " - Rainy: " << rainyCount
                  << ", Cloudy: " << cloudyCount << ", Sunny: " << sunnyCount << "\n";

        if (rainyCount > maxRainyDays) {
            maxRainyDays = rainyCount;
            maxRainyMonth = i;
        }
    }

    // Display the overall report
    std::cout << "\nOverall Report\n";
    std::cout << "Total Rainy Days: " << maxRainyDays << " (Month " << maxRainyMonth + 1 << ")\n";
}

int main() {
    char weatherData[MONTHS][DAYS_PER_MONTH];
    const std::string fileName = "RainOrShine.txt";

    // Read weather data from file
    readWeatherData(weatherData, fileName);

    // Generate and display weather report
    generateWeatherReport(weatherData);

    return 0;
}
