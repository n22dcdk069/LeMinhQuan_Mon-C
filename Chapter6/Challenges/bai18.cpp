#include <iostream>
#include <iomanip> // For setprecision

// Function prototypes
int getValidRooms();
double getValidPaintPrice();
double getValidWallSpace();
void calculateAndDisplayCosts(int numRooms, double paintPrice);

int main() {
    // Get user input and calculate/display costs
    int numRooms = getValidRooms();
    double paintPrice = getValidPaintPrice();
    calculateAndDisplayCosts(numRooms, paintPrice);

    return 0;
}

// Function to get a valid number of rooms
int getValidRooms() {
    int numRooms;
    do {
        std::cout << "Enter the number of rooms to be painted (must be at least 1): ";
        std::cin >> numRooms;

        if (numRooms < 1) {
            std::cout << "Please enter a valid number of rooms (at least 1).\n";
        }
    } while (numRooms < 1);

    return numRooms;
}

// Function to get a valid price of paint per gallon
double getValidPaintPrice() {
    double paintPrice;
    do {
        std::cout << "Enter the price of paint per gallon (must be at least $10.00): $";
        std::cin >> paintPrice;

        if (paintPrice < 10.00) {
            std::cout << "Please enter a valid price of paint per gallon (at least $10.00).\n";
        }
    } while (paintPrice < 10.00);

    return paintPrice;
}

// Function to get a valid square footage of wall space
double getValidWallSpace() {
    double wallSpace;
    do {
        std::cout << "Enter the square footage of wall space in each room (must be greater than 0): ";
        std::cin >> wallSpace;

        if (wallSpace <= 0) {
            std::cout << "Please enter a valid square footage of wall space (greater than 0).\n";
        }
    } while (wallSpace <= 0);

    return wallSpace;
}

// Function to calculate and display costs
void calculateAndDisplayCosts(int numRooms, double paintPrice) {
    const int SQUARE_FEET_PER_GALLON = 110;
    const double LABOR_HOURS_PER_GALLON = 8;
    const double LABOR_COST_PER_HOUR = 25.00;

    double totalGallons = 0, totalLaborHours = 0, totalPaintCost = 0, totalLaborCost = 0, totalCost = 0;

    for (int room = 1; room <= numRooms; ++room) {
        double wallSpace = getValidWallSpace();

        // Calculate gallons of paint required for the room
        double gallonsNeeded = wallSpace / SQUARE_FEET_PER_GALLON;
        totalGallons += gallonsNeeded;

        // Calculate labor hours required for the room
        double laborHoursNeeded = gallonsNeeded * LABOR_HOURS_PER_GALLON;
        totalLaborHours += laborHoursNeeded;

        // Calculate cost of paint for the room
        double paintCost = gallonsNeeded * paintPrice;
        totalPaintCost += paintCost;

        // Calculate labor cost for the room
        double laborCost = laborHoursNeeded * LABOR_COST_PER_HOUR;
        totalLaborCost += laborCost;
    }

    // Calculate total cost of the paint job
    totalCost = totalPaintCost + totalLaborCost;

    // Display the results
    std::cout << "\nCost Details for the Paint Job:\n";
    std::cout << "--------------------------------\n";
    std::cout << "Number of gallons of paint required: " << std::fixed << std::setprecision(2) << totalGallons << std::endl;
    std::cout << "Hours of labor required: " << std::fixed << std::setprecision(2) << totalLaborHours << std::endl;
    std::cout << "Cost of the paint: $" << std::fixed << std::setprecision(2) << totalPaintCost << std::endl;
    std::cout << "Labor charges: $" << std::fixed << std::setprecision(2) << totalLaborCost << std::endl;
    std::cout << "Total cost of the paint job: $" << std::fixed << std::setprecision(2) << totalCost << std::endl;
}
