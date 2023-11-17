#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct SalesData {
    std::string division;
    int quarter;
    double sales;
};

void readSalesData(const std::string& fileName, std::vector<SalesData>& salesData) {
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        SalesData data;

        if (iss >> data.division >> data.quarter >> data.sales) {
            salesData.push_back(data);
        } else {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }

    inputFile.close();
}

int main() {
    const std::string fileName = "sales_data.txt";  // Adjust the file name as needed
    std::vector<SalesData> salesData;

    // Read sales data from the file
    readSalesData(fileName, salesData);

    // Calculate and display figures
    // (Assuming quarters are numbered from 1 to 4)

    // Total corporate sales for each quarter
    double totalQuarterlySales[4] = {0};

    // Total yearly sales for each division
    std::vector<double> totalYearlySales(salesData.size(), 0);

    // Total yearly corporate sales
    double totalCorporateSales = 0;

    // Average quarterly sales for the divisions
    std::vector<double> averageQuarterlySales(salesData.size(), 0);

    // Find the highest and lowest quarters for the corporation
    int highestQuarter = 0;
    int lowestQuarter = 0;

    for (const auto& data : salesData) {
        int quarterIndex = data.quarter - 1;

        // Total corporate sales for each quarter
        totalQuarterlySales[quarterIndex] += data.sales;

        // Total yearly sales for each division
        totalYearlySales[quarterIndex] += data.sales;

        // Total yearly corporate sales
        totalCorporateSales += data.sales;

        // Average quarterly sales for the divisions
        averageQuarterlySales[quarterIndex] += data.sales / 4;

        // Find the highest and lowest quarters for the corporation
        if (totalQuarterlySales[quarterIndex] > totalQuarterlySales[highestQuarter]) {
            highestQuarter = quarterIndex;
        }

        if (totalQuarterlySales[quarterIndex] < totalQuarterlySales[lowestQuarter]) {
            lowestQuarter = quarterIndex;
        }
    }

    // Display calculated figures
    std::cout << "Total corporate sales for each quarter:\n";
    for (int i = 0; i < 4; ++i) {
        std::cout << "Quarter " << i + 1 << ": $" << totalQuarterlySales[i] << std::endl;
    }

    std::cout << "\nTotal yearly sales for each division:\n";
    for (size_t i = 0; i < totalYearlySales.size(); ++i) {
        std::cout << "Division " << salesData[i].division << ": $" << totalYearlySales[i] << std::endl;
    }

    std::cout << "\nTotal yearly corporate sales: $" << totalCorporateSales << std::endl;

    std::cout << "\nAverage quarterly sales for the divisions:\n";
    for (size_t i = 0; i < averageQuarterlySales.size(); ++i) {
        std::cout << "Division " << salesData[i].division << ": $" << averageQuarterlySales[i] << std::endl;
    }

    std::cout << "\nHighest quarter for the corporation: Quarter " << highestQuarter + 1 << std::endl;
    std::cout << "Lowest quarter for the corporation: Quarter " << lowestQuarter + 1 << std::endl;

    return 0;
}
