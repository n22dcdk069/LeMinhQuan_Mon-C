#include <iostream>
using namespace std;

int main() {
    int shares = 750;
    double sharePrice = 35.00;
    double commissionRate = 0.02;

    // Calculate the amount paid for the stock alone
    double stockAmount = shares * sharePrice;

    // Calculate the commission
    double commission = stockAmount * commissionRate;

    // Calculate the total amount paid
    double totalAmount = stockAmount + commission;

    // Display the results
    cout << "Amount paid for the stock alone: $" << stockAmount << endl;
    cout << "Commission: $" << commission << endl;
    cout << "Total amount paid: $" << totalAmount << endl;

    return 0;
}
