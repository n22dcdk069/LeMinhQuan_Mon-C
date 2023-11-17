#include <iostream>
#include <iomanip>
#include <cmath> // For pow()

int main() {
    // Variables
    double loanAmount, annualInterestRate;
    int numberOfPayments;

    // Get user input for loan details
    std::cout << "Enter the loan amount: $";
    std::cin >> loanAmount;

    std::cout << "Enter the annual interest rate (as a percentage): ";
    std::cin >> annualInterestRate;

    std::cout << "Enter the number of payments: ";
    std::cin >> numberOfPayments;

    // Convert annual interest rate to monthly rate
    double monthlyInterestRate = (annualInterestRate / 100.0) / 12.0;

    // Calculate the monthly payment using the provided formula
    double numerator = monthlyInterestRate * pow(1 + monthlyInterestRate, numberOfPayments);
    double denominator = pow(1 + monthlyInterestRate, numberOfPayments) - 1;
    double monthlyPayment = (numerator / denominator) * loanAmount;

    // Calculate amount paid back and interest paid
    double amountPaidBack = monthlyPayment * numberOfPayments;
    double interestPaid = amountPaidBack - loanAmount;

    // Display the report
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nLoan Amount: $" << loanAmount << "\n";
    std::cout << "Monthly Interest Rate: " << monthlyInterestRate * 100 << "%\n";
    std::cout << "Number of Payments: " << numberOfPayments << "\n";
    std::cout << "Monthly Payment: $" << monthlyPayment << "\n";
    std::cout << "Amount Paid Back: $" << amountPaidBack << "\n";
    std::cout << "Interest Paid: $" << interestPaid << "\n";

    return 0;
}
