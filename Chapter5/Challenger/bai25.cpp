#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("LineUp.txt");

    if (!inputFile) {
        std::cerr << "Error opening the file LineUp.txt\n";
        return 1; // Return an error code
    }

    std::string studentName;

    std::cout << "Student Line Up:\n";

    // Read names from the file until there is no more data
    while (getline(inputFile, studentName)) {
        std::cout << studentName << "\n";
    }

    inputFile.close(); // Close the file

    return 0;
}
