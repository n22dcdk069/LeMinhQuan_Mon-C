#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

// Function to calculate the average of an array of values
double calculateAverage(const int* arr, int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

// Function to calculate the median of a sorted array of values
double calculateMedian(const int* arr, int size) {
    // If the size of the array is even, calculate the average of the two middle values
    if (size % 2 == 0) {
        return static_cast<double>(arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    }
    // If the size is odd, return the middle value
    else {
        return static_cast<double>(arr[size / 2]);
    }
}

// Function to calculate the mode of an array of values
int calculateMode(const int* arr, int size) {
    std::unordered_map<int, int> frequencyMap;

    for (int i = 0; i < size; ++i) {
        frequencyMap[arr[i]]++;
    }

    int mode = arr[0];
    int maxFrequency = 1;

    for (const auto& entry : frequencyMap) {
        if (entry.second > maxFrequency) {
            mode = entry.first;
            maxFrequency = entry.second;
        }
    }

    return mode;
}

int main() {
    int numStudents;

    // Step A: Ask the user how many students were surveyed
    std::cout << "Enter the number of students surveyed: ";
    std::cin >> numStudents;

    // Input validation
    while (numStudents <= 0) {
        std::cout << "Please enter a positive number of students: ";
        std::cin >> numStudents;
    }

    // Step B: Dynamically allocate an array for the number of students
    int* movieCounts = new int[numStudents];

    // Step B: Allow the user to enter the number of movies each student saw into the array
    for (int i = 0; i < numStudents; ++i) {
        do {
            std::cout << "Enter the number of movies for student " << i + 1 << ": ";
            std::cin >> movieCounts[i];

            // Input validation
            if (movieCounts[i] < 0) {
                std::cout << "Please enter a non-negative number of movies.\n";
            }
        } while (movieCounts[i] < 0);
    }

    // Step C: Calculate and display the average, median, and mode of the values entered
    // Sort the array for calculating median
    std::sort(movieCounts, movieCounts + numStudents);

    // Calculate statistics
    double average = calculateAverage(movieCounts, numStudents);
    double median = calculateMedian(movieCounts, numStudents);
    int mode = calculateMode(movieCounts, numStudents);

    // Display the results
    std::cout << "\nStatistical Data:\n";
    std::cout << "Average number of movies: " << average << "\n";
    std::cout << "Median number of movies: " << median << "\n";
    std::cout << "Mode number of movies: " << mode << "\n";

    // Clean up: Deallocate the dynamically allocated memory
    delete[] movieCounts;

    return 0;
}
