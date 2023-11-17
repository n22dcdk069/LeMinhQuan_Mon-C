#include <iostream>
#include <limits> // For numeric_limits

// Function prototypes
void getJudgeData(double &score);
void calcScore(double score1, double score2, double score3, double score4, double score5);
int findLowest(double score1, double score2, double score3, double score4, double score5);
int findHighest(double score1, double score2, double score3, double score4, double score5);

int main() {
    // Variables to store judge scores
    double score1, score2, score3, score4, score5;

    // Get judge scores
    getJudgeData(score1);
    getJudgeData(score2);
    getJudgeData(score3);
    getJudgeData(score4);
    getJudgeData(score5);

    // Calculate and display the contestant's score
    calcScore(score1, score2, score3, score4, score5);

    return 0;
}

// Function to get a judge's score and validate it
void getJudgeData(double &score) {
    do {
        std::cout << "Enter a judge's score (between 0 and 10): ";
        std::cin >> score;

        if (std::cin.fail() || score < 0 || score > 10) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a score between 0 and 10.\n";
        }
    } while (score < 0 || score > 10);
}

// Function to calculate and display the contestant's score
void calcScore(double score1, double score2, double score3, double score4, double score5) {
    // Find and drop the lowest and highest scores
    int lowestIndex = findLowest(score1, score2, score3, score4, score5);
    int highestIndex = findHighest(score1, score2, score3, score4, score5);

    double totalScore = score1 + score2 + score3 + score4 + score5;
    totalScore -= (score1 + score2 + score3 + score4 + score5) / 5; // Drop the lowest and highest scores

    // Display the contestant's final score
    std::cout << "Contestant's final score: " << totalScore / 3 << std::endl;
}

// Function to find the index of the lowest score
int findLowest(double score1, double score2, double score3, double score4, double score5) {
    int lowestIndex = 1;
    double lowestScore = score1;

    if (score2 < lowestScore) {
        lowestIndex = 2;
        lowestScore = score2;
    }
    if (score3 < lowestScore) {
        lowestIndex = 3;
        lowestScore = score3;
    }
    if (score4 < lowestScore) {
        lowestIndex = 4;
        lowestScore = score4;
    }
    if (score5 < lowestScore) {
        lowestIndex = 5;
    }

    return lowestIndex;
}

// Function to find the index of the highest score
int findHighest(double score1, double score2, double score3, double score4, double score5) {
    int highestIndex = 1;
    double highestScore = score1;

    if (score2 > highestScore) {
        highestIndex = 2;
        highestScore = score2;
    }
    if (score3 > highestScore) {
        highestIndex = 3;
        highestScore = score3;
    }
    if (score4 > highestScore) {
        highestIndex = 4;
        highestScore = score4;
    }
    if (score5 > highestScore) {
        highestIndex = 5;
    }

    return highestIndex;
}