#include <iostream>
#include <string>

class Date {
private:
    int month;
    int day;
    int year;

public:
    // Constructor to initialize the Date object
    Date(int m, int d, int y) : month(m), day(d), year(y) {}

    // Member functions to print the date in different forms
    void printDateFormat1() const {
        std::cout << month << "/" << day << "/" << year << std::endl;
    }

    void printDateFormat2() const {
        // Array of month names
        const std::string monthNames[] = {"", "January", "February", "March", "April", "May", "June",
                                          "July", "August", "September", "October", "November", "December"};

        std::cout << monthNames[month] << " " << day << ", " << year << std::endl;
    }

    void printDateFormat3() const {
        // Array of month names
        const std::string monthNames[] = {"", "January", "February", "March", "April", "May", "June",
                                          "July", "August", "September", "October", "November", "December"};

        std::cout << day << " " << monthNames[month] << " " << year << std::endl;
    }
};

int main() {
    int inputMonth, inputDay, inputYear;

    // Get user input for the date
    std::cout << "Enter month (1-12): ";
    std::cin >> inputMonth;

    // Input validation for month
    while (inputMonth < 1 || inputMonth > 12) {
        std::cout << "Invalid month. Please enter a value between 1 and 12: ";
        std::cin >> inputMonth;
    }

    std::cout << "Enter day (1-31): ";
    std::cin >> inputDay;

    // Input validation for day
    while (inputDay < 1 || inputDay > 31) {
        std::cout << "Invalid day. Please enter a value between 1 and 31: ";
        std::cin >> inputDay;
    }

    std::cout << "Enter year: ";
    std::cin >> inputYear;

    // Create a Date object
    Date myDate(inputMonth, inputDay, inputYear);

    // Print the date in different formats
    std::cout << "\nDate in Format 1: ";
    myDate.printDateFormat1();

    std::cout << "\nDate in Format 2: ";
    myDate.printDateFormat2();

    std::cout << "\nDate in Format 3: ";
    myDate.printDateFormat3();

    return 0;
}
