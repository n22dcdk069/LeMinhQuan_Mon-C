#include <iostream>
#include <cstring>

class Bike {
private:
    char* brand; // hiệu xe

public:
    // Constructor
    Bike(const char* b) {
        brand = new char[strlen(b) + 1];
        strcpy(brand, b);
    }

    // Destructor
    virtual ~Bike() {
        delete[] brand;
    }

    // Copy Constructor
    Bike(const Bike& other) {
        brand = new char[strlen(other.brand) + 1];
        strcpy(brand, other.brand);
    }

    // Copy Assignment Operator
    Bike& operator=(const Bike& other) {
        if (this != &other) {
            delete[] brand;
            brand = new char[strlen(other.brand) + 1];
            strcpy(brand, other.brand);
        }
        return *this;
    }

    virtual void move(int t1) {
        std::cout << brand << ":" << t1 * 12 << " ";
    }
};

class EBike : public Bike {
public:
    // Constructor
    EBike(const char* b) : Bike(b) {}

    void move(int t2) override {
        Bike::move(t2 * 2);
    }
};

void display(Bike& a, EBike& b) {
    a.move(2);
    b.move(2);
}

int main() {
    EBike b1("EBike1");
    EBike b2("EBike2");
    display(b1, b2);
    return 0;
}
