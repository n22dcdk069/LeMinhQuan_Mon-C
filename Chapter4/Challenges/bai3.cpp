#include <iostream>

int main() {
    // Get user input
    int month, day, year;

    std::cout << "Enter the month (numeric form): ";
    std::cin >> month;

    std::cout << "Enter the day: ";
    std::cin >> day;

    std::cout << "Enter the two-digit year: ";
    std::cin >> year;

    // Check if the date is magic
    if (month * day == year) {
        std::cout << "The date is magic!" << std::endl;
    } else {
        std::cout << "The date is not magic." << std::endl;
    }

    return 0;
}
