#include <iostream>
#include <map>
#include <sstream>
#include <cctype> // For isalnum

// Morse code table
std::map<char, std::string> morseCodeTable = {
    {' ', " "},    {',', "--..--"}, {'.', ".-.-.-"},
    {'?', "..--.."}, {'0', "-----"},  {'1', ".----"},
    {'2', "..---"},  {'3', "...--"},  {'4', "....-"},
    {'5', "....."},  {'6', "-...."},  {'7', "--..."},
    {'8', "---.."},  {'9', "----."},  {'A', ".-"},
    {'B', "-..."},   {'C', "-.-."},   {'D', "-.."},
    {'E', "."},      {'F', "..-."},   {'G', "--."},
    {'H', "...."},   {'I', ".."},     {'J', ".---"},
    {'K', "-.-"},    {'L', ".-.."},   {'M', "--"},
    {'N', "-."},     {'O', "---"},    {'P', ".--."},
    {'Q', "--.-"},   {'R', ".-."},    {'S', "..."},
    {'T', "-"},      {'U', "..-"},    {'V', "...-"},
    {'W', ".--"},    {'X', "-..-"},   {'Y', "-.--"},
    {'Z', "--.."}
};

// Function to convert a string to Morse code
std::string stringToMorse(const std::string& input) {
    std::stringstream morseCode;

    for (char ch : input) {
        // Convert to uppercase and check if the character is alphanumeric or a space
        ch = std::toupper(ch);
        if (std::isalnum(ch) || ch == ' ') {
            morseCode << morseCodeTable[ch] << " ";
        }
    }

    return morseCode.str();
}

int main() {
    // Get user input
    std::cout << "Enter a string: ";
    std::string userInput;
    std::getline(std::cin, userInput);

    // Convert the string to Morse code
    std::string morseResult = stringToMorse(userInput);

    // Display the Morse code
    std::cout << "Morse Code: " << morseResult << std::endl;

    return 0;
}
