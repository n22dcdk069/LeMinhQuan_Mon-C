#include <iostream>

int main() {
    const int asterisksPer100Sales = 1; // Number of asterisks per $100 of sales

    int sales[5];

    // Get today's sales for each store
    for (int i = 0; i < 5; ++i) {
        std::cout << "Enter today's sales for store " << (i + 1) << ": ";
        std::cin >> sales[i];

        // Input validation: Ensure sales are non-negative
        while (sales[i] < 0) {
            std::cout << "Sales cannot be negative. Please re-enter today's sales for store " << (i + 1) << ": ";
            std::cin >> sales[i];
        }
    }

    // Display the sales bar chart
    std::cout << "\nSALES BAR CHART\n(Each * = $100)\n";

    for (int i = 0; i < 5; ++i) {
        std::cout << "Store " << (i + 1) << ": ";
        for (int j = 0; j < (sales[i] / 100) * asterisksPer100Sales; ++j) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }

    return 0;
}
