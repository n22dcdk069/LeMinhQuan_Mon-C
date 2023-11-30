#include <iostream>

// Lớp cha
class Shape {
public:
    virtual double calculateArea() const {
        return 0.0; // Phương thức ảo có thể được triển khai trong các lớp con
    }
};

// Lớp con 1
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Ghi đè phương thức calculateArea
    double calculateArea() const override {
        return 3.14 * radius * radius;
    }
};

// Lớp con 2
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Ghi đè phương thức calculateArea
    double calculateArea() const override {
        return length * width;
    }
};

int main() {
    // Tạo một đối tượng Circle và tính diện tích
    Circle circle(5.0);
    std::cout << "Area of Circle: " << circle.calculateArea() << std::endl;

    // Tạo một đối tượng Rectangle và tính diện tích
    Rectangle rectangle(4.0, 6.0);
    std::cout << "Area of Rectangle: " << rectangle.calculateArea() << std::endl;

    // Sử dụng đa hình: tạo một mảng các đối tượng Shape và tính tổng diện tích
    Shape* shapes[] = {&circle, &rectangle};

    double totalArea = 0.0;
    for (const Shape* shape : shapes) {
        totalArea += shape->calculateArea();
    }

    std::cout << "Total Area: " << totalArea << std::endl;

    return 0;
}
