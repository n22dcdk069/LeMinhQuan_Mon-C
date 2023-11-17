#include <iostream>
#include <string>

int main() {
    const int numSalsas = 5;
    
    // Initialize array of salsa names
    std::string salsaNames[numSalsas] = {"mild", "medium", "sweet", "hot", "zesty"};
    
    // Initialize array to store the number of jars sold for each salsa type
    int jarsSold[numSalsas];

    // Input sales data for each salsa type
    for (int i = 0; i < numSalsas; ++i) {
        do {
            std::cout << "Enter the number of jars sold for " << salsaNames[i] << ": ";
            std::cin >> jarsSold[i];

            // Input validation
            if (jarsSold[i] < 0) {
                std::cout << "Please enter a non-negative value.\n";
            }
        } while (jarsSold[i] < 0);
    }

    // Display sales report
    std::cout << "\nSales Report:\n";
    std::cout << "-----------------\n";

    int totalSales = 0;
    int maxSalesIndex = 0;
    int minSalesIndex = 0;

    // Calculate total sales and find highest and lowest selling products
    for (int i = 0; i < numSalsas; ++i) {
        totalSales += jarsSold[i];

        if (jarsSold[i] > jarsSold[maxSalesIndex]) {
            maxSalesIndex = i;
        }

        if (jarsSold[i] < jarsSold[minSalesIndex]) {
            minSalesIndex = i;
        }
    }

    // Display individual salsa sales
    for (int i = 0; i < numSalsas; ++i) {
        std::cout << salsaNames[i] << ": " << jarsSold[i] << " jars\n";
    }

    // Display total sales
    std::cout << "Total Sales: " << totalSales << " jars\n";

    // Display highest and lowest selling products
    std::cout << "Highest Selling Salsa: " << salsaNames[maxSalesIndex] << "\n";
    std::cout << "Lowest Selling Salsa: " << salsaNames[minSalesIndex] << "\n";

    return 0;
}
