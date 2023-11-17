#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    // Open the file
    std::ifstream inputFile("People.txt");

    // Check if the file is successfully opened
    if (!inputFile) {
        std::cerr << "Error opening the file. Make sure the file exists and is accessible.\n";
        return 1; // Exit with an error code
    }

    // Display chart header
    std::cout << "PRAIRIEVILLE POPULATION GROWTH\n";
    std::cout << "(each * represents 1,000 people)\n";

    // Read and display population data
    int year, population;

    while (inputFile >> year >> population) {
        // Display the year
        std::cout << year << " ";

        // Display asterisks for each 1,000 people
        for (int i = 0; i < population / 1000; ++i) {
            std::cout << '*';
        }

        // Move to the next line for the next year
        std::cout << std::endl;
    }

    // Close the file
    inputFile.close();

    return 0;
}
