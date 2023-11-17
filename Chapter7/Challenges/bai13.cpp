#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

const int numStudents = 5;
const int numTests = 4;

void calculateAverages(std::vector<std::vector<double>>& scores) {
    for (int i = 0; i < numStudents; ++i) {
        // Sort scores for each student
        std::sort(scores[i].begin(), scores[i].end());

        // Calculate average excluding the lowest score
        double sum = std::accumulate(scores[i].begin() + 1, scores[i].end(), 0.0);
        double average = sum / (numTests - 1);

        // Output average and letter grade
        std::cout << "Student " << (i + 1) << ": Average Score = " << average << ", Letter Grade = ";

        if (average >= 90) {
            std::cout << "A\n";
        } else if (average >= 80) {
            std::cout << "B\n";
        } else if (average >= 70) {
            std::cout << "C\n";
        } else if (average >= 60) {
            std::cout << "D\n";
        } else {
            std::cout << "F\n";
        }
    }
}

int main() {
    std::vector<std::vector<double>> testScores(numStudents, std::vector<double>(numTests));

    // Input test scores for each student
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Enter test scores for Student " << (i + 1) << ":\n";

        for (int j = 0; j < numTests; ++j) {
            std::cout << "Test " << (j + 1) << ": ";
            std::cin >> testScores[i][j];
        }
    }

    // Calculate averages and display results
    calculateAverages(testScores);

    return 0;
}
