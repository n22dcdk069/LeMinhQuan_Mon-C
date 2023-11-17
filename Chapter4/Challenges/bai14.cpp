#include <iostream>
#include <iomanip>

int main() {
    // Constants for fees and balance threshold
    const double MONTHLY_FEE = 10.0;
    const double LOW_BALANCE_FEE = 15.0;
    const double CHECK_FEE_1 = 0.10;
    const double CHECK_FEE_2 = 0.08;
    const double CHECK_FEE_3 = 0.06;
    const double CHECK_FEE_4 = 0.04;
    const int LOW_BALANCE_THRESHOLD = 400;

    // Variables to store user input
    double balance;
    int numChecks;

    // Get input for the beginning balance
    std::cout << "Enter the beginning balance: $";
    std::cin >> balance;

    // Validate the input for the beginning balance
    if (balance < 0) {
        std::cout << "URGENT: Account is overdrawn! Please deposit funds immediately.\n";
        return 1; // Exit the program with an error code
    }

    // Get input for the number of checks written
    std::cout << "Enter the number of checks written: ";
    std::cin >> numChecks;

    // Validate the input for the number of checks
    if (numChecks < 0) {
        std::cout << "Error: Number of checks cannot be negative.\n";
        return 1; // Exit the program with an error code
    }

    // Calculate check fees based on the number of checks
    double checkFees;
    if (numChecks < 20) {
        checkFees = numChecks * CHECK_FEE_1;
    } else if (numChecks >= 20 && numChecks < 40) {
        checkFees = numChecks * CHECK_FEE_2;
    } else if (numChecks >= 40 && numChecks < 60) {
        checkFees = numChecks * CHECK_FEE_3;
    } else {
        checkFees = numChecks * CHECK_FEE_4;
    }

    // Apply low balance fee if applicable
    if (balance < LOW_BALANCE_THRESHOLD) {
        checkFees += LOW_BALANCE_FEE;
    }

    // Add the monthly fee
    checkFees += MONTHLY_FEE;

    // Display the result with two decimal places
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total service fees for the month: $" << checkFees << std::endl;

    return 0;
}
