#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Function to read names from a file into a vector
void readNamesFromFile(const std::string& fileName, std::vector<std::string>& names) {
    std::ifstream inputFile(fileName);

    if (!inputFile) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        exit(1);
    }

    std::string name;
    while (getline(inputFile, name)) {
        names.push_back(name);
    }

    inputFile.close();
}

// Function to check if a name is among the most popular
bool isPopular(const std::vector<std::string>& names, const std::string& inputName) {
    return std::find(names.begin(), names.end(), inputName) != names.end();
}

int main() {
    std::vector<std::string> girlNames;
    std::vector<std::string> boyNames;

    // Read names from files
    readNamesFromFile("GirlNames.txt", girlNames);
    readNamesFromFile("BoyNames.txt", boyNames);

    // Get user input
    std::string girlInput, boyInput;
    std::cout << "Enter a girl's name: ";
    std::cin >> girlInput;

    std::cout << "Enter a boy's name: ";
    std::cin >> boyInput;

    // Check if names are among the most popular
    if (isPopular(girlNames, girlInput)) {
        std::cout << girlInput << " is among the most popular girl names.\n";
    } else {
        std::cout << girlInput << " is not among the most popular girl names.\n";
    }

    if (isPopular(boyNames, boyInput)) {
        std::cout << boyInput << " is among the most popular boy names.\n";
    } else {
        std::cout << boyInput << " is not among the most popular boy names.\n";
    }

    return 0;
}
