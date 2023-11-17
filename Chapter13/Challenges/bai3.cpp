#include <iostream>
#include <string>

class Car {
private:
    int yearModel;
    std::string make;
    int speed;

public:
    // Constructor
    Car(int model, const std::string& carMake) : yearModel(model), make(carMake), speed(0) {}

    // Accessor functions
    int getYearModel() const {
        return yearModel;
    }

    std::string getMake() const {
        return make;
    }

    int getSpeed() const {
        return speed;
    }

    // Member functions
    void accelerate() {
        speed += 5;
    }

    void brake() {
        speed -= 5;
    }
};

class PersonalInformation {
private:
    std::string name;
    std::string address;
    int age;
    std::string phoneNumber;

public:
    // Mutator functions
    void setName(const std::string& n) {
        name = n;
    }

    void setAddress(const std::string& a) {
        address = a;
    }

    void setAge(int a) {
        age = a;
    }

    void setPhoneNumber(const std::string& phone) {
        phoneNumber = phone;
    }

    // Accessor functions
    std::string getName() const {
        return name;
    }

    std::string getAddress() const {
        return address;
    }

    int getAge() const {
        return age;
    }

    std::string getPhoneNumber() const {
        return phoneNumber;
    }
};

class RetailItem {
private:
    std::string description;
    int unitsOnHand;
    double price;

public:
    // Constructor
    RetailItem(const std::string& desc, int units, double itemPrice)
        : description(desc), unitsOnHand(units), price(itemPrice) {}

    // Mutator functions
    void setDescription(const std::string& desc) {
        description = desc;
    }

    void setUnitsOnHand(int units) {
        unitsOnHand = units;
    }

    void setPrice(double itemPrice) {
        price = itemPrice;
    }

    // Accessor functions
    std::string getDescription() const {
        return description;
    }

    int getUnitsOnHand() const {
        return unitsOnHand;
    }

    double getPrice() const {
        return price;
    }
};

int main() {
    // Demonstrate the Car class
    Car myCar(2022, "Toyota");

    for (int i = 0; i < 5; ++i) {
        myCar.accelerate();
        std::cout << "Current speed after acceleration: " << myCar.getSpeed() << " mph\n";
    }

    for (int i = 0; i < 5; ++i) {
        myCar.brake();
        std::cout << "Current speed after braking: " << myCar.getSpeed() << " mph\n";
    }

    // Demonstrate the PersonalInformation class
    PersonalInformation myInfo;
    myInfo.setName("Your Name");
    myInfo.setAddress("Your Address");
    myInfo.setAge(25);
    myInfo.setPhoneNumber("123-456-7890");

    PersonalInformation friend1, friend2;
    friend1.setName("Friend 1");
    friend1.setAddress("Friend 1's Address");
    friend1.setAge(30);
    friend1.setPhoneNumber("987-654-3210");

    friend2.setName("Friend 2");
    friend2.setAddress("Friend 2's Address");
    friend2.setAge(28);
    friend2.setPhoneNumber("111-222-3333");

    // Demonstrate the RetailItem class
    RetailItem item1("Jacket", 12, 59.95);
    RetailItem item2("Designer Jeans", 40, 34.95);
    RetailItem item3("Shirt", 20, 24.95);

    // Displaying RetailItem data
    std::cout << "\nRetail Items Information:\n";
    std::cout << "Item #1: " << item1.getDescription() << ", Units: " << item1.getUnitsOnHand()
              << ", Price: $" << item1.getPrice() << std::endl;

    std::cout << "Item #2: " << item2.getDescription() << ", Units: " << item2.getUnitsOnHand()
              << ", Price: $" << item2.getPrice() << std::endl;

    std::cout << "Item #3: " << item3.getDescription() << ", Units: " << item3.getUnitsOnHand()
              << ", Price: $" << item3.getPrice() << std::endl;

    return 0;
}
