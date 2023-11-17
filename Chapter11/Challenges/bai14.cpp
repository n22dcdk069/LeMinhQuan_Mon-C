#include <iostream>
#include <iomanip>
#include <string>

const int NUM_BINS = 10;
const int MAX_PARTS_PER_BIN = 30;

// Structure to represent each bin
struct InventoryBin {
    std::string partDescription;
    int numParts;
};

// Function to display the inventory bins
void displayInventory(const InventoryBin bins[], int numBins) {
    std::cout << std::setw(20) << "Part Description" << std::setw(20) << "Number of Parts" << std::endl;
    std::cout << std::string(45, '-') << std::endl;

    for (int i = 0; i < numBins; ++i) {
        std::cout << std::setw(20) << bins[i].partDescription
                  << std::setw(20) << bins[i].numParts << std::endl;
    }
}

// Function to add parts to a specific bin
void addParts(InventoryBin& bin, int numToAdd) {
    if (bin.numParts + numToAdd <= MAX_PARTS_PER_BIN) {
        bin.numParts += numToAdd;
        std::cout << "Added " << numToAdd << " parts to bin. New total: " << bin.numParts << " parts.\n";
    } else {
        std::cout << "Cannot add more parts than the bin can hold.\n";
    }
}

// Function to remove parts from a specific bin
void removeParts(InventoryBin& bin, int numToRemove) {
    if (bin.numParts - numToRemove >= 0) {
        bin.numParts -= numToRemove;
        std::cout << "Removed " << numToRemove << " parts from bin. New total: " << bin.numParts << " parts.\n";
    } else {
        std::cout << "Cannot remove more parts than are in the bin.\n";
    }
}

int main() {
    // Initialize the array of bins with data
    InventoryBin bins[NUM_BINS] = {
        {"Valve", 10},
        {"Bearing", 5},
        {"Bushing", 15},
        {"Coupling", 21},
        {"Flange", 7},
        {"Gear", 5},
        {"Gear Housing", 5},
        {"Vacuum Gripper", 25},
        {"Cable", 18},
        {"Rod", 12}
    };

    while (true) {
        // Display current inventory
        std::cout << "\nCurrent Inventory:\n";
        displayInventory(bins, NUM_BINS);

        // Prompt user to select a bin or quit
        std::cout << "\nEnter the number of the bin you want to select (1-10), or enter 0 to quit: ";
        int choice;
        std::cin >> choice;

        if (choice == 0) {
            std::cout << "Exiting the program. Goodbye!\n";
            break;
        } else if (choice >= 1 && choice <= NUM_BINS) {
            // Display options for the selected bin
            std::cout << "\nSelected Bin: " << bins[choice - 1].partDescription << " (Bin " << choice << ")\n";
            std::cout << "1. Add Parts\n";
            std::cout << "2. Remove Parts\n";
            std::cout << "Enter your choice (1 or 2): ";

            int option;
            std::cin >> option;

            if (option == 1) {
                // Add parts
                std::cout << "Enter the number of parts to add: ";
                int numToAdd;
                std::cin >> numToAdd;
                addParts(bins[choice - 1], numToAdd);
            } else if (option == 2) {
                // Remove parts
                std::cout << "Enter the number of parts to remove: ";
                int numToRemove;
                std::cin >> numToRemove;
                removeParts(bins[choice - 1], numToRemove);
            } else {
                std::cout << "Invalid choice. Please enter 1 or 2.\n";
            }
        } else {
            std::cout << "Invalid bin number. Please enter a number between 1 and 10.\n";
        }
    }

    return 0;
}
