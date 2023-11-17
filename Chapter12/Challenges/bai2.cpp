#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // for system("pause")

const int LINES_PER_PAGE = 24;

void displayFileContents(const std::string& fileName) {
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    std::string line;
    int lineCount = 0;

    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;

        // Increment line count
        ++lineCount;

        // Pause every LINES_PER_PAGE lines
        if (lineCount % LINES_PER_PAGE == 0) {
            std::cout << "Press Enter to continue...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear input buffer
            std::cin.get(); // wait for user to strike a key
        }
    }

    inputFile.close();
}

int main() {
    std::string fileName;

    // Get the file name from the user
    std::cout << "Enter the name of the file: ";
    std::getline(std::cin, fileName);

    // Display the contents of the file
    displayFileContents(fileName);

    return 0;
}
