#include <iostream>
#include <fstream> // For file handling
#include <iomanip>

// Function prototypes for overloaded calculations
double calculateCharges(int days, double rate, double medCharges, double serviceCharges);
double calculateCharges(double medCharges, double serviceCharges);

// Function prototype for writing the report to a file
void writeReportToFile(std::ofstream &outfile, const char patientType, const int days, const double rate, const double medCharges, const double serviceCharges);

int main() {
    // Open the file for writing
    std::ofstream outfile("hospital_report.txt");
    
    // Input variables
    char patientType;
    int days;
    double rate, medCharges, serviceCharges;

    // Get input from the user
    std::cout << "Enter 'I' for in-patient or 'O' for out-patient: ";
    std::cin >> patientType;

    // Input validation: Ensure the input is either 'I' or 'O'
    while (toupper(patientType) != 'I' && toupper(patientType) != 'O') {
        std::cout << "Invalid input. Enter 'I' for in-patient or 'O' for out-patient: ";
        std::cin >> patientType;
    }

    if (toupper(patientType) == 'I') {
        // In-patient data
        std::cout << "Enter the number of days spent in the hospital: ";
        std::cin >> days;

        std::cout << "Enter the daily rate: $";
        std::cin >> rate;

        std::cout << "Enter hospital medication charges: $";
        std::cin >> medCharges;

        std::cout << "Enter charges for hospital services: $";
        std::cin >> serviceCharges;

        // Calculate and display total charges for in-patient
        double totalCharges = calculateCharges(days, rate, medCharges, serviceCharges);
        std::cout << "Total charges for in-patient: $" << totalCharges << std::endl;

        // Write the report to the file
        writeReportToFile(outfile, 'I', days, rate, medCharges, serviceCharges);
    } else {
        // Out-patient data
        std::cout << "Enter charges for hospital services (lab tests, etc.): $";
        std::cin >> serviceCharges;

        std::cout << "Enter hospital medication charges: $";
        std::cin >> medCharges;

        // Calculate and display total charges for out-patient
        double totalCharges = calculateCharges(medCharges, serviceCharges);
        std::cout << "Total charges for out-patient: $" << totalCharges << std::endl;

        // Write the report to the file
        writeReportToFile(outfile, 'O', 0, 0.0, medCharges, serviceCharges);
    }

    // Close the file
    outfile.close();

    return 0;
}

// Function definition for in-patient charges calculation
double calculateCharges(int days, double rate, double medCharges, double serviceCharges) {
    return days * rate + medCharges + serviceCharges;
}

// Function definition for out-patient charges calculation
double calculateCharges(double medCharges, double serviceCharges) {
    return medCharges + serviceCharges;
}

// Function definition for writing the report to a file
void writeReportToFile(std::ofstream &outfile, const char patientType, const int days, const double rate, const double medCharges, const double serviceCharges) {
    outfile << std::fixed << std::setprecision(2);

    if (patientType == 'I') {
        outfile << "Patient Type: In-Patient\n";
        outfile << "Number of Days: " << days << "\n";
        outfile << "Daily Rate: $" << rate << "\n";
        outfile << "Hospital Medication Charges: $" << medCharges << "\n";
        outfile << "Charges for Hospital Services: $" << serviceCharges << "\n";
    } else {
        outfile << "Patient Type: Out-Patient\n";
        outfile << "Hospital Medication Charges: $" << medCharges << "\n";
        outfile << "Charges for Hospital Services: $" << serviceCharges << "\n";
    }

    outfile << "Total Charges: $" << calculateCharges(days, rate, medCharges, serviceCharges) << "\n\n";
}
