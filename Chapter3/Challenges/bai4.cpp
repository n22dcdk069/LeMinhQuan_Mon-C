#include <iostream>
#include <string>
#include <iomanip> // Required for setprecision
using namespace std;

int main() {
    // Variables to store month names and rainfall amounts
    string month1, month2, month3;
    double rainfall1, rainfall2, rainfall3;

    // Get user input for each month and corresponding rainfall
    cout << "Enter the name of the first month: ";
    cin >> month1;
    cout << "Enter the amount of rainfall for " << month1 << " (in inches): ";
    cin >> rainfall1;

    cout << "Enter the name of the second month: ";
    cin >> month2;
    cout << "Enter the amount of rainfall for " << month2 << " (in inches): ";
    cin >> rainfall2;

    cout << "Enter the name of the third month: ";
    cin >> month3;
    cout << "Enter the amount of rainfall for " << month3 << " (in inches): ";
    cin >> rainfall3;

    // Calculate the average rainfall
    double averageRainfall = (rainfall1 + rainfall2 + rainfall3) / 3.0;

    // Display the average rainfall with fixed-point notation and two decimal places
    cout << fixed << setprecision(2);
    cout << "The average rainfall for " << month1 << ", " << month2 << ", and " << month3 << " is "
         << averageRainfall << " inches." << endl;

    return 0;
}
