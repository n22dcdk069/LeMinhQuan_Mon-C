#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper function

const int NUM_QUESTIONS = 20;

void displayResults(int correctAnswers, int incorrectAnswers, int incorrectQuestions[]) {
    std::cout << "\nResults:\n";
    std::cout << "Number of correctly answered questions: " << correctAnswers << "\n";
    std::cout << "Number of incorrectly answered questions: " << incorrectAnswers << "\n";

    if (incorrectAnswers > 0) {
        std::cout << "List of incorrectly answered questions: ";
        for (int i = 0; i < incorrectAnswers; ++i) {
            std::cout << incorrectQuestions[i];
            if (i < incorrectAnswers - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "\n";
    }

    if (correctAnswers >= 15) {
        std::cout << "Congratulations! You passed the exam.\n";
    } else {
        std::cout << "Sorry, you did not pass the exam.\n";
    }
}

int main() {
    char correctAnswers[NUM_QUESTIONS] = {'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D',
                                          'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B'};
    char studentAnswers[NUM_QUESTIONS];
    int incorrectQuestions[NUM_QUESTIONS];
    int correctCount = 0;
    int incorrectCount = 0;

    // Get student's answers
    std::cout << "Enter the student's answers for the 20 questions (A, B, C, or D):\n";
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        do {
            std::cout << "Question " << (i + 1) << ": ";
            std::cin >> studentAnswers[i];
            studentAnswers[i] = std::toupper(studentAnswers[i]); // convert to uppercase
            if (studentAnswers[i] != 'A' && studentAnswers[i] != 'B' && studentAnswers[i] != 'C' && studentAnswers[i] != 'D') {
                std::cout << "Invalid input. Please enter A, B, C, or D.\n";
            }
        } while (studentAnswers[i] != 'A' && studentAnswers[i] != 'B' && studentAnswers[i] != 'C' && studentAnswers[i] != 'D');

        // Check if the answer is correct
        if (studentAnswers[i] == correctAnswers[i]) {
            ++correctCount;
        } else {
            incorrectQuestions[incorrectCount] = i + 1; // store the question number
            ++incorrectCount;
        }
    }

    // Display results
    displayResults(correctCount, incorrectCount, incorrectQuestions);

    return 0;
}
