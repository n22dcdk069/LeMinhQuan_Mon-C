#include <iostream>
#include <iomanip> // For setprecision

// Function prototypes
void getData(int &spoolsOrdered, int &spoolsInStock, bool &specialCharges, double &specialChargesAmount);
void displayOrderStatus(int spoolsOrdered, int spoolsInStock, bool specialCharges, double specialChargesAmount = 10.00);

int main() {
    // Variables to store input data
    int spoolsOrdered, spoolsInStock;
    bool specialCharges;
    double specialChargesAmount;

    // Get input data
    getData(spoolsOrdered, spoolsInStock, specialCharges, specialChargesAmount);

    // Display order status
    displayOrderStatus(spoolsOrdered, spoolsInStock, specialCharges, specialChargesAmount);

    return 0;
}

// Function to get input data
void getData(int &spoolsOrdered, int &spoolsInStock, bool &specialCharges, double &specialChargesAmount) {
    // Get the number of spools ordered
    do {
        std::cout << "Enter the number of spools ordered (must be at least 1): ";
        std::cin >> spoolsOrdered;

        if (spoolsOrdered < 1) {
            std::cout << "Please enter a valid number (at least 1).\n";
        }
    } while (spoolsOrdered < 1);

    // Get the number of spools in stock
    do {
        std::cout << "Enter the number of spools in stock: ";
        std::cin >> spoolsInStock;

        if (spoolsInStock < 0) {
            std::cout << "Please enter a valid number (0 or greater).\n";
        }
    } while (spoolsInStock < 0);

    // Ask for special shipping and handling charges
    std::cout << "Are there special shipping and handling charges? (1 for Yes, 0 for No): ";
    std::cin >> specialCharges;

    // If there are special charges, ask for the amount per spool
    if (specialCharges) {
        do {
            std::cout << "Enter the special charges per spool: $";
            std::cin >> specialChargesAmount;

            if (specialChargesAmount < 0) {
                std::cout << "Please enter a valid amount (0 or greater).\n";
            }
        } while (specialChargesAmount < 0);
    }
}

// Function to display order status
void displayOrderStatus(int spoolsOrdered, int spoolsInStock, bool specialCharges, double specialChargesAmount) {
    // Calculate the number of spools ready to ship
    int spoolsReadyToShip = std::min(spoolsOrdered, spoolsInStock);

    // Calculate the number of spools on backorder
    int spoolsOnBackorder = std::max(spoolsOrdered - spoolsInStock, 0);

    // Calculate the subtotal of the portion ready to ship
    double subtotalReadyToShip = spoolsReadyToShip * 100.00;

    // Calculate total shipping and handling charges on the portion ready to ship
    double totalShippingCharges = spoolsReadyToShip * specialChargesAmount;

    // Calculate total of the order ready to ship
    double totalOrderReadyToShip = subtotalReadyToShip + totalShippingCharges;

    // Display order status
    std::cout << "\nOrder Status:\n";
    std::cout << "Number of spools ready to ship: " << spoolsReadyToShip << std::endl;
    std::cout << "Number of spools on backorder: " << spoolsOnBackorder << std::endl;
    std::cout << "Subtotal of the portion ready to ship: $" << std::fixed << std::setprecision(2) << subtotalReadyToShip << std::endl;
    std::cout << "Total shipping and handling charges on the portion ready to ship: $" << totalShippingCharges << std::endl;
    std::cout << "Total of the order ready to ship: $" << totalOrderReadyToShip << std::endl;
}
