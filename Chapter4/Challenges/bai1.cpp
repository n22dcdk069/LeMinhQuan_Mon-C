#include <iostream>

int main() {
    // Declare variables to store user input
    double num1, num2;

    // Get input from the user
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    // Determine and display the larger and smaller numbers using the conditional operator
    double largerNum = (num1 > num2) ? num1 : num2;
    double smallerNum = (num1 < num2) ? num1 : num2;

    std::cout << "The larger number is: " << largerNum << std::endl;
    std::cout << "The smaller number is: " << smallerNum << std::endl;

    return 0;
}
