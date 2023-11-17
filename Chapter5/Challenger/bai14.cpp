#include <iostream>
#include <string>

int main() {
    // Variables
    int numStudents;
    std::string firstName, firstInLine, lastInLine;

    // Get the number of students with validation
    do {
        std::cout << "Enter the number of students in the class (1-25): ";
        std::cin >> numStudents;

        if (numStudents < 1 || numStudents > 25) {
            std::cout << "Please enter a number between 1 and 25.\n";
        }
    } while (numStudents < 1 || numStudents > 25);

    // Loop to read names
    for (int i = 1; i <= numStudents; ++i) {
        std::cout << "Enter the name of student " << i << ": ";
        std::cin >> firstName;

        // Update first and last in line based on alphabetical order
        if (i == 1 || firstName < firstInLine) {
            firstInLine = firstName;
        }
        if (i == 1 || firstName > lastInLine) {
            lastInLine = firstName;
        }
    }

    // Display results
    std::cout << "\nAt the front of the line: " << firstInLine << std::endl;
    std::cout << "At the end of the line: " << lastInLine << std::endl;

    return 0;
}
