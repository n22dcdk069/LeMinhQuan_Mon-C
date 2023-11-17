#include <iostream>

int* doubleArraySize(const int* arr, int size) {
    // Create a new array with twice the size
    int newSize = 2 * size;
    int* newArray = new int[newSize];

    // Copy the contents of the argument array to the new array
    for (int i = 0; i < size; ++i) {
        newArray[i] = arr[i];
    }

    // Initialize the unused elements of the second array with 0
    for (int i = size; i < newSize; ++i) {
        newArray[i] = 0;
    }

    return newArray;
}

int main() {
    // Example usage
    const int size = 5;
    int originalArray[size] = {1, 2, 3, 4, 5};

    // Call the function to double the size of the array
    int* newArray = doubleArraySize(originalArray, size);

    // Display the contents of the new array
    std::cout << "New array: ";
    for (int i = 0; i < 2 * size; ++i) {
        std::cout << newArray[i] << " ";
    }
    std::cout << std::endl;

    // Don't forget to delete the dynamically allocated memory
    delete[] newArray;

    return 0;
}
