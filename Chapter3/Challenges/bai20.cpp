#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Constants
    const double sliceArea = 14.125; // Area of each slice in square inches

    // Variables
    double diameter, radius, pizzaArea;
    int numberOfSlices;

    // Input
    cout << "Enter the diameter of the pizza in inches: ";
    cin >> diameter;

    // Calculate radius
    radius = diameter / 2.0;

    // Calculate the area of the pizza
    pizzaArea = M_PI * pow(radius, 2);

    // Calculate the number of slices
    numberOfSlices = static_cast<int>(pizzaArea / sliceArea);

    // Display the result
    cout << "Number of slices: " << numberOfSlices << endl;

    return 0;
}
