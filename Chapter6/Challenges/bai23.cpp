#include <iostream>
#include <fstream>

// Function prototype for checking if a number is prime
bool isPrime(int number);

int main() {
    // Open the file for writing
    std::ofstream outfile("prime_numbers.txt");

    // Check and store prime numbers from 1 through 100 in the file
    for (int i = 1; i <= 100; ++i) {
        if (isPrime(i)) {
            outfile << i << "\n";
        }
    }

    // Close the file
    outfile.close();

    std::cout << "Prime numbers from 1 through 100 have been stored in 'prime_numbers.txt'." << std::endl;

    return 0;
}

// Function definition for checking if a number is prime
bool isPrime(int number) {
    if (number < 2) {
        return false;
    }

    for (int i = 2; i <= number / 2; ++i) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}
