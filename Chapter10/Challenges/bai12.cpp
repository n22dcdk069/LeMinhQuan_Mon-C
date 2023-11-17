#include <iostream>
#include <cctype> // For isupper, islower, and isdigit functions

int main() {
    const int MIN_LENGTH = 6;

    std::cout << "Enter your password: ";
    std::string password;
    std::cin >> password;

    // Check the length of the password
    if (password.length() < MIN_LENGTH) {
        std::cout << "Password is too short. It should be at least " << MIN_LENGTH << " characters long." << std::endl;
        return 1; // Exit the program with an error code
    }

    // Check for at least one uppercase letter
    bool hasUppercase = false;
    for (char ch : password) {
        if (std::isupper(ch)) {
            hasUppercase = true;
            break;
        }
    }

    if (!hasUppercase) {
        std::cout << "Password should contain at least one uppercase letter." << std::endl;
        return 1; // Exit the program with an error code
    }

    // Check for at least one lowercase letter
    bool hasLowercase = false;
    for (char ch : password) {
        if (std::islower(ch)) {
            hasLowercase = true;
            break;
        }
    }

    if (!hasLowercase) {
        std::cout << "Password should contain at least one lowercase letter." << std::endl;
        return 1; // Exit the program with an error code
    }

    // Check for at least one digit
    bool hasDigit = false;
    for (char ch : password) {
        if (std::isdigit(ch)) {
            hasDigit = true;
            break;
        }
    }

    if (!hasDigit) {
        std::cout << "Password should contain at least one digit." << std::endl;
        return 1; // Exit the program with an error code
    }

    std::cout << "Password meets the criteria. Password accepted!" << std::endl;

    return 0;
}
