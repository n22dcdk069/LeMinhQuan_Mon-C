#include <iostream>

int main() {
    const int size = 10;
    int values[size];

    // Input values into the array
    std::cout << "Enter 10 values:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter value " << (i + 1) << ": ";
        std::cin >> values[i];
    }

    // Find the largest and smallest values
    int largest = values[0];
    int smallest = values[0];

    for (int i = 1; i < size; ++i) {
        if (values[i] > largest) {
            largest = values[i];
        }

        if (values[i] < smallest) {
            smallest = values[i];
        }
    }

    // Display the results
    std::cout << "Largest value: " << largest << std::endl;
    std::cout << "Smallest value: " << smallest << std::endl;

    return 0;
}
