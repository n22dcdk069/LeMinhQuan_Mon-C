#include <iostream>

int main() {
    // Variables to store length and width for two rectangles
    double length1, width1, length2, width2;

    // Get input for the dimensions of the first rectangle
    std::cout << "Enter length and width for Rectangle 1 (separated by space): ";
    std::cin >> length1 >> width1;

    // Get input for the dimensions of the second rectangle
    std::cout << "Enter length and width for Rectangle 2 (separated by space): ";
    std::cin >> length2 >> width2;

    // Calculate areas of the rectangles
    double area1 = length1 * width1;
    double area2 = length2 * width2;

    // Compare the areas and print the result
    if (area1 > area2) {
        std::cout << "Rectangle 1 has a greater area.\n";
    } else if (area2 > area1) {
        std::cout << "Rectangle 2 has a greater area.\n";
    } else {
        std::cout << "Both rectangles have the same area.\n";
    }

    return 0;
}
