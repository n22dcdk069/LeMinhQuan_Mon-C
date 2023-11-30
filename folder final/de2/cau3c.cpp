#include <cmath>
#include <iostream>

class Function {
public:
    virtual double Value(double x) = 0;
    virtual double Derive(double x) = 0;
};

class Sin : public Function {
public:
    double Value(double x) override {
        return sin(x);
    }

    double Derive(double x) override {
        return cos(x);
    }
};

class Cos : public Function {
public:
    double Value(double x) override {
        return cos(x);
    }

    double Derive(double x) override {
        return -sin(x);
    }
};

class DerivableFunction : public Function {
public:
    // Hàm thương: (f / g)'
    static double DeriveQuotient(Function* f, Function* g, double x) {
        if (f != nullptr && g != nullptr) {
            double fPrime = f->Derive(x);
            double gPrime = g->Derive(x);
            double fValue = f->Value(x);
            double gValue = g->Value(x);

            if (gValue != 0) {
                return (fPrime * gValue - fValue * gPrime) / (gValue * gValue);
            }
        }

        std::cerr << "Error: Division by zero or invalid functions." << std::endl;
        return 0.0;
    }

    // Hàm hợp: (f ∘ g)'
    static double DeriveComposition(Function* f, Function* g, double x) {
        if (f != nullptr && g != nullptr) {
            double gValue = g->Value(x);
            double gPrime = g->Derive(x);

            return f->Derive(gValue) * gPrime;
        }

        std::cerr << "Error: Invalid functions." << std::endl;
        return 0.0;
    }
};

int main() {
    // Example usage:
    double x = 3.14 / 6;

    // Define two functions, for example, sin(x) and cos(x)
    Function* sinFunc = new Sin();
    Function* cosFunc = new Cos();

    // Calculate the derivative of the quotient: (sin(x) / cos(x))'
    double derivativeQuotient = DerivableFunction::DeriveQuotient(sinFunc, cosFunc, x);
    std::cout << "(sin(x) / cos(x))' at x = " << x << " is: " << derivativeQuotient << std::endl;

    // Calculate the derivative of the composition: (sin(cos(x)))'
    double derivativeComposition = DerivableFunction::DeriveComposition(sinFunc, cosFunc, x);
    std::cout << "(sin(cos(x)))' at x = " << x << " is: " << derivativeComposition << std::endl;

    delete sinFunc;
    delete cosFunc;

    return 0;
}
