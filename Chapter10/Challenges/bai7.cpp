#include <iostream>
#include <cstring> // For C-string functions

int main() {
    const int MAX_NAME_LENGTH = 50;

    // Arrays to store first, middle, last names, and the formatted name
    char firstName[MAX_NAME_LENGTH];
    char middleName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char formattedName[MAX_NAME_LENGTH * 3]; // Assuming the formatted name won't exceed three times the length of the input

    // Get user input
    std::cout << "Enter your first name: ";
    std::cin.getline(firstName, MAX_NAME_LENGTH);

    std::cout << "Enter your middle name: ";
    std::cin.getline(middleName, MAX_NAME_LENGTH);

    std::cout << "Enter your last name: ";
    std::cin.getline(lastName, MAX_NAME_LENGTH);

    // Create the formatted name
    strcpy(formattedName, lastName);
    strcat(formattedName, ", ");
    strcat(formattedName, firstName);
    strcat(formattedName, " ");
    strcat(formattedName, middleName);

    // Display the formatted name
    std::cout << "Formatted Name: " << formattedName << std::endl;

    return 0;
}
