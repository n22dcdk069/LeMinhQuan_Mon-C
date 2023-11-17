#include <iostream>
using namespace std;

int main()
{
    double payRate;   // Holds the hourly pay rate
    double hours;     // Holds the hours worked
    int employNumber; // Holds the employee number

    // Input section
    cout << "Enter the employee number: ";
    cin >> employNumber;

    cout << "Enter the hourly pay rate: ";
    cin >> payRate;

    cout << "Enter the number of hours worked: ";
    cin >> hours;

    // Calculate the gross pay
    double grossPay = payRate * hours;

    // Display the payroll information
    cout << "Employee Number: " << employNumber << endl;
    cout << "Hourly Pay Rate: $" << payRate << endl;
    cout << "Hours Worked: " << hours << endl;
    cout << "Gross Pay: $" << grossPay << endl;

    return 0;
}
