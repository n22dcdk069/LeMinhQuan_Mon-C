#include <iostream>

int main() {
    // Define the meal cost and tax/tip percentages
    double mealCost = 88.67;          // Meal cost in dollars
    double taxRate = 6.75;            // Tax rate in percent
    double tipRate = 20.0;            // Tip rate in percent

    // Calculate tax and tip amounts
    double taxAmount = (taxRate / 100) * mealCost;
    double totalWithTax = mealCost + taxAmount;
    double tipAmount = (tipRate / 100) * totalWithTax;
    double totalBill = totalWithTax + tipAmount;

    // Display the results
    std::cout << "Meal Cost: $" << mealCost << std::endl;
    std::cout << "Tax Amount: $" << taxAmount << std::endl;
    std::cout << "Tip Amount: $" << tipAmount << std::endl;
    std::cout << "Total Bill: $" << totalBill << std::endl;

    return 0;
}
