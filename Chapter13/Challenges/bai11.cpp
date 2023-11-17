#include <iostream>

class PayRoll {
private:
    double hourlyPayRate;
    double hoursWorked;
    double totalPay;

public:
    // Constructor
    PayRoll(double payRate = 0.0, double hours = 0.0) : hourlyPayRate(payRate), hoursWorked(hours), totalPay(0.0) {}

    // Mutator functions
    void setHourlyPayRate(double payRate) {
        hourlyPayRate = payRate;
    }

    void setHoursWorked(double hours) {
        // Input validation: Do not accept values greater than 60 for the number of hours worked
        if (hours > 60) {
            std::cerr << "Invalid input. Number of hours worked cannot be greater than 60.\n";
            exit(1); // Exit program with an error code
        }
        hoursWorked = hours;
    }

    // Accessor functions
    double getHourlyPayRate() const {
        return hourlyPayRate;
    }

    double getHoursWorked() const {
        return hoursWorked;
    }

    double getTotalPay() const {
        return totalPay;
    }

    // Member function to calculate total pay
    void calculateTotalPay() {
        totalPay = hourlyPayRate * hoursWorked;
    }
};

int main() {
    const int NUM_EMPLOYEES = 7;
    PayRoll payrollArray[NUM_EMPLOYEES];

    // Get input for each employee's hours worked
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        double hours;
        std::cout << "Enter hours worked for Employee " << i + 1 << ": ";
        std::cin >> hours;

        // Set hours worked for the PayRoll object
        payrollArray[i].setHoursWorked(hours);

        // Assume a fixed hourly pay rate for simplicity (you can modify this as needed)
        payrollArray[i].setHourlyPayRate(15.0);

        // Calculate total pay for the employee
        payrollArray[i].calculateTotalPay();
    }

    // Display the total pay for each employee
    std::cout << "\nTotal Pay for Each Employee:\n";
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        std::cout << "Employee " << i + 1 << ": $" << payrollArray[i].getTotalPay() << std::endl;
    }

    return 0;
}
