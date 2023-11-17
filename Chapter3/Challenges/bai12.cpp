#include <iostream>
using namespace std;

int main() {
    // Variables
    double celsius, fahrenheit;

    // Input
    cout << "Enter the temperature in Celsius: ";
    cin >> celsius;

    // Convert Celsius to Fahrenheit
    fahrenheit = (9.0 / 5.0) * celsius + 32;

    // Display the result
    cout << "Temperature in Fahrenheit: " << fahrenheit << " degrees" << endl;

    return 0;
}
