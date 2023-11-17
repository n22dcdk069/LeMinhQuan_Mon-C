#include <iostream>
#include <fstream>
#include <cctype> // For isupper, islower, isdigit

int main() {
    // Open the file
    std::ifstream inputFile("path/to/text.txt"); // Replace with the actual path

    // Check if the file is successfully opened
    if (!inputFile) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    char ch;
    int uppercaseCount = 0;
    int lowercaseCount = 0;
    int digitCount = 0;

    // Read each character from the file
    while (inputFile.get(ch)) {
        if (std::isupper(ch)) {
            uppercaseCount++;
        } else if (std::islower(ch)) {
            lowercaseCount++;
        } else if (std::isdigit(ch)) {
            digitCount++;
        }
    }

    // Close the file
    inputFile.close();

    // Display the results
    std::cout << "Uppercase letters: " << uppercaseCount << std::endl;
    std::cout << "Lowercase letters: " << lowercaseCount << std::endl;
    std::cout << "Digits: " << digitCount << std::endl;

    return 0;
}
