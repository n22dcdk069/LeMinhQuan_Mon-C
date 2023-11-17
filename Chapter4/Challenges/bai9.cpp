#include <iostream>

int main() {
    // Constants representing the values of each coin
    const int PENNY_VALUE = 1;
    const int NICKEL_VALUE = 5;
    const int DIME_VALUE = 10;
    const int QUARTER_VALUE = 25;

    // Variables to store the number of each type of coin
    int pennies, nickels, dimes, quarters;

    // Get user input for the number of each coin
    std::cout << "Enter the number of pennies: ";
    std::cin >> pennies;

    std::cout << "Enter the number of nickels: ";
    std::cin >> nickels;

    std::cout << "Enter the number of dimes: ";
    std::cin >> dimes;

    std::cout << "Enter the number of quarters: ";
    std::cin >> quarters;

    // Calculate the total value in cents
    int totalCents = (pennies * PENNY_VALUE) + (nickels * NICKEL_VALUE) +
                     (dimes * DIME_VALUE) + (quarters * QUARTER_VALUE);

    // Check if the total value is equal to one dollar
    if (totalCents == 100) {
        std::cout << "Congratulations! You won the game!" << std::endl;
    } else {
        std::cout << "Sorry, the total amount is ";
        if (totalCents < 100) {
            std::cout << "less than one dollar." << std::endl;
        } else {
            std::cout << "more than one dollar." << std::endl;
        }
    }

    return 0;
}
