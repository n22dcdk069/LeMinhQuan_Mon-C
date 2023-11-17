#include <iostream>

int main() {
    // Declare variables for monthly expenses
    double loanPayment, insurance, gas, oil, tires, maintenance;

    // Get user input for monthly expenses
    std::cout << "Enter the monthly loan payment: $";
    std::cin >> loanPayment;

    std::cout << "Enter the monthly insurance cost: $";
    std::cin >> insurance;

    std::cout << "Enter the monthly gas cost: $";
    std::cin >> gas;

    std::cout << "Enter the monthly oil cost: $";
    std::cin >> oil;

    std::cout << "Enter the monthly tires cost: $";
    std::cin >> tires;

    std::cout << "Enter the monthly maintenance cost: $";
    std::cin >> maintenance;

    // Calculate total monthly and annual costs
    double totalMonthlyCost = loanPayment + insurance + gas + oil + tires + maintenance;
    double totalAnnualCost = totalMonthlyCost * 12;

    // Display the results
    std::cout << "\nTotal Monthly Cost: $" << totalMonthlyCost << std::endl;
    std::cout << "Total Annual Cost: $" << totalAnnualCost << std::endl;

    return 0;
}
