#include <iostream>

int* allocateIntArray(int size) {
    // Dynamically allocate an array of integers
    int* newArray = new int[size];

    // Check if allocation was successful
    if (!newArray) {
        std::cerr << "Memory allocation failed." << std::endl;
        // You may choose to handle the error in a different way, e.g., throw an exception
    }

    return newArray;
}

int main() {
    // Example of using the function
    int arraySize = 5;
    int* myArray = allocateIntArray(arraySize);

    // Now you can use 'myArray' as a dynamically allocated array

    // Don't forget to delete the allocated memory when you're done
    delete[] myArray;

    return 0;
}
