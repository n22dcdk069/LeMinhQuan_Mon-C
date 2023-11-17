#include <iostream>

int main() {
    char choice;

    do {
        // Display menu
        std::cout << "\nMath Quiz Menu\n";
        std::cout << "1. Addition\n";
        std::cout << "2. Subtraction\n";
        std::cout << "3. Multiplication\n";
        std::cout << "4. Division\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        // Process user choice
        switch (choice) {
            case '1': {
                // Addition
                int num1, num2;
                std::cout << "Enter two numbers for addition: ";
                std::cin >> num1 >> num2;
                std::cout << "Result: " << num1 + num2 << std::endl;
                break;
            }
            case '2': {
                // Subtraction
                int num1, num2;
                std::cout << "Enter two numbers for subtraction: ";
                std::cin >> num1 >> num2;
                std::cout << "Result: " << num1 - num2 << std::endl;
                break;
            }
            case '3': {
                // Multiplication
                int num1, num2;
                std::cout << "Enter two numbers for multiplication: ";
                std::cin >> num1 >> num2;
                std::cout << "Result: " << num1 * num2 << std::endl;
                break;
            }
            case '4': {
                // Division
                double num1, num2;
                std::cout << "Enter two numbers for division: ";
                std::cin >> num1 >> num2;

                if (num2 != 0) {
                    std::cout << "Result: " << num1 / num2 << std::endl;
                } else {
                    std::cout << "Error: Cannot divide by zero." << std::endl;
                }
                break;
            }
            case '5':
                // Quit the program
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                // Invalid choice
                std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }

    } while (choice != '5'); // Continue until the user chooses to quit

    return 0;
}
