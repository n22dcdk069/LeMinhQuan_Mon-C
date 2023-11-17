#include <iostream>
#include <string>

// Function to get sales for a division
double getSales(const std::string& divisionName) {
    double sales;

    // Get and validate the sales input
    do {
        std::cout << "Enter quarterly sales for " << divisionName << " division: $";
        std::cin >> sales;

        // Input validation: Do not accept dollar amounts less than $0.00
        if (sales < 0.0) {
            std::cout << "Invalid input. Sales must be a non-negative amount.\n";
        }
    } while (sales < 0.0);

    return sales;
}

// Function to find the highest sales and print the result
void findHighest(double northeastSales, double southeastSales, double northwestSales, double southwestSales) {
    double highestSales = northeastSales;
    std::string highestDivision = "Northeast";

    if (southeastSales > highestSales) {
        highestSales = southeastSales;
        highestDivision = "Southeast";
    }

    if (northwestSales > highestSales) {
        highestSales = northwestSales;
        highestDivision = "Northwest";
    }

    if (southwestSales > highestSales) {
        highestSales = southwestSales;
        highestDivision = "Southwest";
    }

    // Display the result
    std::cout << "The division with the highest sales is " << highestDivision << " with sales: $" << highestSales << std::endl;
}

int main() {
    // Get sales for each division
    double northeastSales = getSales("Northeast");
    double southeastSales = getSales("Southeast");
    double northwestSales = getSales("Northwest");
    double southwestSales = getSales("Southwest");

    // Find and display the highest sales division
    findHighest(northeastSales, southeastSales, northwestSales, southwestSales);

    return 0;
}