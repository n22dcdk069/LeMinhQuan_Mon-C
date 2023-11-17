#include <iostream>

int main() {
    // Define and initialize variables
    double payAmount = 2200.0;
    int payPeriods = 26;
    double annualPay;

    // Calculate the annual pay
    annualPay = payAmount * payPeriods;

    // Display the annual pay
    std::cout << "The employee's total annual pay is: $" << annualPay << std::endl;

    return 0;
}
