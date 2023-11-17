#include <iostream>
#include <iomanip> // Required for setprecision
using namespace std;

int main() {
    // Variables to store test scores
    double testScore1, testScore2, testScore3, testScore4, testScore5;

    // Get user input for test scores
    cout << "Enter test score 1: ";
    cin >> testScore1;

    cout << "Enter test score 2: ";
    cin >> testScore2;

    cout << "Enter test score 3: ";
    cin >> testScore3;

    cout << "Enter test score 4: ";
    cin >> testScore4;

    cout << "Enter test score 5: ";
    cin >> testScore5;

    // Calculate average test score
    double averageScore = (testScore1 + testScore2 + testScore3 + testScore4 + testScore5) / 5.0;

    // Display the average score with fixed-point notation and one decimal point
    cout << fixed << setprecision(1);
    cout << "Average test score: " << averageScore << endl;

    return 0;
}
