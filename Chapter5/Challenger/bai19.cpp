#include <iostream>

int main() {
    double budgetAmount;
    double totalExpenses = 0.0;
    double expense;

    // Get the budgeted amount from the user
    std::cout << "Enter the budgeted amount for the month: $";
    std::cin >> budgetAmount;

    // Loop to prompt the user to enter expenses
    char addAnotherExpense;
    do {
        std::cout << "Enter an expense amount: $";
        std::cin >> expense;

        // Input validation: Ensure expense is non-negative
        while (expense < 0) {
            std::cout << "Expense cannot be negative. Please re-enter the expense amount: $";
            std::cin >> expense;
        }

        // Add the expense to the total
        totalExpenses += expense;

        // Ask if the user wants to add another expense
        std::cout << "Do you want to add another expense? (y/n): ";
        std::cin >> addAnotherExpense;

    } while (addAnotherExpense == 'y' || addAnotherExpense == 'Y');

    // Display the budget status
    double difference = totalExpenses - budgetAmount;
    std::cout << "\nBudget Summary:\n"
              << "Budgeted amount: $" << budgetAmount << "\n"
              << "Total expenses: $" << totalExpenses << "\n";

    if (difference >= 0) {
        std::cout << "You are over budget by $" << difference << std::endl;
    } else {
        std::cout << "You are under budget by $" << -difference << std::endl;
    }

    return 0;
}
