#include <iostream>
#include <algorithm> // for std::sort
#include <unordered_map> // for std::unordered_map

// Function to calculate the average of an array of values
double calculateAverage(const int* arr, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

// Function to calculate the median of a sorted array
double calculateMedian(const int* arr, int size) {
    if (size % 2 == 0) {
        return static_cast<double>(arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else {
        return static_cast<double>(arr[size / 2]);
    }
}

// Function to calculate the mode of an array of values
int calculateMode(const int* arr, int size) {
    std::unordered_map<int, int> countMap;

    for (int i = 0; i < size; ++i) {
        countMap[arr[i]]++;
    }

    int mode = arr[0];
    int maxCount = 1;

    for (auto const& pair : countMap) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mode = pair.first;
        }
    }

    return mode;
}

int main() {
    // Step A: Ask the user how many students were surveyed
    int numStudents;
    std::cout << "How many students were surveyed? ";
    std::cin >> numStudents;

    // Input validation for the number of students
    while (numStudents <= 0) {
        std::cout << "Please enter a positive number of students: ";
        std::cin >> numStudents;
    }

    // Step B: Dynamically allocate an array of integers
    int* moviesPerStudent = new int[numStudents];

    // Allow the user to enter the number of movies each student saw into the array
    for (int i = 0; i < numStudents; ++i) {
        do {
            std::cout << "Enter the number of movies student " << i + 1 << " saw: ";
            std::cin >> moviesPerStudent[i];

            // Input validation for negative numbers
            if (moviesPerStudent[i] < 0) {
                std::cout << "Please enter a non-negative number of movies.\n";
            }
        } while (moviesPerStudent[i] < 0);
    }

    // Step C: Calculate and display the average, median, and mode
    std::sort(moviesPerStudent, moviesPerStudent + numStudents); // Sort for median calculation

    double average = calculateAverage(moviesPerStudent, numStudents);
    double median = calculateMedian(moviesPerStudent, numStudents);
    int mode = calculateMode(moviesPerStudent, numStudents);

    // Display the results
    std::cout << "\nResults:\n";
    std::cout << "Average number of movies: " << average << std::endl;
    std::cout << "Median number of movies: " << median << std::endl;
    std::cout << "Mode number of movies: " << mode << std::endl;

    // Clean up: Free dynamically allocated memory
    delete[] moviesPerStudent;

    return 0;
}
