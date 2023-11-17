#include <iostream>

int main() {
    const double calories_per_minute = 3.6;

    // Loop through the specified time intervals
    for (int minutes = 5; minutes <= 30; minutes += 5) {
        // Calculate calories burned for the current time interval
        double calories_burned = calories_per_minute * minutes;

        // Display the result
        std::cout << "After " << minutes << " minutes, you burned " << calories_burned << " calories." << std::endl;
    }

    return 0;
}
