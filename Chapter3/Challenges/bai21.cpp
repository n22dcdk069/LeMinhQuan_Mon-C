#include <iostream>
#include <cmath>

int main() {
    const double PI = 3.14159;
    const int SLICES_PER_PERSON = 4;

    // Variables
    int numPeople;
    double pizzaDiameter;

    // Get user input
    std::cout << "Enter the number of people at the party: ";
    std::cin >> numPeople;

    std::cout << "Enter the diameter of the pizzas to be ordered (in inches): ";
    std::cin >> pizzaDiameter;

    // Calculate the number of slices in a pizza
    double pizzaRadius = pizzaDiameter / 2.0;
    double pizzaArea = PI * std::pow(pizzaRadius, 2);
    int slicesPerPizza = static_cast<int>(pizzaArea) / SLICES_PER_PERSON;

    // Calculate the number of pizzas needed
    int totalSlicesNeeded = numPeople * SLICES_PER_PERSON;
    int numPizzas = totalSlicesNeeded / slicesPerPizza;

    // Display the result
    std::cout << "You need to buy " << numPizzas << " pizzas for the party.\n";

    return 0;
}
