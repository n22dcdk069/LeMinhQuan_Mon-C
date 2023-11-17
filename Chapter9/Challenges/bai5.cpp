#include <iostream>

int doSomething(int* x, int* y) {
    int temp = *x;
    *x = (*y) * 10;
    *y = temp * 10;
    return (*x) + (*y);
}

int main() {
    int a = 5;
    int b = 3;

    std::cout << "Before calling doSomething:\n";
    std::cout << "a = " << a << ", b = " << b << "\n\n";

    int result = doSomething(&a, &b);

    std::cout << "After calling doSomething:\n";
    std::cout << "a = " << a << ", b = " << b << "\n";
    std::cout << "Result: " << result << "\n";

    return 0;
}
