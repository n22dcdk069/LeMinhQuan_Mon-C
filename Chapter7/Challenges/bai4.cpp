#include <iostream>

void displayNumbersGreaterThanN(int arr[], int size, int n) {
    std::cout << "Numbers greater than " << n << ": ";
    for (int i = 0; i < size; ++i) {
        if (arr[i] > n) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    const int SIZE = 5;
    int numbers[SIZE] = {10, 5, 20, 15, 25};
    int n;

    // Get the value of n from the user
    std::cout << "Enter a number (n): ";
    std::cin >> n;

    // Call the function to display numbers greater than n
    displayNumbersGreaterThanN(numbers, SIZE, n);

    return 0;
}
