#include <iostream>
#include <iomanip>

const int numMonkeys = 3;
const int numDays = 5;

int main() {
    // Initialize a 2D array to store the pounds of food eaten by each monkey each day
    double foodConsumption[numMonkeys][numDays];

    // Input data for each monkey
    for (int monkey = 0; monkey < numMonkeys; ++monkey) {
        std::cout << "Enter pounds of food eaten by Monkey " << (monkey + 1) << " each day:\n";

        for (int day = 0; day < numDays; ++day) {
            do {
                std::cout << "Day " << (day + 1) << ": ";
                std::cin >> foodConsumption[monkey][day];

                // Input validation
                if (foodConsumption[monkey][day] < 0) {
                    std::cout << "Please enter a non-negative value.\n";
                }
            } while (foodConsumption[monkey][day] < 0);
        }
    }

    // Display the report
    std::cout << "\nFood Consumption Report:\n";
    std::cout << "-------------------------\n";

    double totalFood = 0.0;
    double minFood = foodConsumption[0][0];
    double maxFood = foodConsumption[0][0];

    // Calculate total food consumption and find the least and greatest amounts
    for (int monkey = 0; monkey < numMonkeys; ++monkey) {
        for (int day = 0; day < numDays; ++day) {
            totalFood += foodConsumption[monkey][day];

            if (foodConsumption[monkey][day] < minFood) {
                minFood = foodConsumption[monkey][day];
            }

            if (foodConsumption[monkey][day] > maxFood) {
                maxFood = foodConsumption[monkey][day];
            }
        }
    }

    // Calculate average amount of food eaten per day by the whole family
    double averageFood = totalFood / (numMonkeys * numDays);

    // Display the results
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Average amount of food eaten per day by the whole family: " << averageFood << " pounds\n";
    std::cout << "Least amount of food eaten during the week by any one monkey: " << minFood << " pounds\n";
    std::cout << "Greatest amount of food eaten during the week by any one monkey: " << maxFood << " pounds\n";

    return 0;
}
