#include <iostream>
#include <string>

// Define the MonthlyBudget structure
struct MonthlyBudget {
    double housing;
    double utilities;
    double householdExpenses;
    double transportation;
    double food;
    double medical;
    double insurance;
    double entertainment;
    double clothing;
    double miscellaneous;
};

// Function prototypes
void enterExpenses(MonthlyBudget& budget);
void displayBudgetReport(const MonthlyBudget& budget);

int main() {
    MonthlyBudget monthlyBudget;

    // Ask the user to enter the amounts spent in each budget category
    enterExpenses(monthlyBudget);

    // Display a report indicating the amount over or under in each category
    // and the amount over or under for the entire monthly budget
    displayBudgetReport(monthlyBudget);

    return 0;
}

void enterExpenses(MonthlyBudget& budget) {
    std::cout << "Enter the amounts spent in each budget category for the month:\n";

    std::cout << "Housing: $";
    std::cin >> budget.housing;

    std::cout << "Utilities: $";
    std::cin >> budget.utilities;

    std::cout << "Household Expenses: $";
    std::cin >> budget.householdExpenses;

    std::cout << "Transportation: $";
    std::cin >> budget.transportation;

    std::cout << "Food: $";
    std::cin >> budget.food;

    std::cout << "Medical: $";
    std::cin >> budget.medical;

    std::cout << "Insurance: $";
    std::cin >> budget.insurance;

    std::cout << "Entertainment: $";
    std::cin >> budget.entertainment;

    std::cout << "Clothing: $";
    std::cin >> budget.clothing;

    std::cout << "Miscellaneous: $";
    std::cin >> budget.miscellaneous;
}

void displayBudgetReport(const MonthlyBudget& budget) {
    // Monthly budget amounts
    const double budgetAmounts[] = {500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 150.00, 75.00, 50.00};

    double totalOverUnder = 0.0;

    std::cout << "\n*** Budget Report ***\n";
    for (int i = 0; i < sizeof(budgetAmounts) / sizeof(budgetAmounts[0]); ++i) {
        double overUnder = budgetAmounts[i] - budget.housing;

        std::cout << "Category: ";
        switch (i) {
            case 0:
                std::cout << "Housing";
                break;
            case 1:
                std::cout << "Utilities";
                break;
            case 2:
                std::cout << "Household Expenses";
                break;
            case 3:
                std::cout << "Transportation";
                break;
            case 4:
                std::cout << "Food";
                break;
            case 5:
                std::cout << "Medical";
                break;
            case 6:
                std::cout << "Insurance";
                break;
            case 7:
                std::cout << "Entertainment";
                break;
            case 8:
                std::cout << "Clothing";
                break;
            case 9:
                std::cout << "Miscellaneous";
                break;
        }

        std::cout << "\tSpent: $" << budget.housing
                  << "\tBudgeted: $" << budgetAmounts[i]
                  << "\tOver/Under: $" << overUnder << std::endl;

        totalOverUnder += overUnder;
    }

    std::cout << "\nTotal Over/Under for the Entire Monthly Budget: $" << totalOverUnder << std::endl;
}