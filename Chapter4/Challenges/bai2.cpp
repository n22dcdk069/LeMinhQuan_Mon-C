#include <iostream>

int main() {
    // Get user input
    int number;
    std::cout << "Enter a number between 1 and 10: ";
    std::cin >> number;

    // Input validation
    if (number < 1 || number > 10) {
        std::cout << "Invalid input. Please enter a number between 1 and 10." << std::endl;
        return 1; // Exit the program with an error code
    }

    // Switch statement to display Roman numerals
    switch (number) {
        case 1:
            std::cout << "I" << std::endl;
            break;
        case 2:
            std::cout << "II" << std::endl;
            break;
        case 3:
            std::cout << "III" << std::endl;
            break;
        case 4:
            std::cout << "IV" << std::endl;
            break;
        case 5:
            std::cout << "V" << std::endl;
            break;
        case 6:
            std::cout << "VI" << std::endl;
            break;
        case 7:
            std::cout << "VII" << std::endl;
            break;
        case 8:
            std::cout << "VIII" << std::endl;
            break;
        case 9:
            std::cout << "IX" << std::endl;
            break;
        case 10:
            std::cout << "X" << std::endl;
            break;
        default:
            std::cout << "Unexpected case!" << std::endl;
            return 1; // Exit the program with an error code
    }

    return 0; // Exit the program successfully
}
