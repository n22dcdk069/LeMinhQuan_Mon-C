#include <iostream>
#include <limits> // For numeric_limits

int main() {
    const double PACKAGE_A_BASE_COST = 39.99;
    const double PACKAGE_B_BASE_COST = 59.99;
    const double PACKAGE_C_BASE_COST = 69.99;

    const int PACKAGE_A_INCLUDED_MINUTES = 450;
    const int PACKAGE_B_INCLUDED_MINUTES = 900;

    const double ADDITIONAL_RATE_A = 0.45;
    const double ADDITIONAL_RATE_B = 0.40;

    const int DAYS_IN_MONTH[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const int HOURS_IN_MONTH[] = {744, 672, 744, 720, 744, 720, 744, 744, 720, 744, 720, 744};

    char packageChoice;
    int month, minutesUsed;
    double totalAmountDue;

    // Display the menu
    std::cout << "Select a subscription package (A, B, or C): ";
    std::cin >> packageChoice;

    // Input validation for the package choice
    if (packageChoice != 'A' && packageChoice != 'B' && packageChoice != 'C') {
        std::cout << "Invalid choice. Please select package A, B, or C." << std::endl;
        return 1; // Exit the program with an error code
    }

    // Get the month
    std::cout << "Enter the month (1 for January, 2 for February, ..., 12 for December): ";
    std::cin >> month;

    // Input validation for the month
    if (month < 1 || month > 12) {
        std::cout << "Invalid month. Please enter a number between 1 and 12." << std::endl;
        return 1; // Exit the program with an error code
    }

    // Get the number of minutes used
    std::cout << "Enter the number of minutes used: ";
    std::cin >> minutesUsed;

    // Input validation for the number of minutes
    if (minutesUsed < 0 || minutesUsed > HOURS_IN_MONTH[month - 1] * 60) {
        std::cout << "Invalid number of minutes. Please enter a non-negative value "
                  << "not exceeding the maximum for the selected month." << std::endl;
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
