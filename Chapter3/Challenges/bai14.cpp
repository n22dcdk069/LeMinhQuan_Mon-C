#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Constants
    const double stateTaxRate = 0.04;  // State sales tax rate (4%)
    const double countyTaxRate = 0.02; // County sales tax rate (2%)

    // Variables
    string month, year;
    double totalCollected, productSales, countySalesTax, stateSalesTax, totalSalesTax;

    // Input
    cout << "Enter the month: ";
    getline(cin, month);

    cout << "Enter the year: ";
    getline(cin, year);

    cout << "Enter the total amount collected at the cash register: $";
    cin >> totalCollected;

    // Calculate product sales
    productSales = totalCollected / 1.06;

    // Calculate sales tax amounts
    countySalesTax = productSales * countyTaxRate;
    stateSalesTax = productSales * stateTaxRate;
    totalSalesTax = countySalesTax + stateSalesTax;

    // Display the report
    cout << fixed << setprecision(2);
    cout << "Month: " << month << endl;
    cout << "-----------------------" << endl;
    cout << "Total Collected: $" << totalCollected << endl;
    cout << "Sales: $" << productSales << endl;
    cout << "County Sales Tax: $" << countySalesTax << endl;
    cout << "State Sales Tax: $" << stateSalesTax << endl;
    cout << "Total Sales Tax: $" << totalSalesTax << endl;

    return 0;
}
