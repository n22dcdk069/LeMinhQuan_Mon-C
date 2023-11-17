#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Constants
    const double seniorExemption = 5000.0; // Senior homeowner exemption in dollars
    const int quarterlyPayments = 4;       // Number of quarterly payments

    // Variables
    double actualValue, assessedValue, taxRate, taxableValue, annualTax, quarterlyTax;

    // Input
    cout << "Enter the actual value of the property: $";
    cin >> actualValue;

    cout << "Enter the current tax rate per $100 of assessed value: $";
    cin >> taxRate;

    // Calculate assessed value
    assessedValue = actualValue * 0.6;

    // Apply senior homeowner exemption
    taxableValue = assessedValue - seniorExemption;

    // Calculate annual property tax
    annualTax = taxableValue * (taxRate / 100.0);

    // Calculate quarterly tax bill
    quarterlyTax = annualTax / quarterlyPayments;

    // Display the result
    cout << fixed << setprecision(2);
    cout << "Assessed Value: $" << assessedValue << endl;
    cout << "Taxable Value: $" << taxableValue << endl;
    cout << "Annual Property Tax: $" << annualTax << endl;
    cout << "Quarterly Tax Bill: $" << quarterlyTax << endl;

    return 0;
}
