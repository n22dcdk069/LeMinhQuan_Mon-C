#include <iostream>
#include <cmath> // For the pow function

// Function to calculate the distance an object has fallen
double fallingDistance(int time) {
    const double g = 9.8; // Acceleration due to gravity in m/s^2
    return 0.5 * g * pow(time, 2);
}

int main() {
    std::cout << "Time (s)\tDistance (m)\n";
    
    // Loop to demonstrate the fallingDistance function
    for (int time = 1; time <= 10; ++time) {
        double distance = fallingDistance(time);
        std::cout << time << "\t\t" << distance << "\n";
    }

    return 0;
}
