#include <iostream>
#include <iomanip>

int main() {
    int numDays;

    // Get the number of days from the user (with input validation)
    do {
        std::cout << "Enter the number of days worked (must be 1 or more): ";
        std::cin >> numDays;

        if (numDays < 1) {
            std::cout << "Please enter a number of days that is 1 or more.\n";
        }
    } while (numDays < 1);

    // Display the table header
    std::cout << std::setw(10) << "Day" << std::setw(20) << "Salary ($)" << std::endl;
    std::cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << std::endl;

    // Calculate and display the salary progression for each day
    double totalPay = 0.0;
    for (int day = 1; day <= numDays; ++day) {
        double salary = 0.01 * (1 << (day - 1)); // Calculate the salary for the current day
        totalPay += salary; // Accumulate the total pay
        std::cout << std::setw(10) << day << std::setw(20) << std::fixed << std::setprecision(2) << salary << std::endl;
    }

    // Display the total pay at the end of the period
    std::cout << "Total pay over " << numDays << " days: $" << std::fixed << std::setprecision(2) << totalPay << std::endl;

    return 0;
}
