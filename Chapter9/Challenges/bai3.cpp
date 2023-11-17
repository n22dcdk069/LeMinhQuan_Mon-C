#include <iostream>
#include <algorithm>  // Required for using std::sort

// Function to dynamically allocate an array of integers
int* allocateIntArray(int size) {
    return new int[size];
}

// Function to calculate the average of an array of test scores, dropping the lowest score
double calculateAverageWithoutLowest(int* scores, int size) {
    if (size <= 1) {
        // If there's only one or zero scores, no need to drop the lowest
        return (size == 1) ? scores[0] : 0.0;
    }

    // Sort the array in ascending order
    std::sort(scores, scores + size);

    // Calculate the sum of scores excluding the lowest one
    int sum = 0;
    for (int i = 1; i < size; ++i) {
        sum += scores[i];
    }

    // Calculate and return the average
    return static_cast<double>(sum) / (size - 1);
}

int main() {
    // Example of using the functions
    int arraySize = 5;
    int* testScores = allocateIntArray(arraySize);

    // Input test scores
    std::cout << "Enter " << arraySize << " test scores:\n";
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "Test Score " << i + 1 << ": ";
        std::cin >> testScores[i];
    }

    // Calculate the average without the lowest score
    double average = calculateAverageWithoutLowest(testScores, arraySize);

    // Output the result
    std::cout << "Average test score (excluding the lowest): " << average << std::endl;

    // Don't forget to delete the allocated memory when you're done
    delete[] testScores;

    return 0;
}
