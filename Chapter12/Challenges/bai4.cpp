#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int LINES_TO_DISPLAY = 10;

void displayTailOfFile(const std::string& fileName) {
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;

    // Read all lines from the file and store them in a vector
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }

    inputFile.close();

    int totalLines = lines.size();

    if (totalLines <= LINES_TO_DISPLAY) {
        // Display the entire file
        for (const auto& line : lines) {
            std::cout << line << std::endl;
        }
        std::cout << "Entire file has been displayed." << std::endl;
    } else {
        // Display the last LINES_TO_DISPLAY lines
        std::cout << "Displaying the last " << LINES_TO_DISPLAY << " lines of the file:" << std::endl;
        for (int i = totalLines - LINES_TO_DISPLAY; i < totalLines; ++i) {
            std::cout << lines[i] << std::endl;
        }
    }
}

int main() {
    std::string fileName;

    // Get the file name from the user
    std::cout << "Enter the name of the file: ";
    std::getline(std::cin, fileName);

    // Display the last 10 lines (or entire file if fewer than 10)
    displayTailOfFile(fileName);

    return 0;
}
