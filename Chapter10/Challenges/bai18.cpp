#include <iostream>
#include <string>

const int ARRAY_SIZE = 10;

int main() {
    std::string phoneBook[ARRAY_SIZE] = {
        "Alejandra Cruz, 555-1223",
        "Joe Looney, 555-0097",
        "Geri Palmer, 555-8787",
        "Li Chen, 555-1212",
        "Holly Gaddis, 555-8878",
        "Sam Wiggins, 555-0998",
        "Bob Kain, 555-8712",
        "Tim Haynes, 555-7676",
        "Warren Gaddis, 555-9037",
        "Jean James, 555-4939",
        "Ron Palmer, 555-2783"
    };

    std::cout << "Enter a name or partial name to search for: ";
    std::string searchTerm;
    std::getline(std::cin, searchTerm);

    bool found = false;

    // Search for the entered name in the array
    for (const std::string& entry : phoneBook) {
        if (entry.find(searchTerm) != std::string::npos) {
            std::cout << entry << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No matching entries found." << std::endl;
    }

    return 0;
}
