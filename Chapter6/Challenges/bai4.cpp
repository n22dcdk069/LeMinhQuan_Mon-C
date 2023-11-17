#include <iostream>
#include <limits> // For numeric_limits

// Function prototypes
int getNumAccidents(const std::string& region);
void findLowest(int north, int south, int east, int west, int central);

int main() {
    // Get the number of accidents for each region
    int accidentsNorth = getNumAccidents("North");
    int accidentsSouth = getNumAccidents("South");
    int accidentsEast = getNumAccidents("East");
    int accidentsWest = getNumAccidents("West");
    int accidentsCentral = getNumAccidents("Central");

    // Find the region with the fewest accidents
    findLowest(accidentsNorth, accidentsSouth, accidentsEast, accidentsWest, accidentsCentral);

    return 0;
}

// Function to get the number of accidents for a given region
int getNumAccidents(const std::string& region) {
    int accidents;

    do {
        std::cout << "Enter the number of automobile accidents reported in " << region << " region: ";
        std::cin >> accidents;

        if (accidents < 0) {
            std::cout << "Please enter a non-negative number.\n";
            // Clear the input buffer to handle invalid input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (accidents < 0);

    return accidents;
}

// Function to find the region with the fewest accidents and display the result
void findLowest(int north, int south, int east, int west, int central) {
    std::string region;
    int lowestAccidents = north;

    if (south < lowestAccidents) {
        lowestAccidents = south;
        region = "South";
    }
    if (east < lowestAccidents) {
        lowestAccidents = east;
        region = "East";
    }
    if (west < lowestAccidents) {
        lowestAccidents = west;
        region = "West";
    }
    if (central < lowestAccidents) {
        region = "Central";
    }

    std::cout << "The region with the fewest reported automobile accidents is " << region
              << " with " << lowestAccidents << " accidents.\n";
}