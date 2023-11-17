#include <iostream>
#include <fstream>
#include <string>

// Structure to store division data
struct Division {
    std::string name;
    int quarter;
    double quarterlySales;
};

// Function prototype
void getQuarterlySales(Division& division);

int main() {
    // Create an array of Division structures for each division and quarter
    const int NUM_DIVISIONS = 4;
    const int NUM_QUARTERS = 4;
    Division divisions[NUM_DIVISIONS * NUM_QUARTERS];

    // Get quarterly sales figures for each division
    for (int i = 0; i < NUM_DIVISIONS * NUM_QUARTERS; ++i) {
        getQuarterlySales(divisions[i]);
    }

    // Open a file for writing
    std::ofstream outFile("sales_data.txt");

    if (!outFile.is_open()) {
        std::cerr << "Error opening the file. Exiting program.\n";
        return 1; // Return an error code
    }

    // Write the data to the file
    for (int i = 0; i < NUM_DIVISIONS * NUM_QUARTERS; ++i) {
        outFile << divisions[i].name << " Quarter " << divisions[i].quarter
                << " Sales: $" << divisions[i].quarterlySales << std::endl;
    }

    std::cout << "Data written to sales_data.txt\n";

    // Close the file
    outFile.close();

    return 0;
}

// Function to get quarterly sales figures for a division
void getQuarterlySales(Division& division) {
    std::cout << "Enter the division name: ";
    std::cin >> division.name;

    do {
        std::cout << "Enter the quarter (1-4): ";
        std::cin >> division.quarter;

        if (division.quarter < 1 || division.quarter > 4) {
            std::cout << "Invalid quarter. Please enter a number between 1 and 4.\n";
        }
    } while (division.quarter < 1 || division.quarter > 4);

    do {
        std::cout << "Enter the quarterly sales for " << division.name
                  << " in Quarter " << division.quarter << ": $";
        std::cin >> division.quarterlySales;

        if (division.quarterlySales < 0) {
            std::cout << "Invalid sales figure. Please enter a non-negative number.\n";
        }
    } while (division.quarterlySales < 0);
}
