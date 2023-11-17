#include <iostream>
#include <cstring>

int main() {
    const int MAX_LENGTH = 100;
    char input[MAX_LENGTH];

    // Ask the user to enter a series of single-digit numbers
    std::cout << "Enter a series of single-digit numbers with no spaces: ";
    std::cin.getline(input, MAX_LENGTH);

    int sum = 0;
    char highestDigit = '0'; // Initialize to the smallest digit
    char lowestDigit = '9';  // Initialize to the largest digit

    // Calculate the sum, highest, and lowest digits
    for (int i = 0; input[i] != '\0'; ++i) {
        if (isdigit(input[i])) {
            int digit = input[i] - '0'; // Convert char to int

            // Update sum
            sum += digit;

            // Update highest and lowest digits
            if (input[i] > highestDigit) {
                highestDigit = input[i];
            }
            if (input[i] < lowestDigit) {
                lowestDigit = input[i];
            }
        } else {
            std::cout << "Invalid input. Please enter single-digit numbers only." << std::endl;
            return 1; // Exit the program with an error code
        }
    }

    // Display the results
    std::cout << "Sum of single-digit numbers: " << sum << std::endl;
    std::cout << "Highest digit: " << highestDigit << std::endl;
    std::cout << "Lowest digit: " << lowestDigit << std::endl;

    return 0;
}
