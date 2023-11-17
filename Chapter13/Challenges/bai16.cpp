#include <iostream>

class Temperature {
private:
    double temperature;

public:
    // Constructor
    Temperature(double temp) : temperature(temp) {}

    // Accessor and Mutator functions
    double getTemperature() const {
        return temperature;
    }

    void setTemperature(double temp) {
        temperature = temp;
    }

    // Member functions to check freezing and boiling points
    bool isEthylFreezing() const {
        return temperature <= -173;
    }

    bool isEthylBoiling() const {
        return temperature >= 172;
    }

    bool isOxygenFreezing() const {
        return temperature <= -362;
    }

    bool isOxygenBoiling() const {
        return temperature >= -306;
    }

    bool isWaterFreezing() const {
        return temperature <= 32;
    }

    bool isWaterBoiling() const {
        return temperature >= 212;
    }
};

int main() {
    // Get user input for temperature
    double userTemperature;
    std::cout << "Enter a temperature: ";
    std::cin >> userTemperature;

    // Create Temperature object
    Temperature userTemp(userTemperature);

    // Display substances that will freeze and boil at the entered temperature
    std::cout << "Substances that will freeze at " << userTemp.getTemperature() << " degrees:\n";
    if (userTemp.isEthylFreezing()) {
        std::cout << "Ethyl Alcohol\n";
    }
    if (userTemp.isOxygenFreezing()) {
        std::cout << "Oxygen\n";
    }
    if (userTemp.isWaterFreezing()) {
        std::cout << "Water\n";
    }

    std::cout << "\nSubstances that will boil at " << userTemp.getTemperature() << " degrees:\n";
    if (userTemp.isEthylBoiling()) {
        std::cout << "Ethyl Alcohol\n";
    }
    if (userTemp.isOxygenBoiling()) {
        std::cout << "Oxygen\n";
    }
    if (userTemp.isWaterBoiling()) {
        std::cout << "Water\n";
    }

    return 0;
}
