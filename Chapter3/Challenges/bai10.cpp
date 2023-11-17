#include <iostream>
using namespace std;

int main() {
    // Constants
    const double insurancePercentage = 0.8; // 80% of replacement cost

    // Variables
    double replacementCost, minimumInsurance;

    // Input
    cout << "Enter the replacement cost of the building: $";
    cin >> replacementCost;

    // Calculate minimum insurance
    minimumInsurance = replacementCost * insurancePercentage;

    // Display the result
    cout << "Minimum amount of insurance recommended: $" << minimumInsurance << endl;

    return 0;
}
