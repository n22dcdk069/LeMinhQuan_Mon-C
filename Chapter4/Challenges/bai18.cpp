#include <iostream>

int main() {
    // Constants for calories from fat per gram and percentage threshold
    const double CALORIES_PER_FAT_GRAM = 9.0;
    const double MAX_FAT_PERCENTAGE = 30.0;

    // Variables to store user input
    double calories, fatGrams;

    // Get input for the number of calories
    std::cout << "Enter the number of calories in the food: ";
    std::cin >> calories;

    // Validate the input for calories
    if (calories < 0) {
        std::cout << "Error: Calories cannot be less than 0.\n";
        return 1; // Exit the program with an error code
    }

    // Get input for the number of fat grams
    std::cout << "Enter the number of fat grams in the food: ";
    std::cin >> fatGrams;

    // Validate the input for fat grams
    if (fatGrams < 0 || fatGrams > calories) {
        std::cout << "Error: Invalid input for fat grams.\n";
        return 1; // Exit the program with an error code
    }

    // Calculate calories from fat
    double caloriesFromFat = fatGrams * CALORIES_PER_FAT_GRAM;

    // Calculate the percentage of calories from fat
    double fatPercentage = (caloriesFromFat / calories) * 100;

    // Display the results with two decimal places
    std::cout << "Percentage of calories from fat: " << fatPercentage << "%\n";

    // Display a message if the food is low in fat
    if (fatPercentage < MAX_FAT_PERCENTAGE) {
        std::cout << "This food is low in fat.\n";
    }

    return 0;
}
