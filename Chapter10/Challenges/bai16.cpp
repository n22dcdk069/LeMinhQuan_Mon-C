#include <iostream>
#include <sstream>
#include <string>
#include <cctype> // For isalpha function

// Function to convert a word to Pig Latin
std::string convertToPigLatin(const std::string& word) {
    if (word.empty()) {
        return "";
    }

    char firstLetter = std::tolower(word[0]); // Convert the first letter to lowercase
    std::string restOfWord = word.substr(1); // Get the rest of the word

    return firstLetter + restOfWord + "ay";
}

int main() {
    std::cout << "Enter a sentence: ";
    std::string input;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    std::string word;
    std::string pigLatinSentence;

    while (ss >> word) {
        // Check if the word contains alphabetic characters
        if (std::any_of(word.begin(), word.end(), [](char c) { return std::isalpha(c); })) {
            pigLatinSentence += convertToPigLatin(word) + " ";
        } else {
            // If the word doesn't contain alphabetic characters, keep it unchanged
            pigLatinSentence += word + " ";
        }
    }

    std::cout << "Pig Latin: " << pigLatinSentence << std::endl;

    return 0;
}
