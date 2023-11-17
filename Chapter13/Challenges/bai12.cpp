#include <iostream>
#include <cstdlib> // For rand() and srand() functions
#include <ctime>   // For time() function

class Coin {
private:
    std::string sideUp;

public:
    // Default constructor
    Coin() {
        // Initialize the random number generator with the current time
        srand(static_cast<unsigned int>(time(0)));

        // Randomly determine the side of the coin that is facing up
        toss();
    }

    // Toss the coin and set the sideUp member variable accordingly
    void toss() {
        // Generate a random number (0 or 1) to represent heads or tails
        int randomNum = rand() % 2;

        // Set sideUp based on the random number
        if (randomNum == 0) {
            sideUp = "Heads";
        } else {
            sideUp = "Tails";
        }
    }

    // Return the value of the sideUp member variable
    std::string getSideUp() const {
        return sideUp;
    }
};

int main() {
    // Create an instance of the Coin class
    Coin myCoin;

    // Display the initial side facing up
    std::cout << "Initial side facing up: " << myCoin.getSideUp() << "\n";

    // Toss the coin 20 times and display the side facing up each time
    int headsCount = 0;
    int tailsCount = 0;

    for (int i = 0; i < 20; ++i) {
        myCoin.toss();
        std::cout << "Toss " << (i + 1) << ": " << myCoin.getSideUp() << "\n";

        // Count the number of times heads or tails is facing up
        if (myCoin.getSideUp() == "Heads") {
            headsCount++;
        } else {
            tailsCount++;
        }
    }

    // Display the count of heads and tails
    std::cout << "\nNumber of times Heads is facing up: " << headsCount << "\n";
    std::cout << "Number of times Tails is facing up: " << tailsCount << "\n";

    return 0;
}
