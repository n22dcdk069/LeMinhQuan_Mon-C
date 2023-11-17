#include <iostream>

const int numEmployees = 7;

int main() {
    // Arrays to hold employee information
    long empId[numEmployees] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};
    int hours[numEmployees];
    double payRate[numEmployees];
    double wages[numEmployees];

    // Input data for each employee
    for (int i = 0; i < numEmployees; ++i) {
        std::cout << "Enter hours worked by employee " << empId[i] << ": ";
        std::cin >> hours[i];

        // Input validation for hours
        while (hours[i] < 0) {
            std::cout << "Please enter a non-negative value for hours worked: ";
            std::cin >> hours[i];
        }

        std::cout << "Enter pay rate for employee " << empId[i] << ": ";
        std::cin >> payRate[i];

        // Input validation for pay rate
        while (payRate[i] < 15.00) {
            std::cout << "Please enter a pay rate greater than or equal to 15.00: ";
            std::cin >> payRate[i];
        }

        // Calculate gross wages
        wages[i] = hours[i] * payRate[i];
    }

    // Display employee identification number and gross wages
    std::cout << "\nEmployee Information:\n";
    std::cout << "---------------------\n";

    for (int i = 0; i < numEmployees; ++i) {
        std::cout << "Employee ID: " << empId[i] << "\tGross Wages: $" << wages[i] << std::endl;
    }

    return 0;
}
