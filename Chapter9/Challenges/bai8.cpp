#include <iostream>
#include <unordered_map>

int findMode(const int* array, int size);

int main() {
    const int size = 10;
    int values[size] = {1, 2, 3, 4, 2, 6, 7, 2, 9, 10};

    int mode = findMode(values, size);

    if (mode != -1) {
        std::cout << "The mode is: " << mode << std::endl;
    } else {
        std::cout << "The array has no mode." << std::endl;
    }

    return 0;
}

int findMode(const int* array, int size) {
    if (size == 0) {
        // Empty array, no mode
        return -1;
    }

    // Use unordered_map to count occurrences of each value
    std::unordered_map<int, int> valueCount;

    // Traverse the array using pointers
    for (const int* ptr = array; ptr < array + size; ++ptr) {
        // Increment the count for the current value
        valueCount[*ptr]++;
    }

    // Find the mode (value with the highest count)
    int mode = -1;
    int maxCount = 0;

    for (const auto& pair : valueCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mode = pair.first;
        }
    }

    return mode;
}
