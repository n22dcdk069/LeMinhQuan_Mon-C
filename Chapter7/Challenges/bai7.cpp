#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    // Prompt user for a file name
    std::string fileName;
    std::cout << "Enter the name of the file: ";
    std::cin >> fileName;

    // Open the file
    std::ifstream inputFile(fileName);

    // Check if the file is opened successfully
    if (!inputFile) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    // Read numbers from the file into a vector
    std::vector<double> numbers;
    double number;

    while (inputFile >> number) {
        numbers.push_back(number);
    }

    // Close the file
    inputFile.close();

    // Check if the file is empty
    if (numbers.empty()) {
        std::cout << "No numbers found in the file.\n";
        return 0;
    }

    // Display the results
    std::cout << "Lowest number: " << *std::min_element(numbers.begin(), numbers.end()) << std::endl;
    std::cout << "Highest number: " << *std::max_element(numbers.begin(), numbers.end()) << std::endl;
    std::cout << "Total: " << std::accumulate(numbers.begin(), numbers.end(), 0.0) << std::endl;
    std::cout << "Average: " << std::accumulate(numbers.begin(), numbers.end(), 0.0) / numbers.size() << std::endl;

    return 0;
}
