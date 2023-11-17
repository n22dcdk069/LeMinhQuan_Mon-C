#include <iostream>
#include <iomanip>

int main() {
    int employeeNumber;
    double grossPay, stateTax, federalTax, ficaWithholdings;
    
    double totalGrossPay = 0.0, totalStateTax = 0.0, totalFederalTax = 0.0, totalFICA = 0.0, totalNetPay = 0.0;

    // Input loop
    do {
        // Get employee information
        std::cout << "Enter employee number (0 to end): ";
        std::cin >> employeeNumber;

        // Check if the loop should terminate
        if (employeeNumber == 0) {
            break;
        }

        // Get other details
        std::cout << "Enter gross pay: ";
        std::cin >> grossPay;
        while (grossPay < 0) {
            std::cout << "Gross pay cannot be negative. Please re-enter: ";
            std::cin >> grossPay;
        }

        std::cout << "Enter state tax: ";
        std::cin >> stateTax;
        while (stateTax < 0 || stateTax > grossPay) {
            std::cout << "State tax should be non-negative and less than or equal to gross pay. Please re-enter: ";
            std::cin >> stateTax;
        }

        std::cout << "Enter federal tax: ";
        std::cin >> federalTax;
        while (federalTax < 0 || federalTax > grossPay) {
            std::cout << "Federal tax should be non-negative and less than or equal to gross pay. Please re-enter: ";
            std::cin >> federalTax;
        }

        std::cout << "Enter FICA withholdings: ";
        std::cin >> ficaWithholdings;
        while (ficaWithholdings < 0 || ficaWithholdings > grossPay) {
            std::cout << "FICA withholdings should be non-negative and less than or equal to gross pay. Please re-enter: ";
            std::cin >> ficaWithholdings;
        }

        // Check if the total withholdings exceed gross pay
        if (stateTax + federalTax + ficaWithholdings > grossPay) {
            std::cout << "Error: Total withholdings exceed gross pay. Please re-enter data for employee number " << employeeNumber << ".\n";
            continue;  // Continue to the next iteration of the loop
        }

        // Update totals
        totalGrossPay += grossPay;
        totalStateTax += stateTax;
        totalFederalTax += federalTax;
        totalFICA += ficaWithholdings;
        totalNetPay += (grossPay - stateTax - federalTax - ficaWithholdings);

    } while (true);

    // Display the weekly payroll report with totals
    std::cout << "\nWeekly Payroll Report:\n"
              << std::setw(15) << "Total Gross Pay:" << std::setw(10) << totalGrossPay << "\n"
              << std::setw(15) << "Total State Tax:" << std::setw(10) << totalStateTax << "\n"
              << std::setw(15) << "Total Federal Tax:" << std::setw(10) << totalFederalTax << "\n"
              << std::setw(15) << "Total FICA:" << std::setw(10) << totalFICA << "\n"
              << std::setw(15) << "Total Net Pay:" << std::setw(10) << totalNetPay << std::endl;

    return 0;
}
