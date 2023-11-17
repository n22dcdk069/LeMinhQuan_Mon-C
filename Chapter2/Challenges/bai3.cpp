#include <iostream>

int main() {
    // Define the purchase amount and sales tax rates
    double purchaseAmount = 95.0;  // Purchase amount in dollars
    double stateSalesTaxRate = 4.0;  // State sales tax rate in percent
    double countySalesTaxRate = 2.0;  // County sales tax rate in percent

    // Calculate the sales tax amounts
    double stateSalesTax = (stateSalesTaxRate / 100) * purchaseAmount;
    double countySalesTax = (countySalesTaxRate / 100) * purchaseAmount;
    double totalSalesTax = stateSalesTax + countySalesTax;

    // Display the sales tax amounts
    std::cout << "State Sales Tax: $" << stateSalesTax << std::endl;
    std::cout << "County Sales Tax: $" << countySalesTax << std::endl;
    std::cout << "Total Sales Tax: $" << totalSalesTax << std::endl;

    return 0;
}
