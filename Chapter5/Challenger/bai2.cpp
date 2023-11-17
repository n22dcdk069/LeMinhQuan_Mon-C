#include <iostream>

int main() {
    // Loop through ASCII codes 0 to 127
    for (int i = 0; i <= 127; ++i) {
        // Print the character
        std::cout << static_cast<char>(i) << ' ';

        // Print a newline after every 16 characters
        if ((i + 1) % 16 == 0) {
            std::cout << std::endl;
        }
    }

    return 0;
}
