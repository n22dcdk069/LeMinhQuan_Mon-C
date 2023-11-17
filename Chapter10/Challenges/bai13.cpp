#include <iostream>
#include <sstream>
#include <iomanip>

int main() {
    // Get user input
    std::cout << "Enter a date (mm/dd/yyyy): ";
    std::string inputDate;
    std::getline(std::cin, inputDate);

    // Parse the input string to extract month, day, and year
    std::istringstream dateStream(inputDate);
    int month, day, year;
    char slash1, slash2;

    dateStream >> month >> slash1 >> day >> slash2 >> year;

    if (dateStream.fail() || slash1 != '/' || slash2 != '/' || month < 1 || month > 12 || day < 1 || day > 31 || year < 1) {
        std::cerr << "Invalid date format. Please enter a valid date in the mm/dd/yyyy format.\n";
        return 1;
    }

    // Convert the numeric month to its string representation
    std::string monthNames[] = {"January", "February", "March", "April", "May", "June",
                                "July", "August", "September", "October", "November", "December"};

    // Ensure that the month is within a valid range
    if (month >= 1 && month <= 12) {
        // Print the formatted date
        std::cout << monthNames[month - 1] << " " << day << ", " << year << std::endl;
    } else {
        std::cerr << "Invalid month. Please enter a valid month (1-12).\n";
        return 1;
    }

    return 0;
}
