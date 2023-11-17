#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

// Function prototype
void coinToss();

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Get the number of times the coin should be tossed
    int numTosses;
    std::cout << "Enter the number of times you want to toss the coin: ";
    std::cin >> numTosses;

    // Validate input
    while (numTosses <= 0) {
        std::cout << "Please enter a positive number: ";
        std::cin >> numTosses;
    }

    // Simulate coin tosses
    for (int i = 0; i < numTosses; ++i) {
        std::cout << "Toss " << i + 1 << ": ";
        coinToss();
    }

    return 0;
}

// Function to simulate a coin toss
void coinToss() {
    // Generate a random number in the range of 1 through 2
    int result = rand() % 2 + 1;

    // Display the result
    if (result == 1) {
        std::cout << "Heads\n";
    } else {
        std::cout << "Tails\n";
    }
}
