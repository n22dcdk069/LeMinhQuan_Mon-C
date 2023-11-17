#include <iostream>
#include <cctype> // For isupper function

int main() {
    std::cout << "Enter a sentence with words run together: ";
    std::string input;
    std::getline(std::cin, input);

    std::string result;

    for (size_t i = 0; i < input.length(); ++i) {
        // Append a space before each uppercase letter (except the first one)
        if (i > 0 && std::isupper(input[i])) {
            result += ' ';
        }

        // Convert uppercase letters (except the first one) to lowercase
        if (i > 0) {
            result += std::tolower(input[i]);
        } else {
            // Keep the first character of the first word as uppercase
            result += input[i];
        }
    }

    std::cout << "Converted sentence: " << result << std::endl;

    return 0;
}
