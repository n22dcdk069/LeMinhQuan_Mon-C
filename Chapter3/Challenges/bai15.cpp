#include <iostream>
#include <iomanip>

int main() {
    // Constants
    const double ASSESSMENT_PERCENTAGE = 0.60;
    const double TAX_RATE = 0.75;

    // Variables
    double actualValue;

    // Get user input for the actual value of the property
    std::cout << "Enter the actual value of the property: $";
    std::cin >> actualValue;

    // Calculate the assessment value
    double assessmentValue = actualValue * ASSESSMENT_PERCENTAGE;

    // Calculate the property tax
    double propertyTax = (assessmentValue / 100.0) * TAX_RATE;

    // Display the results
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nAssessment Value: $" << assessmentValue << "\n";
    std::cout << "Property Tax: $" << propertyTax << "\n";

    return 0;
}
