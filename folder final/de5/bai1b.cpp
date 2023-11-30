#include <iostream>

class A {
public:
    virtual void f(int x) { std::cout << x << " "; }
};

class B : public A {
public:
    void f(int y) override { A::f(y + 1); }
};

void doSomething(A a, B b) {
    a.f(3);
    b.f(3);
}

int main() {
    B x, y;
    doSomething(x, y);

    return 0;
}
