#include <iostream>
#include <cctype> // For isalpha and tolower functions

// Function to count vowels in a C-string
int countVowels(const char* str) {
    int vowelCount = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        char lowercaseChar = tolower(str[i]);

        // Check if the character is a vowel
        if (lowercaseChar == 'a' || lowercaseChar == 'e' || lowercaseChar == 'i' ||
            lowercaseChar == 'o' || lowercaseChar == 'u') {
            vowelCount++;
        }
    }

    return vowelCount;
}

// Function to count consonants in a C-string
int countConsonants(const char* str) {
    int consonantCount = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        char lowercaseChar = tolower(str[i]);

        // Check if the character is a consonant
        if (isalpha(lowercaseChar) && !(lowercaseChar == 'a' || lowercaseChar == 'e' ||
                                        lowercaseChar == 'i' || lowercaseChar == 'o' ||
                                        lowercaseChar == 'u')) {
            consonantCount++;
        }
    }

    return consonantCount;
}

int main() {
    const int MAX_LENGTH = 100;
    char input[MAX_LENGTH];

    // Menu-driven program
    while (true) {
        std::cout << "Enter a string: ";
        std::cin.getline(input, MAX_LENGTH);

        std::cout << "Menu:\n";
        std::cout << "A) Count the number of vowels in the string\n";
        std::cout << "B) Count the number of consonants in the string\n";
        std::cout << "C) Count both the vowels and consonants in the string\n";
        std::cout << "D) Enter another string\n";
        std::cout << "E) Exit the program\n";

        char choice;
        std::cout << "Enter your choice (A/B/C/D/E): ";
        std::cin >> choice;
        std::cin.ignore(); // Clear the newline character from the input buffer

        switch (toupper(choice)) {
            case 'A':
                std::cout << "Number of vowels: " << countVowels(input) << std::endl;
                break;
            case 'B':
                std::cout << "Number of consonants: " << countConsonants(input) << std::endl;
                break;
            case 'C':
                std::cout << "Number of vowels: " << countVowels(input) << std::endl;
                std::cout << "Number of consonants: " << countConsonants(input) << std::endl;
                break;
            case 'D':
                // Continue to the next iteration of the loop to enter another string
                continue;
            case 'E':
                // Exit the program
                std::cout << "Exiting the program. Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
