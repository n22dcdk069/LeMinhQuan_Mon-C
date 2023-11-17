#include <iostream>
using namespace std;

int main() {
    // Declare variables
    double gallonsOfGas, milesPerTank, mileage;

    // Get user input
    cout << "Enter the number of gallons of gas the car can hold: ";
    cin >> gallonsOfGas;

    cout << "Enter the number of miles the car can be driven on a full tank: ";
    cin >> milesPerTank;

    // Calculate gas mileage
    mileage = milesPerTank / gallonsOfGas;

    // Display the result
    cout << "The car's gas mileage is: " << mileage << " miles per gallon." << endl;

    return 0;
}