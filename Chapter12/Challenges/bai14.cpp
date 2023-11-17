#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct InventoryItem {
    std::string description;
    int quantity;
    double wholesaleCost;
    double retailPrice;
};

void readInventoryData(const std::string& fileName, std::vector<InventoryItem>& inventory) {
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        InventoryItem item;

        if (iss >> item.description >> item.quantity >> item.wholesaleCost >> item.retailPrice) {
            inventory.push_back(item);
        } else {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }

    inputFile.close();
}

int main() {
    const std::string fileName = "inventory_data.txt"; // Replace with the actual file name
    std::vector<InventoryItem> inventory;

    // Read inventory data from the file
    readInventoryData(fileName, inventory);

    // Calculate and display data
    double totalWholesaleValue = 0;
    double totalRetailValue = 0;
    int totalQuantity = 0;

    for (const auto& item : inventory) {
        // Calculate total wholesale value
        totalWholesaleValue += item.wholesaleCost * item.quantity;

        // Calculate total retail value
        totalRetailValue += item.retailPrice * item.quantity;

        // Calculate total quantity
        totalQuantity += item.quantity;
    }

    // Display calculated data
    std::cout << "Total Wholesale Value of the Inventory: $" << totalWholesaleValue << std::endl;
    std::cout << "Total Retail Value of the Inventory: $" << totalRetailValue << std::endl;
    std::cout << "Total Quantity of All Items in the Inventory: " << totalQuantity << " units" << std::endl;

    return 0;
}