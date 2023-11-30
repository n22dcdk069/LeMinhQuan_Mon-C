#include <math.h>
#include <stdio.h>

class Function {
public:
    virtual double Value(double x) = 0;
    virtual double Derive(double x) = 0;
};

class Sin : public Function {
private:
    // Đối tượng Sin duy nhất được tạo
    static Sin* instance;

    // Constructor private để ngăn việc tạo đối tượng từ bên ngoài
    Sin() {}

public:
    // Phương thức lấy đối tượng Sin duy nhất
    static Sin* getInstance() {
        if (!instance) {
            instance = new Sin();
        }
        return instance;
    }

    // Hủy bỏ constructor và operator= để ngăn chặn việc tạo bản sao
    Sin(Sin const&) = delete;
    void operator=(Sin const&) = delete;

    double Value(double x) override {
        return sin(x);
    }

    double Derive(double x) override {
        return cos(x);
    }
};

// Khởi tạo biến static
Sin* Sin::instance = nullptr;

double DeriveProduct(Function* f, Function* g, double x) {
    if (f != nullptr && g != nullptr) {
        return f->Derive(x) * g->Value(x) + f->Value(x) * g->Derive(x);
    }
    return 0;
}

double DeriveSum(Function* f, Function* g, double x) {
    if (f != nullptr && g != nullptr) {
        return f->Derive(x) + g->Derive(x);
    }
    return 0;
}

int main() {
    double x = 3.14 / 6; // PI/6
    Sin* s = Sin::getInstance();

    double y_product = DeriveProduct(s, s, x);
    printf("sin(x) = %f; sin'(x) = %f\n", s->Value(x), s->Derive(x));
    printf("y_product = %f\n", y_product);

    // Không cần delete vì getInstance trả về con trỏ static
    return 0;
}
