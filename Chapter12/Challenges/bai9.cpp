#include <iostream>
#include <fstream>

// Function prototype
void encryptFile(const std::string& inputFile, const std::string& outputFile);

int main() {
    std::string inputFileName, outputFileName;

    // Ask the user for the input file name
    std::cout << "Enter the name of the input file: ";
    std::cin >> inputFileName;

    // Ask the user for the output file name
    std::cout << "Enter the name of the output file (encrypted): ";
    std::cin >> outputFileName;

    // Encrypt the files
    encryptFile(inputFileName, outputFileName);

    std::cout << "Encryption complete.\n";

    return 0;
}

// Function to encrypt the contents of a file and write to another file
void encryptFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Error opening files. Exiting program.\n";
        exit(1); // Return an error code
    }

    char ch;

    while (inFile.get(ch)) {
        // Apply basic encryption by adding 10 to the ASCII code of each character
        ch = static_cast<char>(ch + 10);

        // Write the encrypted character to the output file
        outFile.put(ch);
    }

    inFile.close();
    outFile.close();
}
