#include <iostream>

class Singleton {
private:
    // Private constructor để ngăn chặn việc tạo đối tượng từ bên ngoài
    Singleton() {}

    // Ngăn chặn sao chép và gán từ bên ngoài
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

public:
    // Phương thức lấy thể hiện duy nhất của lớp Singleton
    static Singleton& getInstance() {
        static Singleton instance; // Đảm bảo tạo đối tượng chỉ một lần
        return instance;
    }

    // Các phương thức và dữ liệu khác của lớp Singleton
    void someMethod() {
        std::cout << "Executing some method..." << std::endl;
    }
};

int main() {
    // Không thể tạo đối tượng Singleton thông qua constructor
    // Singleton obj; // Lỗi: 'Singleton::Singleton()' is private within this context

    // Lấy thể hiện duy nhất của Singleton
    Singleton& singletonInstance = Singleton::getInstance();

    // Sử dụng các phương thức và dữ liệu của Singleton
    singletonInstance.someMethod();

    return 0;
}
