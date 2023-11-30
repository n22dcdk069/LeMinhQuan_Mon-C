#include <iostream>

class ComplexNumber {
private:
    int real;   // Phần thực
    int imag;   // Phần ảo

public:
    // Hàm tạo
    ComplexNumber(int r, int i) : real(r), imag(i) {}

    // Hàm nhập
    void input() {
        std::cout << "Nhập phần thực: ";
        std::cin >> real;
        std::cout << "Nhập phần ảo: ";
        std::cin >> imag;
    }

    // Hàm xuất
    void output() const {
        std::cout << real;
        if (imag >= 0) {
            std::cout << " + " << imag << "sprt7";
        } else {
            std::cout << " - " << -imag << "sprt7";
        }
        std::cout << std::endl;
    }

    // Hàm đổi dấu
    void negate() {
        real = -real;
        imag = -imag;
    }

    // Phép cộng
    ComplexNumber add(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    // Phép trừ
    ComplexNumber subtract(const ComplexNumber& other) const {
        return ComplexNumber(real - other.real, imag - other.imag);
    }

    // Phép nhân
    ComplexNumber multiply(const ComplexNumber& other) const {
        int newReal = real * other.real + 7 * imag * other.imag;
        int newImag = imag * other.real + real * other.imag;
        return ComplexNumber(newReal, newImag);
    }
};

int main() {
    ComplexNumber num1(3, 2);
    ComplexNumber num2(1, -4);

    // Thực hiện các phép toán và xuất kết quả
    ComplexNumber sum = num1.add(num2);
    ComplexNumber difference = num1.subtract(num2);
    ComplexNumber product = num1.multiply(num2);

    std::cout << "Tổng: ";
    sum.output();

    std::cout << "Hiệu: ";
    difference.output();

    std::cout << "Tích: ";
    product.output();

    return 0;
}
