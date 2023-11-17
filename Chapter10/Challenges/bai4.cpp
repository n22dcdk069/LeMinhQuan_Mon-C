#include <iostream>
#include <cstring>

void wordCounter(const char* str, int& wordCount, int& letterCount) {
    wordCount = 0;
    letterCount = 0;

    // Iterate through the characters of the string
    for (int i = 0; str[i] != '\0'; ++i) {
        // Check if the current character is a letter
        if (std::isalpha(str[i])) {
            letterCount++;

            // Check if the next character is a non-letter, indicating the end of a word
            if (!std::isalpha(str[i + 1])) {
                wordCount++;
            }
        }
    }
}

int main() {
    const int MAX_LENGTH = 100;
    char input[MAX_LENGTH];

    // Ask the user to input a string
    std::cout << "Enter a string: ";
    std::cin.getline(input, MAX_LENGTH);

    int wordCount, letterCount;
    
    // Call the wordCounter function to count words and letters
    wordCounter(input, wordCount, letterCount);

    // Display the word count
    std::cout << "Word count: " << wordCount << std::endl;

    // Display the total number of letters
    std::cout << "Letter count: " << letterCount << std::endl;

    // Calculate and display the average number of letters per word
    if (wordCount > 0) {
        double averageLetters = static_cast<double>(letterCount) / wordCount;
        std::cout << "Average letters per word: " << averageLetters << std::endl;
    } else {
        std::cout << "No words to calculate average." << std::endl;
    }

    return 0;
}
