#include <iostream>
#include <fstream>
#include <cctype>

// Function prototype
void processFile(const std::string& inputFile, const std::string& outputFile);

int main() {
    std::string inputFileName, outputFileName;

    // Ask the user for the input file name
    std::cout << "Enter the name of the input file: ";
    std::cin >> inputFileName;

    // Ask the user for the output file name
    std::cout << "Enter the name of the output file: ";
    std::cin >> outputFileName;

    // Process the files
    processFile(inputFileName, outputFileName);

    std::cout << "File processing complete.\n";

    return 0;
}

// Function to process the files and perform the required changes
void processFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Error opening files. Exiting program.\n";
        exit(1); // Return an error code
    }

    char ch;
    bool newSentence = true; // Flag to track the start of a new sentence

    while (inFile.get(ch)) {
        if (newSentence && std::isalpha(ch)) {
            // Convert the first letter of the sentence to uppercase
            ch = std::toupper(ch);
            newSentence = false;
        } else if (ch == '.') {
            // Set the flag for the start of a new sentence
            newSentence = true;
        }

        // Convert the letter to lowercase
        ch = std::tolower(ch);

        // Write the character to the output file
        outFile.put(ch);
    }

    inFile.close();
    outFile.close();
}
