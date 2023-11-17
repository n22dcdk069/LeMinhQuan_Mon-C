#include <iostream>
using namespace std;

int main() {
    double costPrice = 14.95;
    double profitPercentage = 35.0;  // 35 percent profit

    double profitAmount = costPrice * (profitPercentage / 100);
    double sellingPrice = costPrice + profitAmount;

    cout << "The selling price of the circuit board is: $" << sellingPrice << endl;

    return 0;
}
