#include <iostream>
#include <string>

// Define the structure for company division data
struct DivisionData {
    std::string divisionName;
    double firstQuarterSales;
    double secondQuarterSales;
    double thirdQuarterSales;
    double fourthQuarterSales;
    double totalAnnualSales;
    double averageQuarterlySales;
};

// Function to input sales figures for a division
void inputSales(DivisionData& division) {
    std::cout << "Enter sales figures for " << division.divisionName << " division:" << std::endl;

    // Input validation loop for each quarter
    do {
        std::cout << "First Quarter Sales: ";
        std::cin >> division.firstQuarterSales;
    } while (division.firstQuarterSales < 0);

    do {
        std::cout << "Second Quarter Sales: ";
        std::cin >> division.secondQuarterSales;
    } while (division.secondQuarterSales < 0);

    do {
        std::cout << "Third Quarter Sales: ";
        std::cin >> division.thirdQuarterSales;
    } while (division.thirdQuarterSales < 0);

    do {
        std::cout << "Fourth Quarter Sales: ";
        std::cin >> division.fourthQuarterSales;
    } while (division.fourthQuarterSales < 0);

    // Calculate total annual sales and average quarterly sales
    division.totalAnnualSales = division.firstQuarterSales + division.secondQuarterSales +
                                division.thirdQuarterSales + division.fourthQuarterSales;
    division.averageQuarterlySales = division.totalAnnualSales / 4;
}

// Function to display division information
void displayDivisionInfo(const DivisionData& division) {
    std::cout << "\nDivision Name: " << division.divisionName << std::endl;
    std::cout << "Total Annual Sales: " << division.totalAnnualSales << std::endl;
    std::cout << "Average Quarterly Sales: " << division.averageQuarterlySales << std::endl;
}

int main() {
    // Create structure variables for East, West, North, and South divisions
    DivisionData eastDivision = {"East"};
    DivisionData westDivision = {"West"};
    DivisionData northDivision = {"North"};
    DivisionData southDivision = {"South"};

    // Input sales figures for each division
    inputSales(eastDivision);
    inputSales(westDivision);
    inputSales(northDivision);
    inputSales(southDivision);

    // Display information for each division
    displayDivisionInfo(eastDivision);
    displayDivisionInfo(westDivision);
    displayDivisionInfo(northDivision);
    displayDivisionInfo(southDivision);

    return 0;
}
