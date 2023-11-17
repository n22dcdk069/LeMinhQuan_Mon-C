#include <iostream>
#include <cctype>   // For std::toupper
#include <cstring>  // For C-string functions
#include <string>   // For std::string

// Function to capitalize the first character of each sentence in a C-string
void capitalizeSentences(char* str) {
    // Capitalize the first character of the string
    if (std::isalpha(*str)) {
        *str = std::toupper(*str);
    }

    // Iterate through the string
    while (*str != '\0') {
        // If the current character is a period, question mark, or exclamation mark,
        // and the next character is an alphabet character, capitalize it
        if ((*str == '.' || *str == '?' || *str == '!') && std::isalpha(*(str + 1))) {
            *(str + 1) = std::toupper(*(str + 1));
        }

        // Move to the next character
        str++;
    }
}

// Overloaded function for std::string
void capitalizeSentences(std::string& str) {
    // Use data() to get a pointer to the underlying C-string
    capitalizeSentences(&str[0]);
}

int main() {
    const int MAX_SIZE = 1000; // You can adjust the size based on your requirements
    char inputString[MAX_SIZE];

    // Get user input
    std::cout << "Enter a string: ";
    std::cin.getline(inputString, MAX_SIZE);

    // Call the function to capitalize sentences for C-string
    capitalizeSentences(inputString);

    // Display the modified string for C-string
    std::cout << "Modified string (C-string): " << inputString << std::endl;

    // Get user input for std::string
    std::string inputStdString;
    std::cout << "Enter a string (using std::string): ";
    std::getline(std::cin, inputStdString);

    // Call the function to capitalize sentences for std::string
    capitalizeSentences(inputStdString);

    // Display the modified string for std::string
    std::cout << "Modified string (std::string): " << inputStdString << std::endl;

    return 0;
}
