#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

const int LINES_PER_SCREEN = 24;

// Function prototype
void displayFileContents(const std::string& fileName);

int main() {
    std::string fileName;

    // Ask the user for the name of a file
    std::cout << "Enter the name of the file: ";
    std::cin >> fileName;

    // Display the contents of the file
    displayFileContents(fileName);

    return 0;
}

// Function to display the contents of the file
void displayFileContents(const std::string& fileName) {
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Error opening the file. Exiting program.\n";
        exit(1); // Return an error code
    }

    std::string line;
    int lineNumber = 1;

    while (std::getline(file, line)) {
        std::cout << lineNumber << ":" << line << std::endl;

        // Pause after displaying LINES_PER_SCREEN lines
        if (lineNumber % LINES_PER_SCREEN == 0) {
            std::cout << "\nPress Enter to continue...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        lineNumber++;
    }

    file.close();
}
