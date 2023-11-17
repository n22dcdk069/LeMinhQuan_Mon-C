#include <iostream>

int main() {
    // Get user input for seconds
    int seconds;
    
    std::cout << "Enter the number of seconds: ";
    std::cin >> seconds;

    // Convert seconds to minutes, hours, and days
    int minutes = seconds / 60;
    int hours = seconds / 3600;
    int days = seconds / 86400;

    // Display the results
    if (seconds >= 60) {
        std::cout << "Minutes: " << minutes << std::endl;
    }

    if (seconds >= 3600) {
        std::cout << "Hours: " << hours << std::endl;
    }

    if (seconds >= 86400) {
        std::cout << "Days: " << days << std::endl;
    }

    return 0;
}
