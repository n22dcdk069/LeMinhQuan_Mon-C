#include <iostream>

class NumberArray {
private:
    float* numbers; // Array of floating-point numbers
    int size;       // Size of the array

public:
    // Constructor
    NumberArray(int arraySize) {
        size = arraySize;
        numbers = new float[size];
    }

    // Destructor
    ~NumberArray() {
        delete[] numbers;
    }

    // Store a number in any element of the array
    void setElement(int index, float value) {
        if (index >= 0 && index < size) {
            numbers[index] = value;
        } else {
            std::cerr << "Error: Index out of bounds.\n";
        }
    }

    // Retrieve a number from any element of the array
    float getElement(int index) const {
        if (index >= 0 && index < size) {
            return numbers[index];
        } else {
            std::cerr << "Error: Index out of bounds. Returning 0.0.\n";
            return 0.0;
        }
    }

    // Return the highest value stored in the array
    float getHighest() const {
        float highest = numbers[0];
        for (int i = 1; i < size; ++i) {
            if (numbers[i] > highest) {
                highest = numbers[i];
            }
        }
        return highest;
    }

    // Return the lowest value stored in the array
    float getLowest() const {
        float lowest = numbers[0];
        for (int i = 1; i < size; ++i) {
            if (numbers[i] < lowest) {
                lowest = numbers[i];
            }
        }
        return lowest;
    }

    // Return the average of all the numbers stored in the array
    float getAverage() const {
        float sum = 0.0;
        for (int i = 0; i < size; ++i) {
            sum += numbers[i];
        }
        return (size > 0) ? (sum / size) : 0.0;
    }
};

int main() {
    // Demonstrate the NumberArray class
    int arraySize;
    std::cout << "Enter the size of the array: ";
    std::cin >> arraySize;

    // Create a NumberArray object
    NumberArray myArray(arraySize);

    // Store numbers in the array
    for (int i = 0; i < arraySize; ++i) {
        float value;
        std::cout << "Enter value for element " << i << ": ";
        std::cin >> value;
        myArray.setElement(i, value);
    }

    // Display array information
    std::cout << "\nArray Information:\n";
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "Element " << i << ": " << myArray.getElement(i) << "\n";
    }

    std::cout << "Highest Value: " << myArray.getHighest() << "\n";
    std::cout << "Lowest Value: " << myArray.getLowest() << "\n";
    std::cout << "Average: " << myArray.getAverage() << "\n";

    return 0;
}
