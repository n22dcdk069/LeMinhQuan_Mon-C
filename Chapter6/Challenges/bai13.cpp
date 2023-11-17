#include <iostream>

// Function to get the number of employees
int getNumberOfEmployees() {
    int numEmployees;

    do {
        std::cout << "Enter the number of employees in the company: ";
        std::cin >> numEmployees;

        // Input validation: Do not accept a number less than 1
        if (numEmployees < 1) {
            std::cout << "Invalid input. Number of employees must be at least 1.\n";
        }
    } while (numEmployees < 1);

    return numEmployees;
}

// Function to get the total number of days absent for all employees
int getTotalDaysAbsent(int numEmployees) {
    int totalDaysAbsent = 0;

    for (int i = 1; i <= numEmployees; ++i) {
        int daysAbsent;

        // Input validation: Do not accept a negative number for the days any employee missed
        do {
            std::cout << "Enter the number of days employee " << i << " missed during the past year: ";
            std::cin >> daysAbsent;

            if (daysAbsent < 0) {
                std::cout << "Invalid input. Days absent must be a non-negative number.\n";
            }
        } while (daysAbsent < 0);

        totalDaysAbsent += daysAbsent;
    }

    return totalDaysAbsent;
}

// Function to calculate the average number of days absent
double calculateAverageDaysAbsent(int numEmployees, int totalDaysAbsent) {
    // Calculate the average
    return static_cast<double>(totalDaysAbsent) / numEmployees;
}

int main() {
    // Get the number of employees
    int numEmployees = getNumberOfEmployees();

    // Get the total number of days absent for all employees
    int totalDaysAbsent = getTotalDaysAbsent(numEmployees);

    // Calculate and display the average number of days absent
    double averageDaysAbsent = calculateAverageDaysAbsent(numEmployees, totalDaysAbsent);

    std::cout << "The average number of days absent for employees is: " << averageDaysAbsent << std::endl;

    return 0;
}
