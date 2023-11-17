#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Generate two random numbers for addition
    int num1 = rand() % 1000; // Change 1000 to the desired range
    int num2 = rand() % 1000; // Change 1000 to the desired range

    // Display the addition problem
    std::cout << "  " << num1 << "\n+ " << num2 << "\n";

    // Wait for the user to press a key
    std::cout << "\nPress any key to reveal the correct solution...";
    std::cin.ignore();
    std::cin.get();

    // Display the correct solution
    int sum = num1 + num2;
    std::cout << "\n  " << num1 << "\n+ " << num2 << "\n  " << sum << "\n";

    return 0;
}
