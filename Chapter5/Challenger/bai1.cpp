#include <iostream>

int main() {
    int userInput;

    // Get a positive integer from the user
    do {
        std::cout << "Enter a positive integer: ";
        std::cin >> userInput;

        if (userInput <= 0) {
            std::cout << "Please enter a positive integer.\n";
        }
    } while (userInput <= 0);

    // Calculate the sum using a loop
    int sum = 0;
    for (int i = 1; i <= userInput; ++i) {
        sum += i;
    }

    // Display the result
    std::cout << "The sum of integers from 1 to " << userInput << " is: " << sum << std::endl;

    return 0;
}
