#include <iostream>
#include <iomanip>
#include <string>

const int NUM_STUDENTS = 5;
const int NUM_TESTS = 4;

// Function to calculate the average test score
double calculateAverage(double testScores[]) {
    double sum = 0;
    for (int i = 0; i < NUM_TESTS; ++i) {
        sum += testScores[i];
    }
    return sum / NUM_TESTS;
}

// Function to determine the letter grade based on the average score
char calculateLetterGrade(double average) {
    if (average >= 90) {
        return 'A';
    } else if (average >= 80) {
        return 'B';
    } else if (average >= 70) {
        return 'C';
    } else if (average >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    std::string studentNames[NUM_STUDENTS];
    char letterGrades[NUM_STUDENTS];
    double testScores[NUM_STUDENTS][NUM_TESTS];

    // Input: Get student names and test scores
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        std::cout << "Enter the name of student " << i + 1 << ": ";
        std::getline(std::cin, studentNames[i]);

        for (int j = 0; j < NUM_TESTS; ++j) {
            do {
                std::cout << "Enter test score " << j + 1 << " for " << studentNames[i] << ": ";
                std::cin >> testScores[i][j];

                // Input validation
                if (testScores[i][j] < 0 || testScores[i][j] > 100) {
                    std::cout << "Invalid input. Please enter a score between 0 and 100.\n";
                }
            } while (testScores[i][j] < 0 || testScores[i][j] > 100);
        }
        std::cin.ignore(); // consume the newline character
    }

    // Calculate and display average scores and letter grades
    std::cout << "\nResults:\n";
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        double average = calculateAverage(testScores[i]);
        letterGrades[i] = calculateLetterGrade(average);

        std::cout << std::fixed << std::setprecision(2);
        std::cout << studentNames[i] << ": Average Score = " << average << ", Letter Grade = " << letterGrades[i] << "\n";
    }

    return 0;
}
