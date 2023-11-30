#include <iostream>
#include <string>

class IFace {
public:
    virtual void show() = 0;
    virtual IFace* clone() = 0;
    virtual ~IFace() {}
};

class Face : public IFace {
private:
    std::string shape;

protected:
    std::string getShape() {
        return shape;
    }

public:
    Face(std::string sh) : shape(sh) {}

    virtual void show() override {
        std::cout << "Shape: " << shape << std::endl;
    }

    virtual IFace* clone() override {
        return new Face(*this);
    }
};

class EyedFace : public Face {
private:
    int eyes;

public:
    EyedFace(std::string sh, int e) : Face(sh), eyes(e) {}

    virtual IFace* clone() override {
        return new EyedFace(*this);
    }

    virtual void show() override {
        Face::show();
        std::cout << "Eyes: " << eyes << std::endl;
    }
};

void testFace(IFace* fc) {
    IFace* a[3] = {fc, fc->clone(), fc->clone()};
    for (int i = 0; i < 3; i++) {
        a[i]->show();
    }
    std::cout << "The same 3 lines?" << std::endl;
}

int main() {
    EyedFace fc("Rectangle", 2);  // Change to EyedFace
    testFace(&fc);
    return 0;
}
