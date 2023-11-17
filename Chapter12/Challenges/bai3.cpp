#include <iostream>
#include <fstream>
#include <string>

// Function prototypes
void readAndDisplayJoke(const std::string& jokeFileName);
void displayPunchLine(const std::string& punchLineFileName);

int main() {
    // File names for the joke and punch line
    std::string jokeFileName = "joke.txt";
    std::string punchLineFileName = "punchline.txt";

    // Call functions to read and display the joke and punch line
    readAndDisplayJoke(jokeFileName);
    displayPunchLine(punchLineFileName);

    return 0;
}

// Function to read and display each line in the joke file
void readAndDisplayJoke(const std::string& jokeFileName) {
    std::ifstream jokeFile(jokeFileName);

    if (!jokeFile.is_open()) {
        std::cerr << "Error opening the joke file. Exiting program.\n";
        exit(1); // Return an error code
    }

    std::cout << "Joke:\n";
    std::string line;

    while (std::getline(jokeFile, line)) {
        std::cout << line << std::endl;
    }

    jokeFile.close();
}

// Function to display only the last line of the punch line file
void displayPunchLine(const std::string& punchLineFileName) {
    std::ifstream punchLineFile(punchLineFileName);

    if (!punchLineFile.is_open()) {
        std::cerr << "Error opening the punch line file. Exiting program.\n";
        exit(1); // Return an error code
    }

    std::cout << "\nPunch Line:\n";

    // Seek to the end of the file
    punchLineFile.seekg(0, std::ios::end);

    // Back up to the beginning of the last line
    char ch;
    do {
        punchLineFile.seekg(-2, std::ios::cur);
        punchLineFile.get(ch);
    } while (ch != '\n');

    // Display the punch line
    std::string punchLine;
    std::getline(punchLineFile, punchLine);
    std::cout << punchLine << std::endl;

    punchLineFile.close();
}
