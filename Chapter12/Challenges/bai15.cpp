#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

int main() {
    // Open the file for reading
    std::ifstream inFile("text.txt");

    if (!inFile.is_open()) {
        std::cerr << "Error opening the file. Exiting program.\n";
        return 1; // Return an error code
    }

    int totalWords = 0;
    int totalSentences = 0;
    std::string line;

    // Read each line from the file
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string word;

        // Count the number of words in the current line
        while (iss >> word) {
            totalWords++;
        }

        // Increment the total number of sentences
        totalSentences++;
    }

    // Close the file
    inFile.close();

    // Calculate the average number of words per sentence
    double averageWordsPerSentence = 0.0;

    if (totalSentences != 0) {
        averageWordsPerSentence = static_cast<double>(totalWords) / totalSentences;
    }

    // Display the result
    std::cout << "Total sentences: " << totalSentences << std::endl;
    std::cout << "Total words: " << totalWords << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Average words per sentence: " << averageWordsPerSentence << std::endl;

    return 0;
}
