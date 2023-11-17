#include <iostream>

int main() {
    // Define the variables to store the values
    int value1 = 28;
    int value2 = 32;
    int value3 = 37;
    int value4 = 24;
    int value5 = 33;

    // Calculate the sum of the values
    int sum = value1 + value2 + value3 + value4 + value5;

    // Calculate the average by dividing the sum by the number of values
    double average = static_cast<double>(sum) / 5;

    // Display the average
    std::cout << "The average of the values is: " << average << std::endl;

    return 0;
}
