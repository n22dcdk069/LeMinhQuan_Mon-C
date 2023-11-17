#include <iostream>

int main() {
    int number;
    int smallest, largest;
    bool firstNumber = true;

    // Prompt the user to enter integers until -99 is entered
    std::cout << "Enter a series of integers (-99 to end):" << std::endl;

    do {
        std::cout << "Enter an integer: ";
        std::cin >> number;

        // Check if -99 is entered to end the series
        if (number == -99) {
            break;
        }

        // Update smallest and largest based on user input
        if (firstNumber) {
            smallest = largest = number;
            firstNumber = false;
        } else {
            if (number < smallest) {
                smallest = number;
            } else if (number > largest) {
                largest = number;
            }
        }

    } while (true);

    // Display the results
    if (!firstNumber) {
        std::cout << "\nResults:\n"
                  << "Smallest number: " << smallest << "\n"
                  << "Largest number: " << largest << std::endl;
    } else {
        std::cout << "No numbers were entered." << std::endl;
    }

    return 0;
}
