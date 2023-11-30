#include <cmath>
#include <iostream>

class Function {
public:
    virtual double Value(double x) = 0;
    virtual double Derive(double x) = 0;
};

class Cos : public Function {
public:
    double Value(double x) override {
        return cos(x);
    }

    double Derive(double x) override {
        return -sin(x); // Correctly overrides the pure virtual function
    }
};

int main() {
    double x = 3.14 / 6;

    // Using the Cos class
    Cos* cosFunc = new Cos();
    double y = cosFunc->Value(x);
    double yPrime = cosFunc->Derive(x);

    std::cout << "cos(x) = " << y << "; cos'(x) = " << yPrime << std::endl;

    delete cosFunc;

    return 0;
}
