#include <iostream>

// Function prototype
double calculateProfitLoss(int numShares, double purchasePricePerShare, double purchaseCommission,
                            double salePricePerShare, double saleCommission);

int main() {
    // Get user input
    int numShares;
    double purchasePricePerShare, purchaseCommission, salePricePerShare, saleCommission;

    std::cout << "Enter the number of shares: ";
    std::cin >> numShares;

    std::cout << "Enter the purchase price per share: $";
    std::cin >> purchasePricePerShare;

    std::cout << "Enter the purchase commission paid: $";
    std::cin >> purchaseCommission;

    std::cout << "Enter the sale price per share: $";
    std::cin >> salePricePerShare;

    std::cout << "Enter the sale commission paid: $";
    std::cin >> saleCommission;

    // Calculate and display profit or loss
    double result = calculateProfitLoss(numShares, purchasePricePerShare, purchaseCommission,
                                         salePricePerShare, saleCommission);

    if (result >= 0) {
        std::cout << "\nThe sale resulted in a profit of $" << result << std::endl;
    } else {
        std::cout << "\nThe sale resulted in a loss of $" << -result << std::endl;
    }

    return 0;
}

// Function to calculate profit or loss from the sale of stock
double calculateProfitLoss(int numShares, double purchasePricePerShare, double purchaseCommission,
                            double salePricePerShare, double saleCommission) {
    return ((numShares * salePricePerShare - saleCommission) - (numShares * purchasePricePerShare + purchaseCommission));
}
