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
};

class EyedFace : public Face {
private:
    int eyes;

public:
    // Constructor
    EyedFace(std::string sh, int e) : Face(sh), eyes(e) {}

    // Clone method
    virtual IFace* clone() override {
        return new EyedFace(*this);
    }

    // Show method
    virtual void show() override {
        Face::show();
        std::cout << "Eyes: " << eyes << std::endl;
    }
};

int main() {
    // Example usage
    EyedFace eyedFace1("Circle", 2);
    EyedFace* clonedEyedFace = dynamic_cast<EyedFace*>(eyedFace1.clone());

    // Display original EyedFace
    std::cout << "Original EyedFace:" << std::endl;
    eyedFace1.show();

    // Display cloned EyedFace
    std::cout << "\nCloned EyedFace:" << std::endl;
    clonedEyedFace->show();

    delete clonedEyedFace;  // Don't forget to free memory

    return 0;
}

