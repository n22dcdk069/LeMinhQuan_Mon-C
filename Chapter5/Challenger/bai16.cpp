#include <iostream>
#include <iomanip>

int main() {
    // Variables
    double annualInterestRate, startingBalance, balance, monthlyDeposit, monthlyWithdrawal;
    int numMonths;

    // Get user inputs
    std::cout << "Enter the annual interest rate (in percentage): ";
    std::cin >> annualInterestRate;

    std::cout << "Enter the starting balance: ";
    std::cin >> startingBalance;

    std::cout << "Enter the number of months since the account was established: ";
    std::cin >> numMonths;

    // Convert annual interest rate to monthly interest rate
    double monthlyInterestRate = annualInterestRate / 100 / 12;

    // Initialize variables
    double totalDeposits = 0, totalWithdrawals = 0, totalInterest = 0;

    // Loop through each month
    for (int month = 1; month <= numMonths; ++month) {
        // Ask for the amount deposited
        do {
            std::cout << "Enter the amount deposited for Month " << month << " (do not accept negative numbers): ";
            std::cin >> monthlyDeposit;

            if (monthlyDeposit < 0) {
                std::cout << "Please enter a non-negative amount.\n";
            }
        } while (monthlyDeposit < 0);

        // Ask for the amount withdrawn
        do {
            std::cout << "Enter the amount withdrawn for Month " << month << " (do not accept negative numbers): ";
            std::cin >> monthlyWithdrawal;

            if (monthlyWithdrawal < 0) {
                std::cout << "Please enter a non-negative amount.\n";
            }
        } while (monthlyWithdrawal < 0);

        // Update balance, total deposits, and total withdrawals
        balance += monthlyDeposit - monthlyWithdrawal;
        totalDeposits += monthlyDeposit;
        totalWithdrawals += monthlyWithdrawal;

        // Calculate monthly interest
        double monthlyInterest = balance * monthlyInterestRate;
        balance += monthlyInterest;
        totalInterest += monthlyInterest;
    }

    // Display results
    std::cout << "\nEnding Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
    std::cout << "Total Deposits: $" << totalDeposits << std::endl;
    std::cout << "Total Withdrawals: $" << totalWithdrawals << std::endl;
    std::cout << "Total Interest Earned: $" << totalInterest << std::endl;

    return 0;
}
