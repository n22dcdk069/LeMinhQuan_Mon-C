#include <iostream>

// Function prototypes
double getLength();
double getWidth();
double getArea(double length, double width);
void displayData(double length, double width, double area);

int main() {
    // Get user input
    double length = getLength();
    double width = getWidth();

    // Calculate area
    double area = getArea(length, width);

    // Display data
    displayData(length, width, area);

    return 0;
}

// Function to get the rectangle's length from the user
double getLength() {
    double length;
    std::cout << "Enter the rectangle's length: ";
    std::cin >> length;
    return length;
}

// Function to get the rectangle's width from the user
double getWidth() {
    double width;
    std::cout << "Enter the rectangle's width: ";
    std::cin >> width;
    return width;
}

// Function to calculate the rectangle's area
double getArea(double length, double width) {
    return length * width;
}

// Function to display the rectangle's data
void displayData(double length, double width, double area) {
    std::cout << "Rectangle Data:\n";
    std::cout << "Length: " << length << "\n";
    std::cout << "Width: " << width << "\n";
    std::cout << "Area: " << area << "\n";
}
