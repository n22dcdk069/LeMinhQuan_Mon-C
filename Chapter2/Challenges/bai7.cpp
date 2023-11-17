#include <iostream>

int main() {
    // Define the rate of ocean level rise (in millimeters per year)
    double riseRate = 1.5;

    // Calculate the ocean level rise for different years
    int years5 = 5;
    int years7 = 7;
    int years10 = 10;

    double rise5 = riseRate * years5;
    double rise7 = riseRate * years7;
    double rise10 = riseRate * years10;

    // Display the results
    std::cout << "In " << years5 << " years, the ocean's level will be " << rise5 << " millimeters higher than the current level." << std::endl;
    std::cout << "In " << years7 << " years, the ocean's level will be " << rise7 << " millimeters higher than the current level." << std::endl;
    std::cout << "In " << years10 << " years, the ocean's level will be " << rise10 << " millimeters higher than the current level." << std::endl;

    return 0;
}
