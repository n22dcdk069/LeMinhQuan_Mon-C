#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    // Variables
    double angleInRadians, sineValue, cosineValue, tangentValue;

    // Input
    cout << "Enter an angle in radians: ";
    cin >> angleInRadians;

    // Calculate trigonometric values
    sineValue = sin(angleInRadians);
    cosineValue = cos(angleInRadians);
    tangentValue = tan(angleInRadians);

    // Display the result
    cout << fixed << setprecision(4);
    cout << "Sine: " << sineValue << endl;
    cout << "Cosine: " << cosineValue << endl;
    cout << "Tangent: " << tangentValue << endl;

    return 0;
}
