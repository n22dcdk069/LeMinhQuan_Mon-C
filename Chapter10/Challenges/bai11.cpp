#include <iostream>
#include <cstring> // For C-string functions

// Function to convert each character in a C-string to uppercase
void upper(char* str) {
    while (*str != '\0') {
        *str = std::toupper(*str);
        str++;
    }
}

// Function to convert each character in a C-string to lowercase
void lower(char* str) {
    while (*str != '\0') {
        *str = std::tolower(*str);
        str++;
    }
}

// Function to reverse the case of each character in a C-string
void reverse(char* str) {
    while (*str != '\0') {
        if (std::isupper(*str)) {
            *str = std::tolower(*str);
        } else if (std::islower(*str)) {
            *str = std::toupper(*str);
        }
        str++;
    }
}

int main() {
    const int MAX_SIZE = 100; // You can adjust the size based on your requirements
    char inputString[MAX_SIZE];

    // Get user input
    std::cout << "Enter a string: ";
    std::cin.getline(inputString, MAX_SIZE);

    // Test the functions in the specified order: reverse, lower, and upper
    reverse(inputString);
    std::cout << "After reversing the case: " << inputString << std::endl;

    lower(inputString);
    std::cout << "After converting to lowercase: " << inputString << std::endl;

    upper(inputString);
    std::cout << "After converting to uppercase: " << inputString << std::endl;

    return 0;
}
