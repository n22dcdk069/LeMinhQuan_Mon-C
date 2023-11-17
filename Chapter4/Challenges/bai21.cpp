#include <iostream>

int main() {
    // Speeds of sound in different gases (in meters per second)
    const double SPEED_CO2 = 258.0;
    const double SPEED_AIR = 331.5;
    const double SPEED_HELIUM = 972.0;
    const double SPEED_HYDROGEN = 1270.0;

    // Menu
    std::cout << "Select a gas from the menu:\n";
    std::cout << "1. Carbon Dioxide\n";
    std::cout << "2. Air\n";
    std::cout << "3. Helium\n";
    std::cout << "4. Hydrogen\n";

    // User selection
    int choice;
    std::cout << "Enter your choice (1-4): ";
    std::cin >> choice;

    // Input validation for the menu choice
    if (choice < 1 || choice > 4) {
        std::cout << "Invalid choice. Please select a number from 1 to 4." << std::endl;
        return 1; // Exit the program with an error code
    }

    // User input for the time in seconds
    double time;
    std::cout << "Enter the time it took for the sound to travel (in seconds, 0-30): ";
    std::cin >> time;

    // Input validation for time
    if (time < 0 || time > 30) {
        std::cout << "Invalid time. Please enter a time between 0 and 30 seconds." << std::endl;
        return 1; // Exit the program with an error code
    }

    // Calculate distance based on the speed of sound in the selected gas
    double distance;

    switch (choice) {
        case 1:
            distance = SPEED_CO2 * time;
            break;
        case 2:
            distance = SPEED_AIR * time;
            break;
        case 3:
            distance = SPEED_HELIUM * time;
            break;
        case 4:
            distance = SPEED_HYDROGEN * time;
            break;
        default:
            std::cout << "Unexpected case!" << std::endl;
            return 1; // Exit the program with an error code
    }

    // Display the calculated distance
    std::cout << "The source of the sound was approximately " << distance << " meters away." << std::endl;

    return 0;
}
