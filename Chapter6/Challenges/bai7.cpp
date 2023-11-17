#include <iostream>
#include <iomanip>

// Function to convert Fahrenheit to Celsius
double celsius(double fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}

int main() {
    std::cout << "Fahrenheit\tCelsius\n";

    // Loop to demonstrate the celsius function
    for (int fahrenheit = 0; fahrenheit <= 20; ++fahrenheit) {
        double celsiusValue = celsius(static_cast<double>(fahrenheit));
        std::cout << std::fixed << std::setprecision(2);
        std::cout << fahrenheit << "\t\t" << celsiusValue << "\n";
    }

    return 0;
}