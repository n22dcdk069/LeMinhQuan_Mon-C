#include <iostream>
#include <string>

// Enumerated data type for months
enum Month {
    JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE,
    JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};

// Define the structure for company division data
struct DivisionData {
    std::string divisionName;
    double quarterlySales[4];
    double totalAnnualSales;
    double averageQuarterlySales;
};

// Function to input sales figures for a division
void inputSales(DivisionData& division) {
    std::cout << "Enter sales figures for " << division.divisionName << " division:" << std::endl;

    // Input validation loop for each quarter
    for (int i = 0; i < 4; ++i) {
        do {
            std::cout << "Quarter " << (i + 1) << " Sales: ";
            std::cin >> division.quarterlySales[i];
        } while (division.quarterlySales[i] < 0);
    }

    // Calculate total annual sales and average quarterly sales
    division.totalAnnualSales = 0;
    for (double quarterSales : division.quarterlySales) {
        division.totalAnnualSales += quarterSales;
    }
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