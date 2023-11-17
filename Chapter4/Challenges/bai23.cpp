#include <iostream>
#include <cmath> // For using pow()

int main() {
    const double PI = 3.14159;

    // Display the menu
    std::cout << "Geometry Calculator\n";
    std::cout << " 1. Calculate the Area of a Circle\n";
    std::cout << " 2. Calculate the Area of a Rectangle\n";
    std::cout << " 3. Calculate the Area of a Triangle\n";
    std::cout << " 4. Quit\n";
    std::cout << "Enter your choice (1-4): ";

    // User choice
    int choice;
    std::cin >> choice;

    // Input validation
    if (choice < 1 || choice > 4) {
        std::cout << "Invalid choice. Please enter a number between 1 and 4." << std::endl;
        return 1; // Exit the program with an error code
    }

    // Variables for geometric calculations
    double area;

    // Perform the selected calculation
    switch (choice) {
        case 1: // Circle
            {
                double radius;
                std::cout << "Enter the radius of the circle: ";
                std::cin >> radius;

                // Input validation for negative radius
                if (radius < 0) {
                    std::cout << "Invalid input. Radius cannot be negative." << std::endl;
                    return 1; // Exit the program with an error code
                }

                area = PI * pow(radius, 2);
                std::cout << "The area of the circle is: " << area << std::endl;
            }
            break;
        case 2: // Rectangle
            {
                double length, width;
                std::cout << "Enter the length of the rectangle: ";
                std::cin >> length;

                // Input validation for negative length
                if (length < 0) {
                    std::cout << "Invalid input. Length cannot be negative." << std::endl;
                    return 1; // Exit the program with an error code
                }

                std::cout << "Enter the width of the rectangle: ";
                std::cin >> width;

                // Input validation for negative width
                if (width < 0) {
                    std::cout << "Invalid input. Width cannot be negative." << std::endl;
                    return 1; // Exit the program with an error code
                }

                area = length * width;
                std::cout << "The area of the rectangle is: " << area << std::endl;
            }
            break;
        case 3: // Triangle
            {
                double base, height;
                std::cout << "Enter the base of the triangle: ";
                std::cin >> base;

                // Input validation for negative base
                if (base < 0) {
                    std::cout << "Invalid input. Base cannot be negative." << std::endl;
                    return 1; // Exit the program with an error code
                }

                std::cout << "Enter the height of the triangle: ";
                std::cin >> height;

                // Input validation for negative height
                if (height < 0) {
                    std::cout << "Invalid input. Height cannot be negative." << std::endl;
                    return 1; // Exit the program with an error code
                }

                area = 0.5 * base * height;
                std::cout << "The area of the triangle is: " << area << std::endl;
            }
            break;
        case 4: // Quit
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            return 0; // Exit the program successfully
        default:
            std::cout << "Unexpected case!" << std::endl;
            return 1; // Exit the program with an error code
    }

    return 0;
}
