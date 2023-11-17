#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string fileName;
    std::string searchString;

    // Get the file name from the user
    std::cout << "Enter the name of the file: ";
    std::getline(std::cin, fileName);

    // Get the string to search for
    std::cout << "Enter the string to search for: ";
    std::getline(std::cin, searchString);

    std::ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return 1; // Exit with an error code
    }

    std::string line;
    int occurrences = 0;

    // Search for occurrences of the specified string
    while (std::getline(inputFile, line)) {
        size_t found = line.find(searchString);
        if (found != std::string::npos) {
            // Display the line containing the string
            std::cout << "Line: " << line << std::endl;
            occurrences++;
        }
    }

    inputFile.close();

    // Report the number of occurrences
    std::cout << "The string '" << searchString << "' appeared " << occurrences << " times in the file." << std::endl;

    return 0;
}