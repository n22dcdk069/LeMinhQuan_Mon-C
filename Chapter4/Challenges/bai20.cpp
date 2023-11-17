#include <iostream>
#include <iomanip>

int main() {
    // Constants for speed of sound in feet per second
    const double SPEED_AIR = 1100.0;
    const double SPEED_WATER = 4900.0;
    const double SPEED_STEEL = 16400.0;

    // Variables to store user input
    char medium;
    double distance, time;

    // Display the menu
    std::cout << "Select a medium for sound:\n";
    std::cout << "A - Air\n";
    std::cout << "W - Water\n";
    std::cout << "S - Steel\n";
    std::cout << "Enter your choice (A, W, or S): ";
    std::cin >> medium;

    // Validate the user's choice
    if (medium != 'A' && medium != 'a' && medium != 'W' && medium != 'w' && medium != 'S' && medium != 's') {
        std::cout << "Error: Invalid choice. Please select A, W, or S.\n";
        return 1; // Exit the program with an error code
    }

    // Get input for the distance
    std::cout << "Enter the distance in feet: ";
    std::cin >> distance;

    // Validate the input for distance
    if (distance < 0) {
        std::cout << "Error: Distance cannot be less than 0.\n";
        return 1; // Exit the program with an error code
    }

    // Calculate the time it will take for the sound wave to travel
    switch (toupper(medium)) {
        case 'A':
            time = distance / SPEED_AIR;
            break;
        case 'W':
            time = distance / SPEED_WATER;
            break;
        case 'S':
            time = distance / SPEED_STEEL;
            break;
    }

    // Display the result with four decimal places
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "The time it will take for the sound wave to travel is: " << time << " seconds\n";

    return 0;
}
