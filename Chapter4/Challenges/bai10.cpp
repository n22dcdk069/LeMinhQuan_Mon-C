#include <iostream>

int main() {
    // Variables to store user input
    int month, year;

    // Get input for the month
    std::cout << "Enter a month (1-12): ";
    std::cin >> month;

    // Validate the month input
    if (month < 1 || month > 12) {
        std::cout << "Error: Invalid month. Please enter a month in the range 1-12.\n";
        return 1; // Exit the program with an error code
    }

    // Get input for the year
    std::cout << "Enter a year: ";
    std::cin >> year;

    // Check if the year is a leap year
    bool isLeapYear = false;
    if ((year % 100 == 0 && year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)) {
        isLeapYear = true;
    }

    // Determine the number of days in the entered month
    int daysInMonth;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31;
            break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30;
            break;
        case 2:
            daysInMonth = (isLeapYear) ? 29 : 28;
            break;
        default:
            std::cout << "Error: Invalid month.\n";
            return 1; // Exit the program with an error code
    }

    // Display the result
    std::cout << daysInMonth << " days\n";

    return 0;
}
