#include <iostream>
#include <iomanip>

int main() {
    // Constants for package rates
    const double PACKAGE_A_RATE = 39.99;
    const double PACKAGE_B_RATE = 59.99;
    const double PACKAGE_C_RATE = 69.99;

    // Constants for additional hours included in each package
    const int PACKAGE_A_HOURS = 10;
    const int PACKAGE_B_HOURS = 20;

    // Variables to store user input
    char package;
    int hours;

    // Get input for the selected package and number of hours
    std::cout << "Enter the package (A, B, or C): ";
    std::cin >> package;

    // Validate the input for the package
    if (package != 'A' && package != 'a' && package != 'B' && package != 'b' && package != 'C' && package != 'c') {
        std::cout << "Error: Invalid package selection. Please enter A, B, or C.\n";
        return 1; // Exit the program with an error code
    }

    std::cout << "Enter the number of hours used: ";
    std::cin >> hours;

    // Validate the input for the number of hours
    if (hours < 0) {
        std::cout << "Error: Number of hours cannot be less than 0.\n";
        return 1; // Exit the program with an error code
    }

    // Calculate charges for the selected package
    double charges;
    switch (toupper(package)) {
        case 'A':
            charges = PACKAGE_A_RATE;
            if (hours > PACKAGE_A_HOURS) {
                charges += (hours - PACKAGE_A_HOURS) * 2.0;
            }
            break;
        case 'B':
            charges = PACKAGE_B_RATE;
            if (hours > PACKAGE_B_HOURS) {
                charges += (hours - PACKAGE_B_HOURS) * 1.0;
            }
            break;
        case 'C':
            charges = PACKAGE_C_RATE;
            break;
    }

    // Display the charges for the selected package
    std::cout << "Charges for the selected package: $" << charges << std::endl;

    // Calculate and display potential savings for Package A customers
    if (toupper(package) == 'A') {
        double savingsB = charges - PACKAGE_B_RATE;
        double savingsC = charges - PACKAGE_C_RATE;

        if (savingsB > 0) {
            std::cout << "Savings if Package A customers switch to Package B: $" << savingsB << std::endl;
        }

        if (savingsC > 0) {
            std::cout << "Savings if Package A customers switch to Package C: $" << savingsC << std::endl;
        }
    }

    // Calculate and display potential savings for Package B customers
    if (toupper(package) == 'B') {
        double savingsC = charges - PACKAGE_C_RATE;

        if (savingsC > 0) {
            std::cout << "Savings if Package B customers switch to Package C: $" << savingsC << std::endl;
        }
    }

    return 0;
}
