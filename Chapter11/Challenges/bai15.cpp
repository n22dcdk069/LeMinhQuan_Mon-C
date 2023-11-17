#include <iostream>
#include <limits>

// Define structures for hourly paid worker and salaried worker
struct HourlyPaid {
    double hoursWorked;
    double hourlyRate;
};

struct Salaried {
    double salary;
    double bonus;
};

// Define a union with two members, one for each type of worker
union WorkerData {
    HourlyPaid hourlyWorker;
    Salaried salariedWorker;
};

// Function prototypes
void getHourlyPaidData(HourlyPaid& hourlyData);
void getSalariedData(Salaried& salariedData);
double calculateHourlyPay(const HourlyPaid& hourlyData);
double calculateSalariedPay(const Salaried& salariedData);

int main() {
    WorkerData worker;

    // Ask the user whether to calculate pay for an hourly paid worker or a salaried worker
    char workerType;
    std::cout << "Enter 'H' for Hourly Paid worker or 'S' for Salaried worker: ";
    std::cin >> workerType;

    while (workerType != 'H' && workerType != 'S') {
        std::cout << "Invalid choice. Enter 'H' for Hourly Paid worker or 'S' for Salaried worker: ";
        std::cin >> workerType;
    }

    // Get data based on the selected worker type
    if (workerType == 'H') {
        getHourlyPaidData(worker.hourlyWorker);
    } else {
        getSalariedData(worker.salariedWorker);
    }

    // Calculate and display the pay
    double pay;
    if (workerType == 'H') {
        pay = calculateHourlyPay(worker.hourlyWorker);
    } else {
        pay = calculateSalariedPay(worker.salariedWorker);
    }

    std::cout << "The calculated pay is: $" << pay << std::endl;

    return 0;
}

void getHourlyPaidData(HourlyPaid& hourlyData) {
    std::cout << "Enter the number of hours worked (0-80): ";
    std::cin >> hourlyData.hoursWorked;

    while (std::cin.fail() || hourlyData.hoursWorked < 0 || hourlyData.hoursWorked > 80) {
        std::cin.clear(); // Clear input buffer to restore cin to a usable state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore last input
        std::cout << "Invalid input. Enter the number of hours worked (0-80): ";
        std::cin >> hourlyData.hoursWorked;
    }

    std::cout << "Enter the hourly pay rate: $";
    std::cin >> hourlyData.hourlyRate;

    while (std::cin.fail() || hourlyData.hourlyRate < 0) {
        std::cin.clear(); // Clear input buffer to restore cin to a usable state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore last input
        std::cout << "Invalid input. Enter a non-negative hourly pay rate: $";
        std::cin >> hourlyData.hourlyRate;
    }
}

void getSalariedData(Salaried& salariedData) {
    std::cout << "Enter the monthly salary: $";
    std::cin >> salariedData.salary;

    while (std::cin.fail() || salariedData.salary < 0) {
        std::cin.clear(); // Clear input buffer to restore cin to a usable state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore last input
        std::cout << "Invalid input. Enter a non-negative monthly salary: $";
        std::cin >> salariedData.salary;
    }

    std::cout << "Enter the bonus amount: $";
    std::cin >> salariedData.bonus;

    while (std::cin.fail() || salariedData.bonus < 0) {
        std::cin.clear(); // Clear input buffer to restore cin to a usable state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore last input
        std::cout << "Invalid input. Enter a non-negative bonus amount: $";
        std::cin >> salariedData.bonus;
    }
}

double calculateHourlyPay(const HourlyPaid& hourlyData) {
    return hourlyData.hoursWorked * hourlyData.hourlyRate;
}

double calculateSalariedPay(const Salaried& salariedData) {
    return salariedData.salary + salariedData.bonus;
}
