#include <iostream>
#include <iomanip>

class Inventory {
private:
    int itemNumber;
    int quantity;
    double cost;
    double totalCost;

public:
    // Default constructor
    Inventory() : itemNumber(0), quantity(0), cost(0.0), totalCost(0.0) {}

    // Constructor #2
    Inventory(int num, double itemCost, int qty) : itemNumber(num), quantity(qty), cost(itemCost) {
        setTotalCost();
    }

    // Setter functions
    void setItemNumber(int num) {
        if (num >= 0) {
            itemNumber = num;
        } else {
            std::cerr << "Error: Item number cannot be negative.\n";
        }
    }

    void setQuantity(int qty) {
        if (qty >= 0) {
            quantity = qty;
            setTotalCost();
        } else {
            std::cerr << "Error: Quantity cannot be negative.\n";
        }
    }

    void setCost(double itemCost) {
        if (itemCost >= 0) {
            cost = itemCost;
            setTotalCost();
        } else {
            std::cerr << "Error: Cost cannot be negative.\n";
        }
    }

    void setTotalCost() {
        totalCost = quantity * cost;
    }

    // Getter functions
    int getItemNumber() const {
        return itemNumber;
    }

    int getQuantity() const {
        return quantity;
    }

    double getCost() const {
        return cost;
    }

    double getTotalCost() const {
        return totalCost;
    }
};

int main() {
    // Demonstrate the Inventory class
    Inventory item1;
    item1.setItemNumber(101);
    item1.setQuantity(20);
    item1.setCost(15.99);

    Inventory item2(102, 29.99, 15);

    // Display information for item1
    std::cout << "Item 1 Information:\n";
    std::cout << "Item Number: " << item1.getItemNumber() << "\n";
    std::cout << "Quantity: " << item1.getQuantity() << "\n";
    std::cout << "Cost per unit: $" << item1.getCost() << "\n";
    std::cout << "Total Cost: $" << std::fixed << std::setprecision(2) << item1.getTotalCost() << "\n\n";

    // Display information for item2
    std::cout << "Item 2 Information:\n";
    std::cout << "Item Number: " << item2.getItemNumber() << "\n";
    std::cout << "Quantity: " << item2.getQuantity() << "\n";
    std::cout << "Cost per unit: $" << item2.getCost() << "\n";
    std::cout << "Total Cost: $" << std::fixed << std::setprecision(2) << item2.getTotalCost() << "\n";

    return 0;
}
