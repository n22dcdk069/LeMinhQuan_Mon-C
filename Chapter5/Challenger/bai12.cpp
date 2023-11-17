#include <iostream>
#include <iomanip>

int main() {
    // Display table header
    std::cout << "Celsius   Fahrenheit\n";
    std::cout << "---------------------\n";

    // Loop through Celsius temperatures 0-20
    for (int celsius = 0; celsius <= 20; ++celsius) {
        // Convert Celsius to Fahrenheit
        double fahrenheit = (celsius * 9.0 / 5.0) + 32;

        // Display the table row
        std::cout << std::setw(5) << celsius << "      " << std::setw(9) << std::fixed << std::setprecision(2) << fahrenheit << "\n";
    }

    return 0;
}
