#include <iostream>
#include <iomanip>

class InventoryItem {
private:
    std::string itemName;
    double itemCost;
    int quantityOnHand;

public:
    // Constructor
    InventoryItem(const std::string& name, double cost, int quantity)
        : itemName(name), itemCost(cost), quantityOnHand(quantity) {}

    // Accessor functions
    std::string getItemName() const {
        return itemName;
    }

    double getItemCost() const {
        return itemCost;
    }

    int getQuantityOnHand() const {
        return quantityOnHand;
    }

    // Mutator function to update quantity on hand
    void updateQuantity(int quantity) {
        if (quantityOnHand - quantity >= 0) {
            quantityOnHand -= quantity;
        } else {
            std::cerr << "Error: Not enough items in stock.\n";
            exit(1); // Exit program with an error code
        }
    }
};

class CashRegister {
private:
    const double PROFIT_PERCENTAGE = 30.0;
    const double SALES_TAX_RATE = 6.0;

public:
    // Member function to process a purchase
    void processPurchase(InventoryItem& item, int quantity) {
        // Input Validation: Do not accept a negative value for the quantity of items being purchased
        if (quantity < 0) {
            std::cerr << "Invalid input. Quantity cannot be negative.\n";
            exit(1); // Exit program with an error code
        }

        // Get the item's cost from the InventoryItem object
        double itemCost = item.getItemCost();

        // Add a 30% profit to the cost to get the item's unit price
        double unitPrice = itemCost + (itemCost * PROFIT_PERCENTAGE / 100.0);

        // Multiply the unit price times the quantity being purchased to get the purchase subtotal
        double subtotal = unitPrice * quantity;

        // Compute a 6% sales tax on the subtotal to get the purchase total
        double salesTax = subtotal * SALES_TAX_RATE / 100.0;
        double total = subtotal + salesTax;

        // Display the purchase details
        std::cout << "Item: " << item.getItemName() << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << "Subtotal: $" << std::fixed << std::setprecision(2) << subtotal << std::endl;
        std::cout << "Sales Tax (" << SALES_TAX_RATE << "%): $" << salesTax << std::endl;
        std::cout << "Total: $" << total << std::endl;

        // Subtract the quantity being purchased from the onHand variable of the InventoryItem class object
        item.updateQuantity(quantity);
    }
};

int main() {
    // Create an InventoryItem object
    InventoryItem item("Widget", 10.0, 50);

    // Create a CashRegister object
    CashRegister register;

    // Ask the user for the item and quantity being purchased
    int quantity;
    std::cout << "Enter the quantity of " << item.getItemName() << " being purchased: ";
    std::cin >> quantity;

    // Process the purchase using the CashRegister class
    register.processPurchase(item, quantity);

    return 0;
}
