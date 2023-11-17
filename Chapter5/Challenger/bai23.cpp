#include <iostream>

int main() {
    const int patternSize = 10;

    // Pattern A
    std::cout << "Pattern A:\n";
    for (int i = 1; i <= patternSize; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << "+";
        }
        std::cout << " " << std::string(patternSize - i, '+') << "\n";
    }

    // Pattern B
    std::cout << "\nPattern B:\n";
    for (int i = 1; i <= patternSize; ++i) {
        std::cout << std::string(i - 1, ' ') << "+";
        for (int j = 1; j <= patternSize - i; ++j) {
            std::cout << "+";
        }
        std::cout << "\n";
    }

    return 0;
}
