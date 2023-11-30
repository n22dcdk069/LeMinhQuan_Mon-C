#include <iostream>
#include <cstring>
#include <cctype>

class BigInteger {
private:
    char* number;

public:
    // Constructor mặc định
    BigInteger() : number(nullptr) {}

    // Constructor từ chuỗi
    BigInteger(const char* str) {
        // Xóa các ký tự không phải số và khoảng trắng
        int len = strlen(str);
        char* temp = new char[len + 1];
        int j = 0;
        for (int i = 0; i < len; ++i) {
            if (isdigit(str[i]) || str[i] == ' ') {
                temp[j++] = str[i];
            }
        }
        temp[j] = '\0';

        // Xóa các khoảng trắng ở đầu và cuối
        while (j > 0 && temp[j - 1] == ' ') {
            --j;
        }
        temp[j] = '\0';

        number = new char[j + 1];
        strcpy(number, temp);
        delete[] temp;
    }

    // Destructor
    ~BigInteger() {
        delete[] number;
    }

    // Phương thức in số nguyên lớn
    void print() const {
        std::cout << number;
    }

    // Toán tử so sánh bằng
    bool operator==(const BigInteger& other) const {
        return strcmp(number, other.number) == 0;
    }

    // Toán tử nhập
    friend std::istream& operator>>(std::istream& is, BigInteger& obj) {
        char buffer[1000];
        is.getline(buffer, 1000);
        obj = BigInteger(buffer);
        return is;
    }
};

int main() {
    BigInteger n1(" 1234567891011 ");
    BigInteger n2;

    std::cout << "Input an integer = ";
    std::cin >> n2;

    if (n1 == n2)
        std::cout << "Equal.\n";
    else
        std::cout << "Not equal.\n";

    return 0;
}
