#include <iostream>
#include <fstream>
#include <iomanip>

const int numQuestions = 20;

int main() {
    // Arrays to hold correct and student answers
    char correctAnswers[numQuestions];
    char studentAnswers[numQuestions];

    // Read correct answers from "CorrectAnswers.txt"
    std::ifstream correctFile("CorrectAnswers.txt");

    if (!correctFile) {
        std::cerr << "Error opening CorrectAnswers.txt.\n";
        return 1;
    }

    for (int i = 0; i < numQuestions; ++i) {
        correctFile >> correctAnswers[i];
    }

    correctFile.close();

    // Read student answers from "StudentAnswers.txt"
    std::ifstream studentFile("StudentAnswers.txt");

    if (!studentFile) {
        std::cerr << "Error opening StudentAnswers.txt.\n";
        return 1;
    }

    for (int i = 0; i < numQuestions; ++i) {
        studentFile >> studentAnswers[i];
    }

    studentFile.close();

    // Compare answers and calculate results
    int questionsMissed = 0;
    int correctlyAnswered = 0;

    std::cout << "Missed Questions:\n";
    std::cout << "-----------------\n";

    for (int i = 0; i < numQuestions; ++i) {
        if (correctAnswers[i] != studentAnswers[i]) {
            std::cout << "Question " << (i + 1) << ": Correct answer: " << correctAnswers[i]
                      << ", Your answer: " << studentAnswers[i] << std::endl;
            ++questionsMissed;
        } else {
            ++correctlyAnswered;
        }
    }

    // Display results
    double percentageCorrect = static_cast<double>(correctlyAnswered) / numQuestions * 100;

    std::cout << "\nTotal Questions Missed: " << questionsMissed << std::endl;
    std::cout << "Percentage Correct: " << std::fixed << std::setprecision(2) << percentageCorrect << "%\n";

    // Determine pass or fail
    if (percentageCorrect >= 70.0) {
        std::cout << "Student passed the exam.\n";
    } else {
        std::cout << "Student failed the exam.\n";
    }

    return 0;
}
