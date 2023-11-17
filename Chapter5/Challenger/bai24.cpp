#include <iostream>
#include <fstream>

int main() {
    // Open the file
    std::ifstream inputFile("Random.txt");

    // Check if the file is successfully opened
    if (!inputFile) {
        std::cerr << "Error opening the file. Make sure the file exists and is accessible.\n";
        return 1; // Exit with an error code
    }

    // Variables for calculations
    int number;
    int numberOfNumbers = 0;
    int sum = 0;

    // Read numbers from the file and perform calculations
    while (inputFile >> number) {
        numberOfNumbers++;
        sum += number;
    }

    // Close the file
    inputFile.close();

    // Calculate average
    double average = static_cast<double>(sum) / numberOfNumbers;

    // Display results
    std::cout << "Number of numbers in the file: " << numberOfNumbers << std::endl;
    std::cout << "Sum of the numbers: " << sum << std::endl;
    std::cout << "Average of the numbers: " << average << std::endl;

    return 0;
}
