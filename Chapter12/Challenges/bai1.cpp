#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string fileName;

    // Ask the user for the name of a file
    std::cout << "Enter the name of the file: ";
    std::cin >> fileName;

    // Open the file
    std::ifstream file(fileName);

    // Check if the file is successfully opened
    if (!file.is_open()) {
        std::cerr << "Error opening the file. Exiting program.\n";
        return 1; // Return an error code
    }

    // Display the first 10 lines of the file
    std::cout << "\nThe first 10 lines of the file:\n";
    std::string line;
    int lineCount = 0;

    while (std::getline(file, line) && lineCount < 10) {
        std::cout << line << std::endl;
        lineCount++;
    }

    // Check if the file has fewer than 10 lines
    if (lineCount < 10) {
        std::cout << "\nThe entire file has been displayed.\n";
    }

    // Close the file
    file.close();

    return 0;
}
