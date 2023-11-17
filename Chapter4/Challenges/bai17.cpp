#include <iostream>
#include <vector>
#include <algorithm> // For sorting

struct Vault {
    std::string date;
    double height;
};

bool compareVaults(const Vault& v1, const Vault& v2) {
    return v1.height > v2.height; // Sort in descending order of height
}

int main() {
    // Input variables
    std::string vaulterName;
    std::vector<Vault> vaults;

    // Get vaulter's name
    std::cout << "Enter the name of the pole vaulter: ";
    std::getline(std::cin, vaulterName);

    // Get information for each vault
    for (int i = 1; i <= 3; ++i) {
        Vault vault;
        std::cout << "Enter the date of the " << i << " vault: ";
        std::getline(std::cin, vault.date);

        do {
            std::cout << "Enter the height of the vault (between 2.0 and 5.0 meters): ";
            std::cin >> vault.height;

            // Input validation for vault height
            if (vault.height < 2.0 || vault.height > 5.0) {
                std::cout << "Invalid height. Please enter a height between 2.0 and 5.0 meters." << std::endl;
            }

        } while (vault.height < 2.0 || vault.height > 5.0);

        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Add the vault to the vector
        vaults.push_back(vault);
    }

    // Sort vaults in descending order of height
    std::sort(vaults.begin(), vaults.end(), compareVaults);

    // Display the results
    std::cout << "\nBest vaults for " << vaulterName << " in order of height:\n";
    for (const auto& vault : vaults) {
        std::cout << "Date: " << vault.date << ", Height: " << vault.height << " meters\n";
    }

    return 0;
}
