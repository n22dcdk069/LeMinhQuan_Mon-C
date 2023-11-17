#include <iostream>

// Function prototype
int* expandArray(const int* arr, int size);

int main() {
    const int size = 5;
    int originalArray[size] = {1, 2, 3, 4, 5};

    // Call the function to expand the array
    int* expandedArray = expandArray(originalArray, size);

    // Display the original and expanded arrays
    std::cout << "Original Array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << originalArray[i] << " ";
    }

    std::cout << "\nExpanded Array: ";
    for (int i = 0; i < size + 1; ++i) {
        std::cout << expandedArray[i] << " ";
    }

    // Deallocate the dynamically allocated memory
    delete[] expandedArray;

    return 0;
}

int* expandArray(const int* arr, int size) {
    // Dynamically allocate memory for the expanded array
    int* expandedArray = new int[size + 1];

    // Set the first element of the new array to 0
    expandedArray[0] = 0;

    // Copy elements from the original array to the new array
    for (int i = 0; i < size; ++i) {
        expandedArray[i + 1] = arr[i];
    }

    // Return a pointer to the expanded array
    return expandedArray;
}
