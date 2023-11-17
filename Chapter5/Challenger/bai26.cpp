#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    // Create and open the output file stream
    std::ofstream outputFile("SavingsAccountReport.txt");

    // Check if the file is successfully opened
    if (!outputFile) {
        std::cerr << "Error opening the file for writing.\n";
        return 1; // Exit with an error code
    }

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

    // Write header to the file
    outputFile << "Savings Account Report\n";
    outputFile << std::setw(15) << "Month" << std::setw(20) << "Balance" << std::setw(20) << "Total Deposits"
               << std::setw(20) << "Total Withdrawals" << std::setw(20) << "Total Interest Earned\n";

    // Loop through each month
    for (int month = 1; month <= numMonths; ++month) {
        // Get user inputs for the month
        std::cout << "Enter the amount deposited for Month " << month << ": ";
        std::cin >> monthlyDeposit;

        std::cout << "Enter the amount withdrawn for Month " << month << ": ";
        std::cin >> monthlyWithdrawal;

        // Update balance, totals, and calculate interest
        balance += monthlyDeposit - monthlyWithdrawal;
        totalDeposits += monthlyDeposit;
        totalWithdrawals += monthlyWithdrawal;
        double monthlyInterest = balance * monthlyInterestRate;
        balance += monthlyInterest;
        totalInterest += monthlyInterest;

        // Write data to the file
        outputFile << std::setw(15) << month << std::setw(20) << balance << std::setw(20) << totalDeposits
                   << std::setw(20) << totalWithdrawals << std::setw(20) << totalInterest << "\n";
    }

    // Close the file
    outputFile.close();

    std::cout << "Report written to SavingsAccountReport.txt.\n";

    return 0;
}
