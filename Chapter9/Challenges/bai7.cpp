#include <iostream>
#include <algorithm> // for std::sort

int main() {
    const int arrSize = 5;
    int arrptr[arrSize] = {4, 1, 7, 3, 9};

    // Sort the array in descending order using std::sort with a custom comparator
    std::sort(arrptr, arrptr + arrSize, std::greater<int>());

    // Print the sorted array
    std::cout << "Sorted array in descending order: ";
    for (int i = 0; i < arrSize; ++i) {
        std::cout << arrptr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
