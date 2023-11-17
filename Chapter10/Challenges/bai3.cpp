#include <iostream>
#include <cstring> // For C-string functions
#include <string>  // For std::string

// Function to count words in a C-string
int countWords(const char* str) {
    int wordCount = 0;
    bool inWord = false;

    while (*str != '\0') {
        if (std::isspace(*str)) {
            // If the current character is a space, set inWord to false
            inWord = false;
        } else if (!inWord) {
            // If the current character is not a space and inWord is false,
            // it means a new word is starting
            inWord = true;
            wordCount++;
        }

        str++; // Move to the next character
    }

    return wordCount;
}

// Overloaded function for std::string
int countWords(const std::string& str) {
    // Use c_str() to get a pointer to the underlying C-string
    return countWords(str.c_str());
}

int main() {
    const int MAX_SIZE = 100; // You can adjust the size based on your requirements
    char inputString[MAX_SIZE];

    // Get user input
    std::cout << "Enter a string: ";
    std::cin.getline(inputString, MAX_SIZE);

    // Call the function to count words for C-string
    int wordCountCString = countWords(inputString);

    // Display the result for C-string
    std::cout << "Number of words (C-string): " << wordCountCString << std::endl;

    // Get user input for std::string
    std::string inputStdString;
    std::cout << "Enter a string (using std::string): ";
    std::getline(std::cin, inputStdString);

    // Call the function to count words for std::string
    int wordCountStdString = countWords(inputStdString);

    // Display the result for std::string
    std::cout << "Number of words (std::string): " << wordCountStdString << std::endl;

    return 0;
}
