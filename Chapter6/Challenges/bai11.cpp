#include <iostream>

// Function to get a test score from the user and validate it
void getScore(int &score) {
    do {
        std::cout << "Enter a test score (0-100): ";
        std::cin >> score;

        // Input validation: Do not accept test scores lower than 0 or higher than 100
        if (score < 0 || score > 100) {
            std::cout << "Invalid input. Test score must be between 0 and 100.\n";
        }
    } while (score < 0 || score > 100);
}

// Function to find the lowest of the five scores
int findLowest(int scores[]) {
    int lowest = scores[0];

    for (int i = 1; i < 5; ++i) {
        if (scores[i] < lowest) {
            lowest = scores[i];
        }
    }

    return lowest;
}

// Function to calculate and display the average of the four highest scores
void calcAverage(int scores[]) {
    int lowest = findLowest(scores);

    int sum = 0;
    int count = 0;

    // Calculate the sum of the four highest scores
    for (int i = 0; i < 5; ++i) {
        if (scores[i] != lowest) {
            sum += scores[i];
            ++count;
        }
    }

    // Calculate and display the average
    double average = static_cast<double>(sum) / count;
    std::cout << "The average of the four highest scores is: " << average << std::endl;
}

int main() {
    int scores[5];

    // Get test scores from the user
    for (int i = 0; i < 5; ++i) {
        getScore(scores[i]);
    }

    // Calculate and display the average of the four highest scores
    calcAverage(scores);

    return 0;
}
