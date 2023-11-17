#include <iostream>

// Function to count characters in a C-string
int countCharacters(const char* str) {
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

int main() {
    const int MAX_SIZE = 100;  // You can adjust the size based on your requirements
    char inputString[MAX_SIZE];

    // Get user input
    std::cout << "Enter a string: ";
    std::cin.getline(inputString, MAX_SIZE);

    // Call the function to count characters
    int charCount = countCharacters(inputString);

    // Display the result
    std::cout << "Number of characters: " << charCount << std::endl;

    return 0;
}
