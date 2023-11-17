#include <iostream>

int main() {
    // Define the total sales and the percentage for the East Coast division
    double totalSales = 8.6;  // Total sales in millions
    double eastCoastPercentage = 58.0;  // Percentage for the East Coast division

    // Calculate the East Coast division's sales
    double eastCoastSales = (eastCoastPercentage / 100) * totalSales;

    // Display the predicted East Coast division sales
    std::cout << "The East Coast division is predicted to generate $" << eastCoastSales << " million." << std::endl;

    return 0;
}
