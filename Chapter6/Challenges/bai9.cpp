#include <iostream>
#include <cmath> // For the pow function

// Function to calculate the present value
double presentValue(double futureValue, double annualInterestRate, int numberOfYears) {
    // Validate input: Ensure the interest rate is a valid percentage
    if (annualInterestRate < 0 || annualInterestRate > 100) {
        std::cerr << "Error: Annual interest rate must be between 0 and 100.\n";
        return -1.0; // Return an invalid value
    }

    // Calculate present value using the present value formula
    double r = annualInterestRate / 100.0;
    return futureValue / pow((1 + r), numberOfYears);
}

int main() {
    double futureValue, annualInterestRate;
    int numberOfYears;

    // Get input from the user
    std::cout << "Enter the future value you want in the account: $";
    std::cin >> futureValue;

    std::cout << "Enter the annual interest rate (as a percentage): ";
    std::cin >> annualInterestRate;

    std::cout << "Enter the number of years: ";
    std::cin >> numberOfYears;

    // Call the presentValue function and display the result
    double presentVal = presentValue(futureValue, annualInterestRate, numberOfYears);

    if (presentVal != -1.0) {
        std::cout << "You need to deposit $" << presentVal << " today to achieve a future value of $" << futureValue << " in " << numberOfYears << " years.\n";
    }

    return 0;
}
