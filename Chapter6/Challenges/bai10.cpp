#include <iostream>
#include <cmath> // For pow()

// Function prototype
double futureValue(double presentValue, double monthlyInterestRate, int months);

int main() {
    // Get user input
    double presentValue, monthlyInterestRate;
    int months;

    std::cout << "Enter the present value of the account: $";
    std::cin >> presentValue;

    std::cout << "Enter the monthly interest rate (in decimal form): ";
    std::cin >> monthlyInterestRate;

    std::cout << "Enter the number of months: ";
    std::cin >> months;

    // Calculate future value using the function
    double result = futureValue(presentValue, monthlyInterestRate, months);

    // Display the future value
    std::cout << "The future value of the account after " << months << " months is: $" << result << std::endl;

    return 0;
}

// Function to calculate the future value
double futureValue(double presentValue, double monthlyInterestRate, int months) {
    // Formula: F = P * (1 + i)^t
    return presentValue * std::pow(1 + monthlyInterestRate, months);
}
