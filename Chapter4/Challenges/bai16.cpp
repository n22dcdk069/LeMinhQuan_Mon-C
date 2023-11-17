#include <iostream>
#include <string>

int main() {
    // Variables to store runner information
    std::string runner1, runner2, runner3;
    double time1, time2, time3;

    // Get input for the first runner
    std::cout << "Enter the name of the first runner: ";
    std::cin >> runner1;
    std::cout << "Enter the finishing time for " << runner1 << " (in seconds): ";
    std::cin >> time1;

    // Validate the input for the first runner's time
    if (time1 < 0) {
        std::cout << "Error: Finishing time must be a positive number.\n";
        return 1; // Exit the program with an error code
    }

    // Get input for the second runner
    std::cout << "Enter the name of the second runner: ";
    std::cin >> runner2;
    std::cout << "Enter the finishing time for " << runner2 << " (in seconds): ";
    std::cin >> time2;

    // Validate the input for the second runner's time
    if (time2 < 0) {
        std::cout << "Error: Finishing time must be a positive number.\n";
        return 1; // Exit the program with an error code
    }

    // Get input for the third runner
    std::cout << "Enter the name of the third runner: ";
    std::cin >> runner3;
    std::cout << "Enter the finishing time for " << runner3 << " (in seconds): ";
    std::cin >> time3;

    // Validate the input for the third runner's time
    if (time3 < 0) {
        std::cout << "Error: Finishing time must be a positive number.\n";
        return 1; // Exit the program with an error code
    }

    // Determine the rankings and display the results
    if (time1 < time2 && time1 < time3) {
        std::cout << "1st Place: " << runner1 << std::endl;
        if (time2 < time3) {
            std::cout << "2nd Place: " << runner2 << std::endl;
            std::cout << "3rd Place: " << runner3 << std::endl;
        } else {
            std::cout << "2nd Place: " << runner3 << std::endl;
            std::cout << "3rd Place: " << runner2 << std::endl;
        }
    } else if (time2 < time1 && time2 < time3) {
        std::cout << "1st Place: " << runner2 << std::endl;
        if (time1 < time3) {
            std::cout << "2nd Place: " << runner1 << std::endl;
            std::cout << "3rd Place: " << runner3 << std::endl;
        } else {
            std::cout << "2nd Place: " << runner3 << std::endl;
            std::cout << "3rd Place: " << runner1 << std::endl;
        }
    } else {
        std::cout << "1st Place: " << runner3 << std::endl;
        if (time1 < time2) {
            std::cout << "2nd Place: " << runner1 << std::endl;
            std::cout << "3rd Place: " << runner2 << std::endl;
        } else {
            std::cout << "2nd Place: " << runner2 << std::endl;
            std::cout << "3rd Place: " << runner1 << std::endl;
        }
    }

    return 0;
}
