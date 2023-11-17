#include <iostream>
using namespace std;

int main() {
    // Constants representing the amounts of ingredients for 48 cookies
    const double SUGAR_PER_COOKIE = 1.5 / 48.0;
    const double BUTTER_PER_COOKIE = 1.0 / 48.0;
    const double FLOUR_PER_COOKIE = 2.75 / 48.0;

    // Variables to store the user input and calculated amounts
    int numCookies;
    double sugarAmount, butterAmount, flourAmount;

    // Get user input for the number of cookies to make
    cout << "Enter the number of cookies you want to make: ";
    cin >> numCookies;

    // Calculate the amounts of each ingredient based on the user input
    sugarAmount = SUGAR_PER_COOKIE * numCookies;
    butterAmount = BUTTER_PER_COOKIE * numCookies;
    flourAmount = FLOUR_PER_COOKIE * numCookies;

    // Display the amounts of each ingredient
    cout << "To make " << numCookies << " cookies, you'll need:\n";
    cout << "Sugar: " << sugarAmount << " cups\n";
    cout << "Butter: " << butterAmount << " cups\n";
    cout << "Flour: " << flourAmount << " cups\n";

    return 0;
}
