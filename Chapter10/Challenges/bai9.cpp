#include <iostream>
#include <cstring> // For C-string functions
#include <string>  // For std::string

char mostFrequentCharacter(const char* str) {
    if (str == nullptr || *str == '\0') {
        // Handle empty string or null pointer
        return '\0';
    }

    int charCount[256] = {0}; // Assuming ASCII characters, adjust for other character sets

    // Count occurrences of each character
    while (*str != '\0') {
        charCount[static_cast<unsigned char>(*str)]++;
        str++;
    }

    // Find the most frequent character
    char mostFrequent = '\0';
    int maxCount = 0;

    for (int i = 0; i < 256; i++) {
        if (charCount[i] > maxCount) {
            maxCount = charCount[i];
            mostFrequent = static_cast<char>(i);
        }
    }

    return mostFrequent;
}

char mostFrequentCharacter(const std::string& str) {
    return mostFrequentCharacter(str.c_str());
}

int main() {
    const int MAX_SIZE = 1000; // You can adjust the size based on your requirements
    char inputCString[MAX_SIZE];

    // Get user input for C-string
    std::cout << "Enter a string (C-string): ";
    std::cin.getline(inputCString, MAX_SIZE);

    // Call the function to find the most frequent character for C-string
    char mostFrequentCharCString = mostFrequentCharacter(inputCString);

    // Display the result for C-string
    std::cout << "Most frequent character (C-string): " << mostFrequentCharCString << std::endl;

    // Get user input for std::string
    std::string inputStdString;
    std::cout << "Enter a string (using std::string): ";
    std::getline(std::cin, inputStdString);

    // Call the function to find the most frequent character for std::string
    char mostFrequentCharStdString = mostFrequentCharacter(inputStdString);

    // Display the result for std::string
    std::cout << "Most frequent character (std::string): " << mostFrequentCharStdString << std::endl;

    return 0;
}
