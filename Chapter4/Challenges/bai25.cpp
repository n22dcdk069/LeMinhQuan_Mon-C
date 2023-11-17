#include <iostream>

int main() {
    const double PACKAGE_A_BASE_COST = 39.99;
    const double PACKAGE_B_BASE_COST = 59.99;
    const double PACKAGE_C_BASE_COST = 69.99;

    const int PACKAGE_A_INCLUDED_MINUTES = 450;
    const int PACKAGE_B_INCLUDED_MINUTES = 900;

    const double ADDITIONAL_RATE_A = 0.45;
    const double ADDITIONAL_RATE_B = 0.40;

    char packageChoice;
    int minutesUsed;
    double totalAmountDue;

    // Display the menu
    std::cout << "Select a subscription package (A, B, or C): ";
    std::cin >> packageChoice;

    // Input validation
    if (packageChoice != 'A' && packageChoice != 'B' && packageChoice != 'C') {
        std::cout << "Invalid choice. Please select package A, B, or C." << std::endl;
        return 1; // Exit the program with an error code
    }

    // Get the number of minutes used
    std::cout << "Enter the number of minutes used: ";
    std::cin >> minutesUsed;

    // Input validation for negative minutes
    if (minutesUsed < 0) {
        std::cout << "Invalid input. Minutes used cannot be negative." << std::endl;
        return 1; // Exit the program with an error code
    }

    // Calculate the total amount due based on the selected package
    switch (packageChoice) {
        case 'A':
            totalAmountDue = PACKAGE_A_BASE_COST;
            if (minutesUsed > PACKAGE_A_INCLUDED_MINUTES) {
                totalAmountDue += (minutesUsed - PACKAGE_A_INCLUDED_MINUTES) * ADDITIONAL_RATE_A;
            }
            break;
        case 'B':
            totalAmountDue = PACKAGE_B_BASE_COST;
            if (minutesUsed > PACKAGE_B_INCLUDED_MINUTES) {
                totalAmountDue += (minutesUsed - PACKAGE_B_INCLUDED_MINUTES) * ADDITIONAL_RATE_B;
            }
            break;
        case 'C':
            totalAmountDue = PACKAGE_C_BASE_COST;
            break;
        default:
            std::cout << "Unexpected case!" << std::endl;
            return 1; // Exit the program with an error code
    }

    // Display the total amount due
    std::cout << "Total amount due: $" << totalAmountDue << std::endl;

    return 0;
}
