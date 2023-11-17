#include <iostream>

double calculateMedian(const int* arr, int size) {
    // If the size of the array is even, calculate the average of the two middle values
    if (size % 2 == 0) {
        const int* middle1 = arr + (size / 2) - 1;
        const int* middle2 = arr + (size / 2);
        return static_cast<double>(*middle1 + *middle2) / 2.0;
    }
    // If the size is odd, return the middle value
    else {
        const int* middle = arr + (size / 2);
        return static_cast<double>(*middle);
    }
}

int main() {
    // Example usage
    const int size = 6;
    int sortedArray[size] = {1, 3, 5, 7, 9, 11};

    // Calculate the median using the function
    double median = calculateMedian(sortedArray, size);

    // Display the result
    std::cout << "Median: " << median << std::endl;

    return 0;
}
