#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()

const int ARRAY_SIZE = 5;

void generateLotteryNumbers(int lottery[]) {
    // Seed for the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Generate random numbers for the lottery array
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        lottery[i] = rand() % 10;  // Random number in the range 0-9
    }
}

void getUserNumbers(int user[]) {
    std::cout << "Enter five digits (0-9) for the lottery: ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cin >> user[i];
    }
}

int countMatchingDigits(const int lottery[], const int user[]) {
    int count = 0;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (lottery[i] == user[i]) {
            ++count;
        }
    }
    return count;
}

int main() {
    int lotteryNumbers[ARRAY_SIZE];
    int userNumbers[ARRAY_SIZE];

    // Generate random lottery numbers
    generateLotteryNumbers(lotteryNumbers);

    // Get user's lottery numbers
    getUserNumbers(userNumbers);

    // Display the lottery numbers
    std::cout << "Lottery Numbers: ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << lotteryNumbers[i] << " ";
    }
    std::cout << "\n";

    // Count and display matching digits
    int matchingDigits = countMatchingDigits(lotteryNumbers, userNumbers);
    std::cout << "Matching Digits: " << matchingDigits << "\n";

    // Check if the user is a grand prize winner
    if (matchingDigits == ARRAY_SIZE) {
        std::cout << "Congratulations! You are a grand prize winner!\n";
    }

    return 0;
}
