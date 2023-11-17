#include <iostream>

// Function prototype
int* reverseArray(const int* arr, int size);

int main() {
    const int size = 5;
    int originalArray[size] = {1, 2, 3, 4, 5};

    // Call the function to reverse the array
    int* reversedArray = reverseArray(originalArray, size);

    // Display the original and reversed arrays
    std::cout << "Original Array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << originalArray[i] << " ";
    }

    std::cout << "\nReversed Array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << reversedArray[i] << " ";
    }

    // Deallocate the dynamically allocated memory
    delete[] reversedArray;

    return 0;
}

int* reverseArray(const int* arr, int size) {
    // Dynamically allocate memory for the reversed array
    int* reversedArray = new int[size];

    // Copy and reverse the elements
    for (int i = 0; i < size; ++i) {
        reversedArray[i] = arr[size - 1 - i];
    }

    // Return a pointer to the reversed array
    return reversedArray;
}
