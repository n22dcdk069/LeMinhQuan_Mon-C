#include <iostream>

// Function prototypes
void inputDonations(double*& donations, int numDonations);
void displayDonations(const double* donations, int numDonations);
void sortDonations(double* donations, int numDonations);
double calculateAverage(const double* donations, int numDonations);

int main() {
    int numDonations;

    // Get the number of donations from the user
    std::cout << "Enter the number of donations: ";
    std::cin >> numDonations;

    // Validate the number of donations
    while (numDonations <= 0) {
        std::cout << "Please enter a positive number of donations: ";
        std::cin >> numDonations;
    }

    // Dynamically allocate an array for donations
    double* donations = new double[numDonations];

    // Input donations
    inputDonations(donations, numDonations);

    // Sort the donations
    sortDonations(donations, numDonations);

    // Display the sorted donations
    displayDonations(donations, numDonations);

    // Calculate the average donation
    double average = calculateAverage(donations, numDonations);
    std::cout << "Average Donation: " << average << std::endl;

    // Deallocate the dynamically allocated memory
    delete[] donations;

    return 0;
}

void inputDonations(double*& donations, int numDonations) {
    std::cout << "Enter the donations:\n";
    for (int i = 0; i < numDonations; ++i) {
        std::cout << "Donation " << i + 1 << ": ";
        std::cin >> *(donations + i);
    }
}

void displayDonations(const double* donations, int numDonations) {
    std::cout << "Sorted Donations:\n";
    for (int i = 0; i < numDonations; ++i) {
        std::cout << "Donation " << i + 1 << ": " << *(donations + i) << "\n";
    }
}

void sortDonations(double* donations, int numDonations) {
    std::sort(donations, donations + numDonations);
}

double calculateAverage(const double* donations, int numDonations) {
    double sum = 0.0;
    for (int i = 0; i < numDonations; ++i) {
        sum += *(donations + i);
    }
    return sum / numDonations;
}
