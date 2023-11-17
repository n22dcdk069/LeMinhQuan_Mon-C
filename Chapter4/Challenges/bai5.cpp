#include <iostream>
#include <cmath>

int main() {
    // Get user input for weight and height
    double weight, height;

    std::cout << "Enter weight in pounds: ";
    std::cin >> weight;

    std::cout << "Enter height in inches: ";
    std::cin >> height;

    // Calculate BMI using the formula
    double bmi = (weight * 703) / pow(height, 2);

    // Display the calculated BMI
    std::cout << "BMI: " << bmi << std::endl;

    // Determine the weight category
    if (bmi >= 18.5 && bmi <= 25) {
        std::cout << "Optimal weight" << std::endl;
    } else if (bmi < 18.5) {
        std::cout << "Underweight" << std::endl;
    } else {
        std::cout << "Overweight" << std::endl;
    }

    return 0;
}
