#include <iostream>
#include <iomanip>

int main() {
    // Constants
    const int numShares = 1000;
    const double purchasePricePerShare = 45.50;
    const double salePricePerShare = 56.90;
    const double commissionRate = 0.02; // 2%

    // Calculate the amounts
    double amountPaid = numShares * purchasePricePerShare;
    double purchaseCommission = amountPaid * commissionRate;

    double amountReceived = numShares * salePricePerShare;
    double saleCommission = amountReceived * commissionRate;

    double profit = amountReceived - saleCommission - amountPaid - purchaseCommission;

    // Display the information
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Amount Joe paid for the stock: $" << amountPaid << "\n";
    std::cout << "Commission Joe paid when buying the stock: $" << purchaseCommission << "\n";
    std::cout << "Amount Joe sold the stock for: $" << amountReceived << "\n";
    std::cout << "Commission Joe paid when selling the stock: $" << saleCommission << "\n";
    std::cout << "Profit after commissions: $" << profit << "\n";

    return 0;
}
