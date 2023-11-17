#include <iostream>

int main() {
    // Variables to store speed and time
    double speed, time;

    // Get speed input with validation
    do {
        std::cout << "What is the speed of the vehicle in mph? ";
        std::cin >> speed;

        if (speed < 0) {
            std::cout << "Please enter a non-negative speed." << std::endl;
        }
    } while (speed < 0);

    // Get time input with validation
    do {
        std::cout << "How many hours has it traveled? ";
        std::cin >> time;

        if (time < 1) {
            std::cout << "Please enter a time greater than or equal to 1." << std::endl;
        }
    } while (time < 1);

    // Display header
    std::cout << "\nHour   Distance Traveled" << std::endl;
    std::cout << "------------------------" << std::endl;

    // Calculate and display distance for each hour
    for (int hour = 1; hour <= time; ++hour) {
        double distance = speed * hour;
        std::cout << hour << "      " << distance << std::endl;
    }

    return 0;
}
