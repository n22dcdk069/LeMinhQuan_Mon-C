#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

// Structure to store inventory data
struct InventoryItem {
    std::string description;
    int quantity;
    double wholesaleCost;
    double retailCost;
    std::string dateAdded;
};

// Function prototypes
void addRecord(std::ofstream& outFile);
void displayRecord(std::ifstream& inFile);
void changeRecord(std::fstream& ioFile);

int main() {
    std::fstream inventoryFile("inventory_data.txt", std::ios::in | std::ios::out | std::ios::app);

    if (!inventoryFile.is_open()) {
        std::cerr << "Error opening the file. Exiting program.\n";
        return 1; // Return an error code
    }

    int choice;

    do {
        // Display menu
        std::cout << "\nInventory Management Menu:\n";
        std::cout << "1. Add new record\n";
        std::cout << "2. Display record\n";
        std::cout << "3. Change record\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addRecord(inventoryFile);
                break;
            case 2:
                displayRecord(inventoryFile);
                break;
            case 3:
                changeRecord(inventoryFile);
                break;
            case 4:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }

    } while (choice != 4);

    // Close the file
    inventoryFile.close();

    return 0;
}

// Function to add a new record to the file
void addRecord(std::ofstream& outFile) {
    InventoryItem newItem;

    // Input data for the new item
    std::cout << "Enter item description: ";
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, newItem.description);

    do {
        std::cout << "Enter quantity on hand: ";
        std::cin >> newItem.quantity;

        if (newItem.quantity < 0) {
            std::cout << "Invalid quantity. Please enter a non-negative number.\n";
        }
    } while (newItem.quantity < 0);

    do {
        std::cout << "Enter wholesale cost: $";
        std::cin >> newItem.wholesaleCost;

        if (newItem.wholesaleCost < 0) {
            std::cout << "Invalid cost. Please enter a non-negative number.\n";
        }
    } while (newItem.wholesaleCost < 0);

    do {
        std::cout << "Enter retail cost: $";
        std::cin >> newItem.retailCost;

        if (newItem.retailCost < 0) {
            std::cout << "Invalid cost. Please enter a non-negative number.\n";
        }
    } while (newItem.retailCost < 0);

    std::cout << "Enter date added to inventory (MM/DD/YYYY): ";
    std::cin >> newItem.dateAdded;

    // Write the new item to the file
    outFile << newItem.description << " "
            << newItem.quantity << " "
            << newItem.wholesaleCost << " "
            << newItem.retailCost << " "
            << newItem.dateAdded << std::endl;

    std::cout << "Record added successfully.\n";
}

// Function to display a specific record from the file
void displayRecord(std::ifstream& inFile) {
    int recordNumber;

    // Input the record number to display
    std::cout << "Enter the record number to display: ";
    std::cin >> recordNumber;

    // Move to the specified record in the file
    inFile.seekg((recordNumber - 1) * sizeof(InventoryItem), std::ios::beg);

    // Read the record from the file
    InventoryItem item;
    inFile >> item.description >> item.quantity >> item.wholesaleCost >> item.retailCost >> item.dateAdded;

    // Display the record
    if (!inFile.fail()) {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Record " << recordNumber << ":\n";
        std::cout << "Description: " << item.description << "\n";
        std::cout << "Quantity on Hand: " << item.quantity << "\n";
        std::cout << "Wholesale Cost: $" << item.wholesaleCost << "\n";
        std::cout << "Retail Cost: $" << item.retailCost << "\n";
        std::cout << "Date Added to Inventory: " << item.dateAdded << "\n";
    } else {
        std::cout << "Record not found.\n";
    }
}

// Function to change a specific record in the file
void changeRecord(std::fstream& ioFile) {
    int recordNumber;

    // Input the record number to change
    std::cout << "Enter the record number to change: ";
    std::cin >> recordNumber;

    // Move to the specified record in the file
    ioFile.seekg((recordNumber - 1) * sizeof(InventoryItem), std::ios::beg);

    // Read the record from the file
    InventoryItem item;
    ioFile >> item.description >> item.quantity >> item.wholesaleCost >> item.retailCost >> item.dateAdded;

    // Change the data in the record
    std::cout << "Enter the new data for the record:\n";
    addRecord(ioFile);

    // Display the record after modification
    std::cout << "Record " << recordNumber << " has been changed:\n";
    displayRecord(ioFile);
}
