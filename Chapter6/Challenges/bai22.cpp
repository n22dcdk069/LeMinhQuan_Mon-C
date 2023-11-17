#include <iostream>

// Function prototype
bool isPrime(int number);

int main() {
    // Get user input
    int userNumber;
    std::cout << "Enter an integer to check if it is prime: ";
    std::cin >> userNumber;

    // Check and display if the number is prime or not
    if (isPrime(userNumber)) {
        std::cout << userNumber << " is a prime number.\n";
    } else {
        std::cout << userNumber << " is not a prime number.\n";
    }

    return 0;
}

// Function to check if a number is prime
bool isPrime(int number) {
    // Prime numbers are greater than 1
    if (number <= 1) {
        return false;
    }

    // Check for factors from 2 to the square root of the number
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            // If the number is divisible by any factor, it is not prime
            return false;
        }
    }

    // If no factors were found, the number is prime
    return true;
}
