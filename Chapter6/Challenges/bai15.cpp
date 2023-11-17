#include <iostream>

// Function prototype for in-patient charges calculation
double calculateTotalCharges(int days, double dailyRate, double medCharges, double serviceCharges);

// Function prototype for out-patient charges calculation
double calculateTotalCharges(double medCharges, double serviceCharges);

int main() {
    char patientType;

    // Ask if the patient is an in-patient or an out-patient
    std::cout << "Enter 'I' for in-patient or 'O' for out-patient: ";
    std::cin >> patientType;

    // Input validation: Ensure the input is either 'I' or 'O'
    while (toupper(patientType) != 'I' && toupper(patientType) != 'O') {
        std::cout << "Invalid input. Enter 'I' for in-patient or 'O' for out-patient: ";
        std::cin >> patientType;
    }

    if (toupper(patientType) == 'I') {
        // In-patient data
        int days;
        double dailyRate, medCharges, serviceCharges;

        // Get in-patient data
        std::cout << "Enter the number of days spent in the hospital: ";
        std::cin >> days;

        // Input validation: Do not accept negative numbers for any data
        while (days < 0) {
            std::cout << "Invalid input. Please enter a non-negative number of days: ";
            std::cin >> days;
        }

        std::cout << "Enter the daily rate: $";
        std::cin >> dailyRate;

        while (dailyRate < 0) {
            std::cout << "Invalid input. Please enter a non-negative daily rate: $";
            std::cin >> dailyRate;
        }

        std::cout << "Enter hospital medication charges: $";
        std::cin >> medCharges;

        while (medCharges < 0) {
            std::cout << "Invalid input. Please enter non-negative hospital medication charges: $";
            std::cin >> medCharges;
        }

        std::cout << "Enter charges for hospital services: $";
        std::cin >> serviceCharges;

        while (serviceCharges < 0) {
            std::cout << "Invalid input. Please enter non-negative charges for hospital services: $";
            std::cin >> serviceCharges;
        }

        // Calculate and display total charges for in-patient
        double totalCharges = calculateTotalCharges(days, dailyRate, medCharges, serviceCharges);
        std::cout << "Total charges for in-patient: $" << totalCharges << std::endl;
    } else {
        // Out-patient data
        double medCharges, serviceCharges;

        // Get out-patient data
        std::cout << "Enter charges for hospital services (lab tests, etc.): $";
        std::cin >> serviceCharges;

        while (serviceCharges < 0) {
            std::cout << "Invalid input. Please enter non-negative charges for hospital services: $";
            std::cin >> serviceCharges;
        }

        std::cout << "Enter hospital medication charges: $";
        std::cin >> medCharges;

        while (medCharges < 0) {
            std::cout << "Invalid input. Please enter non-negative hospital medication charges: $";
            std::cin >> medCharges;
        }

        // Calculate and display total charges for out-patient
        double totalCharges = calculateTotalCharges(medCharges, serviceCharges);
        std::cout << "Total charges for out-patient: $" << totalCharges << std::endl;
    }

    return 0;
}

// Function definition for in-patient charges calculation
double calculateTotalCharges(int days, double dailyRate, double medCharges, double serviceCharges) {
    return days * dailyRate + medCharges + serviceCharges;
}

// Function definition for out-patient charges calculation
double calculateTotalCharges(double medCharges, double serviceCharges) {
    return medCharges + serviceCharges;
}
