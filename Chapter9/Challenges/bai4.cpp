#include <iostream>
#include <algorithm>
#include <iomanip>

// Function prototypes
void inputScoresAndNames(std::string* names, double* scores, int numScores);
void sortScoresAndNames(std::string* names, double* scores, int numScores);
double calculateAverage(const double* scores, int numScores);
void displayResults(const std::string* names, const double* scores, int numScores, double average);

int main() {
    int numScores;

    // Get the number of test scores from the user
    std::cout << "Enter the number of test scores: ";
    std::cin >> numScores;

    // Validate the number of scores
    while (numScores <= 0) {
        std::cout << "Please enter a positive number of test scores: ";
        std::cin >> numScores;
    }

    // Dynamically allocate arrays for names and test scores
    std::string* names = new std::string[numScores];
    double* scores = new double[numScores];

    // Input test scores and names
    inputScoresAndNames(names, scores, numScores);

    // Sort the test scores and names
    sortScoresAndNames(names, scores, numScores);

    // Calculate the average score
    double average = calculateAverage(scores, numScores);

    // Display results
    displayResults(names, scores, numScores, average);

    // Deallocate the dynamically allocated memory
    delete[] names;
    delete[] scores;

    return 0;
}

void inputScoresAndNames(std::string* names, double* scores, int numScores) {
    std::cout << "Enter the name and test score for each student:\n";
    for (int i = 0; i < numScores; ++i) {
        std::cout << "Student " << i + 1 << " Name: ";
        std::cin.ignore(); // Ignore newline left in the buffer
        std::getline(std::cin, *(names + i));

        do {
            std::cout << "Student " << i + 1 << " Score: ";
            std::cin >> *(scores + i);
            if (*(scores + i) < 0) {
                std::cout << "Please enter a non-negative score.\n";
            }
        } while (*(scores + i) < 0);
    }
}

void sortScoresAndNames(std::string* names, double* scores, int numScores) {
    // Create an array of pairs (name, score) for sorting
    std::pair<double, std::string>* pairs = new std::pair<double, std::string>[numScores];
    for (int i = 0; i < numScores; ++i) {
        pairs[i] = std::make_pair(scores[i], names[i]);
    }

    // Sort the array of pairs based on scores
    std::sort(pairs, pairs + numScores);

    // Copy sorted names and scores back to the original arrays
    for (int i = 0; i < numScores; ++i) {
        names[i] = pairs[i].second;
        scores[i] = pairs[i].first;
    }

    // Deallocate the temporary array of pairs
    delete[] pairs;
}

double calculateAverage(const double* scores, int numScores) {
    double sum = 0.0;
    for (int i = 0; i < numScores; ++i) {
        sum += *(scores + i);
    }
    return sum / numScores;
}

void displayResults(const std::string* names, const double* scores, int numScores, double average) {
    std::cout << "\nSorted Test Scores and Names:\n";
    std::cout << std::setw(20) << "Name" << std::setw(10) << "Score\n";
    for (int i = 0; i < numScores; ++i) {
        std::cout << std::setw(20) << *(names + i) << std::setw(10) << *(scores + i) << "\n";
    }

    std::cout << "\nAverage Score: " << average << "\n";
}
