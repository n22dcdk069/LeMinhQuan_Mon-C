#include <iostream>

// Function prototype for calculating profit or loss
double calculateProfit(int shares, double purchasePrice, double salePrice, double commission);

int main() {
    int numSales;

    // Get the number of stock sales
    std::cout << "Enter the number of stock sales: ";
    std::cin >> numSales;

    // Input validation: Do not accept a number less than 1 for the number of sales
    while (numSales < 1) {
        std::cout << "Invalid input. Please enter a number greater than or equal to 1: ";
        std::cin >> numSales;
    }

    double totalProfit = 0.0;

    for (int i = 1; i <= numSales; ++i) {
        int shares;
        double purchasePrice, salePrice, commission;

        // Get data for each stock sale
        std::cout << "\nStock Sale #" << i << "\n";
        std::cout << "Enter the number of shares: ";
        std::cin >> shares;

        std::cout << "Enter the purchase price per share: $";
        std::cin >> purchasePrice;

        std::cout << "Enter the sale price per share: $";
        std::cin >> salePrice;

        std::cout << "Enter the commission paid for the sale: $";
        std::cin >> commission;

        // Calculate and accumulate the profit or loss
        totalProfit += calculateProfit(shares, purchasePrice, salePrice, commission);
    }

    // Display the total profit or loss
    std::cout << "\nTotal Profit or Loss from " << numSales << " stock sales: $" << totalProfit << std::endl;

    return 0;
}

// Function definition for calculating profit or loss
double calculateProfit(int shares, double purchasePrice, double salePrice, double commission) {
    double totalPurchaseCost = shares * purchasePrice + commission;
    double totalSaleRevenue = shares * salePrice - commission;

    return totalSaleRevenue - totalPurchaseCost;
}
