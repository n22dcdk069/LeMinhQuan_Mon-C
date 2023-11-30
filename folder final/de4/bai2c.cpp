#include <iostream>
#include <string>

// Forward declaration
class IFace;

// Interface class
class IFace {
public:
    virtual ~IFace() {}
    virtual void show() const = 0;
    virtual IFace* clone() const = 0;
};

// Base class
class Face : public IFace {
private:
    std::string shape;

public:
    // Constructor
    Face(const std::string& sh) : shape(sh) {}

    // Destructor
    virtual ~Face() {}

    // Show method
    virtual void show() const override {
        std::cout << "Shape: " << shape << std::endl;
    }

    // Clone method
    virtual IFace* clone() const override {
        return new Face(*this);
    }
};

// Derived class
class EyedFace : public Face {
private:
    static int objectCount;

protected:
    int eyes;

public:
    // Constructor
    EyedFace(const std::string& sh, int e) : Face(sh), eyes(e) {
        objectCount++;
    }

    // Destructor
    virtual ~EyedFace() {
        objectCount--;
    }

    // Clone method
    virtual IFace* clone() const override {
        return new EyedFace(*this);
    }

    // Static method to get object count
    static int getObjectCount() {
        return objectCount;
    }
};

// Initialize static variable
int EyedFace::objectCount = 0;

// Function to test Face
void testFace(const IFace* fc) {
    const IFace* a[3] = { fc, fc->clone(), fc->clone() };
    for (int i = 0; i < 3; i++) {
        a[i]->show();
        delete a[i];
    }
    std::cout << "The same 3 lines?" << std::endl;
}

// Main function
int main() {
    EyedFace fc("Rectangle", 2);
    testFace(&fc);

    // Check the number of EyedFace objects in memory
    std::cout << "Number of EyedFace objects: " << EyedFace::getObjectCount() << std::endl;

    return 0;
}
