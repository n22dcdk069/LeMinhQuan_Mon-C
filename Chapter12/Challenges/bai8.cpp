#include <iostream>
#include <fstream>

// Function to write an array to a file
void arrayToFile(const char* fileName, const int* arr, int size) {
    std::ofstream outFile(fileName, std::ios::binary);

    if (!outFile.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    outFile.write(reinterpret_cast<const char*>(arr), size * sizeof(int));
    outFile.close();
}

// Function to read data from a file into an array
void fileToArray(const char* fileName, int* arr, int size) {
    std::ifstream inFile(fileName, std::ios::binary);

    if (!inFile.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    inFile.read(reinterpret_cast<char*>(arr), size * sizeof(int));
    inFile.close();
}

int main() {
    const char* fileName = "data.bin";
    const int arrSize = 5;

    int originalArray[arrSize] = {1, 2, 3, 4, 5};
    int newArray[arrSize];

    // Write array to file
    arrayToFile(fileName, originalArray, arrSize);
    std::cout << "Array has been written to the file.\n";

    // Read data from file into another array
    fileToArray(fileName, newArray, arrSize);
    std::cout << "Array has been read from the file.\n";

    // Display the contents of the new array
    std::cout << "Contents of the array read from the file:\n";
    for (int i = 0; i < arrSize; ++i) {
        std::cout << newArray[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
