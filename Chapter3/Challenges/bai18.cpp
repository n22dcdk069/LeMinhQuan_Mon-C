#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    // Variables
    double principal, rate, interest, amount;
    int timesCompounded;

    // Input
    cout << "Enter the principal amount: $";
    cin >> principal;

    cout << "Enter the annual interest rate (as a percentage): ";
    cin >> rate;

    cout << "Enter the number of times interest is compounded per year: ";
    cin >> timesCompounded;

    // Convert interest rate to decimal
    rate /= 100.0;

    // Calculate interest
    interest = principal * pow((1 + rate / timesCompounded), timesCompounded) - principal;

    // Calculate amount in savings
    amount = principal + interest;

    // Display the result
    cout << fixed << setprecision(2);
    cout << "Interest Rate: " << rate * 100 << "%" << endl;
    cout << "Times Compounded: " << timesCompounded << endl;
    cout << "Principal: $" << principal << endl;
    cout << "Interest: $" << interest << endl;
    cout << "Amount in Savings: $" << amount << endl;

    return 0;
}
