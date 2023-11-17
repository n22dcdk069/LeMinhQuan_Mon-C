#include <iostream>
#include <iomanip>

int main() {
    int numFloors;

    // Get the number of floors from the user (with input validation)
    do {
        std::cout << "Enter the number of floors in the hotel (must be 1 or more): ";
        std::cin >> numFloors;

        if (numFloors < 1) {
            std::cout << "Please enter a number of floors that is 1 or more.\n";
        }
    } while (numFloors < 1);

    int totalRooms = 0;
    int totalOccupied = 0;

    // Loop for each floor
    for (int floor = 1; floor <= numFloors; ++floor) {
        int numRooms, numOccupied;

        // Get the number of rooms on the floor and the number of occupied rooms
        do {
            std::cout << "Enter the number of rooms on floor " << floor << " (must be 10 or more): ";
            std::cin >> numRooms;

            if (numRooms < 10) {
                std::cout << "Please enter a number of rooms that is 10 or more.\n";
            }
        } while (numRooms < 10);

        std::cout << "Enter the number of occupied rooms on floor " << floor << ": ";
        std::cin >> numOccupied;

        // Update totals
        totalRooms += numRooms;
        totalOccupied += numOccupied;
    }

    // Calculate the occupancy rate
    double occupancyRate = (static_cast<double>(totalOccupied) / totalRooms) * 100;

    // Display the results
    std::cout << "\nHotel Information:\n"
              << "Total number of rooms: " << totalRooms << "\n"
              << "Number of occupied rooms: " << totalOccupied << "\n"
              << "Number of unoccupied rooms: " << totalRooms - totalOccupied << "\n"
              << "Occupancy rate: " << std::fixed << std::setprecision(2) << occupancyRate << "%\n";

    return 0;
}
