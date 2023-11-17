#include <iostream>
#include <vector>

// Function prototype
bool testPIN(const std::vector<int>& custPIN, const std::vector<int>& enteredPIN);

int main() {
    // Initialize vectors for PINs
    std::vector<int> pin1 = {4, 7, 1, 2, 5};
    std::vector<int> pin2 = {8, 7, 1, 2, 5};
    std::vector<int> pin3 = {4, 7, 1, 2, 5};

    // Test PINs
    if (testPIN(pin1, pin2)) {
        std::cout << "PIN 1 and PIN 2 are the same.\n";
    } else {
        std::cout << "PIN 1 and PIN 2 are different.\n";
    }

    if (testPIN(pin1, pin3)) {
        std::cout << "PIN 1 and PIN 3 are the same.\n";
    } else {
        std::cout << "PIN 1 and PIN 3 are different.\n";
    }

    return 0;
}

bool testPIN(const std::vector<int>& custPIN, const std::vector<int>& enteredPIN) {
    for (size_t i = 0; i < custPIN.size(); ++i) {
        if (custPIN[i] != enteredPIN[i]) {
            return false; // If any digit is different, return false
        }
    }
    return true; // All digits are the same, return true
}
