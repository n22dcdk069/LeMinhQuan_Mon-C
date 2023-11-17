#include <iostream>

int main() {
    // Constants
    const int cookiesPerBag = 30;
    const int servingsPerBag = 10;
    const int caloriesPerServing = 300;

    // Get user input
    int cookiesEaten;
    std::cout << "Enter the number of cookies you ate: ";
    std::cin >> cookiesEaten;

    // Calculate total calories consumed
    double caloriesConsumed = (static_cast<double>(cookiesEaten) / cookiesPerBag) * servingsPerBag * caloriesPerServing;

    // Display the result
    std::cout << "You consumed " << caloriesConsumed << " calories.\n";

    return 0;
}
