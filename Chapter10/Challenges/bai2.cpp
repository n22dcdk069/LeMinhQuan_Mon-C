#include <iostream>
#include <cstring>

void displayBackward(const char* str) {
    int length = strlen(str);

    // Display the string backward
    for (int i = length - 1; i >= 0; --i) {
        std::cout << str[i];
    }

    std::cout << std::endl;
}

int main() {
    const int MAX_LENGTH = 100;
    char input[MAX_LENGTH];

    // Ask the user to input a string
    std::cout << "Enter a string: ";
    std::cin.getline(input, MAX_LENGTH);

    // Pass the string to the function to display it backward
    displayBackward(input);

    return 0;
}
