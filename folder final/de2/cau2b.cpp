#include <iostream>

// Lớp trừu tượng
class Shape {
public:
    // Phương thức ảo thuần ảo
    virtual void draw() const = 0;

    // Phương thức ảo có cài đặt
    virtual double area() const {
        std::cout << "Area of the shape (base class)" << std::endl;
        return 0.0;
    }

    // Hàm thành viên thông thường
    void commonOperation() {
        std::cout << "Common operation for shapes" << std::endl;
    }

    // Hủy ảo
    virtual ~Shape() {
        std::cout << "Destructor of the base class" << std::endl;
    }
};

// Lớp con kế thừa từ lớp trừu tượng
class Circle : public Shape {
public:
    // Triển khai phương thức ảo draw
    void draw() const override {
        std::cout << "Drawing a circle" << std::endl;
    }

    // Triển khai phương thức ảo area
    double area() const override {
        std::cout << "Area of the circle" << std::endl;
        return 3.14; // Giả sử diện tích là 3.14
    }

    // Hủy ảo
    ~Circle() override {
        std::cout << "Destructor of the Circle class" << std::endl;
    }
};

int main() {
    // Không thể khởi tạo đối tượng từ lớp trừu tượng
    // Shape shape; // Lỗi!

    // Tuy nhiên, có thể khai báo con trỏ hoặc tham chiếu từ lớp trừu tượng
    Shape* shapePtr = new Circle();
    shapePtr->draw();
    shapePtr->area();
    shapePtr->commonOperation();

    delete shapePtr; // Dùng delete để giải phóng bộ nhớ khi sử dụng new

    return 0;
}
