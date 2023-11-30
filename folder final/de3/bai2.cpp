#include <iostream>

class Base {
public:
    // Hàm hủy ảo
    virtual ~Base() {
        std::cout << "Base destructor called." << std::endl;
    }
};

class Derived : public Base {
public:
    // Hàm hủy ảo (không cần khai báo virtual vì nó kế thừa từ Base)
    ~Derived() {
        std::cout << "Derived destructor called." << std::endl;
    }
};

int main() {
    // Tạo đối tượng của lớp dẫn xuất
    Base* obj = new Derived();

    // Hủy đối tượng
    delete obj;

    return 0;
}
