#include <iostream>
#include <string>

int main() {
    // Constants for substance information
    const std::string SUBSTANCES[] = { "Ethyl alcohol", "Mercury", "Oxygen", "Water" };
    const int FREEZING_POINTS[] = { -173, -38, -362, 32 };
    const int BOILING_POINTS[] = { 172, 676, -306, 212 };

    // Variable to store user input
    int temperature;

    // Get input for the temperature
    std::cout << "Enter a temperature in Fahrenheit: ";
    std::cin >> temperature;

    // Display substances that will freeze at the given temperature
    std::cout << "Substances that will freeze at " << temperature << "°F:\n";
    for (int i = 0; i < sizeof(SUBSTANCES) / sizeof(SUBSTANCES[0]); ++i) {
        if (temperature <= FREEZING_POINTS[i]) {
            std::cout << SUBSTANCES[i] << std::endl;
        }
    }

    // Display substances that will boil at the given temperature
    std::cout << "Substances that will boil at " << temperature << "°F:\n";
    for (int i = 0; i < sizeof(SUBSTANCES) / sizeof(SUBSTANCES[0]); ++i) {
        if (temperature >= BOILING_POINTS[i]) {
            std::cout << SUBSTANCES[i] << std::endl;
        }
    }

    return 0;
}
