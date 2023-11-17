#include <iostream>

class Circle {
private:
    double radius;
    const double pi = 3.14159;

public:
    // Default constructor
    Circle() : radius(0.0) {}

    // Constructor with radius as an argument
    Circle(double r) : radius(r) {}

    // Mutator function for radius
    void setRadius(double r) {
        if (r >= 0) {
            radius = r;
        } else {
            std::cerr << "Error: Radius cannot be negative.\n";
        }
    }

    // Accessor function for radius
    double getRadius() const {
        return radius;
    }

    // Calculate and return the area of the circle
    double getArea() const {
        return pi * radius * radius;
    }

    // Calculate and return the diameter of the circle
    double getDiameter() const {
        return radius * 2;
    }

    // Calculate and return the circumference of the circle
    double getCircumference() const {
        return 2 * pi * radius;
    }
};

int main() {
    // Demonstrate the Circle class
    double userRadius;
    std::cout << "Enter the radius of the circle: ";
    std::cin >> userRadius;

    // Create a Circle object
    Circle myCircle(userRadius);

    // Display circle information
    std::cout << "\nCircle Information:\n";
    std::cout << "Radius: " << myCircle.getRadius() << "\n";
    std::cout << "Area: " << myCircle.getArea() << "\n";
    std::cout << "Diameter: " << myCircle.getDiameter() << "\n";
    std::cout << "Circumference: " << myCircle.getCircumference() << "\n";

    return 0;
}