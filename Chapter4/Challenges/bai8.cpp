#include <iostream>
#include <string>

int main() {
    // Prompt the user to enter the names of two primary colors
    std::cout << "Enter the names of two primary colors (red, blue, or yellow), separated by space: ";

    // Variables to store user input
    std::string color1, color2;

    // Get input for two primary colors
    std::cin >> color1 >> color2;

    // Check if the entered colors are valid primary colors
    if ((color1 == "red" || color1 == "blue" || color1 == "yellow") &&
        (color2 == "red" || color2 == "blue" || color2 == "yellow")) {
        // Check the combination of colors to determine the secondary color
        if ((color1 == "red" && color2 == "blue") || (color1 == "blue" && color2 == "red")) {
            std::cout << "The secondary color is purple.\n";
        } else if ((color1 == "red" && color2 == "yellow") || (color1 == "yellow" && color2 == "red")) {
            std::cout << "The secondary color is orange.\n";
        } else if ((color1 == "blue" && color2 == "yellow") || (color1 == "yellow" && color2 == "blue")) {
            std::cout << "The secondary color is green.\n";
        } else {
            std::cout << "Invalid combination of colors.\n";
        }
    } else {
        std::cout << "Error: Please enter valid primary colors (red, blue, or yellow).\n";
    }

    return 0;
}
