#include <iostream>
#include <cmath>

class MortgageCalculator {
private:
    double loanAmount;
    double annualInterestRate;
    int years;

public:
    // Constructor
    MortgageCalculator() : loanAmount(0.0), annualInterestRate(0.0), years(0) {}

    // Mutator functions
    void setLoanAmount(double amount) {
        if (amount < 0) {
            std::cerr << "Invalid input. Loan amount cannot be negative.\n";
            exit(1); // Exit program with an error code
        }
        loanAmount = amount;
    }

    void setAnnualInterestRate(double rate) {
        if (rate < 0) {
            std::cerr << "Invalid input. Annual interest rate cannot be negative.\n";
            exit(1); // Exit program with an error code
        }
        annualInterestRate = rate;
    }

    void setYears(int numYears) {
        if (numYears < 0) {
            std::cerr << "Invalid input. Number of years cannot be negative.\n";
            exit(1); // Exit program with an error code
        }
        years = numYears;
    }

    // Member function to calculate the monthly payment
    double calculateMonthlyPayment() const {
        double monthlyRate = annualInterestRate / 12.0 / 100.0;
        double term = std::pow(1 + monthlyRate, 12 * years);
        return (loanAmount * monthlyRate * term) / (term - 1);
    }

    // Member function to calculate the total amount paid
    double calculateTotalAmountPaid() const {
        return calculateMonthlyPayment() * 12 * years;
    }
};

int main() {
    MortgageCalculator mortgage;

    // Get user input for loan details
    double loanAmount, annualInterestRate;
    int years;

    std::cout << "Enter loan amount: $";
    std::cin >> loanAmount;
    mortgage.setLoanAmount(loanAmount);

    std::cout << "Enter annual interest rate (%): ";
    std::cin >> annualInterestRate;
    mortgage.setAnnualInterestRate(annualInterestRate);

    std::cout << "Enter number of years: ";
    std::cin >> years;
    mortgage.setYears(years);

    // Display monthly payment and total amount paid
    std::cout << "\nMonthly Payment: $" << mortgage.calculateMonthlyPayment() << std::endl;
    std::cout << "Total Amount Paid: $" << mortgage.calculateTotalAmountPaid() << std::endl;

    return 0;
}
