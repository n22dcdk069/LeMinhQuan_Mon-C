#include <iostream>
#include <iomanip>

int main() {
    // Constants for rate per minute during different time intervals
    const double RATE_OFF_PEAK = 0.05;
    const double RATE_DAYTIME = 0.45;
    const double RATE_EVENING = 0.20;

    // Variables to store user input
    double startTime, minutes, fractionalPart;

    // Get input for the starting time and number of minutes
    std::cout << "Enter the starting time of the call in HH.MM format: ";
    std::cin >> startTime;

    // Validate the input for the starting time
    if (startTime < 0 || startTime >= 24 || static_cast<int>(startTime * 100) % 100 >= 60) {
        std::cout << "Error: Invalid starting time.\n";
        return 1; // Exit the program with an error code
    }

    std::cout << "Enter the number of minutes for the call: ";
    std::cin >> minutes;

    // Validate the input for the number of minutes
    if (minutes < 0) {
        std::cout << "Error: Number of minutes cannot be less than 0.\n";
        return 1; // Exit the program with an error code
    }

    // Calculate the fractional part of the starting time
    fractionalPart = startTime - static_cast<int>(startTime);

    // Determine the time interval and calculate the charges
    double rate, charges;
    if (startTime >= 0.00 && startTime < 7.00) {
        rate = RATE_OFF_PEAK;
    } else if (startTime >= 7.00 && startTime <= 19.00) {
        rate = RATE_DAYTIME;
    } else {
        rate = RATE_EVENING;
    }

    // Calculate charges
    charges = minutes * rate;

    // Display the result with two decimal places
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Charges for the call: $" << charges << std::endl;

    return 0;
}
