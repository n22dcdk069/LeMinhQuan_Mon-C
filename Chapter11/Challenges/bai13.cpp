#include <iostream>
#include <iomanip>
#include <limits>

// Define the structure for the drink data
struct Drink {
    std::string name;
    double cost;
    int quantity;
};

// Function prototypes
void displayMenu(const Drink drinks[], int size);
int getUserChoice(int size);
double getMoneyInput();
void processUserChoice(Drink& selectedDrink, double moneyInserted);

int main() {
    const int NUM_DRINKS = 5;
    Drink drinks[NUM_DRINKS] = {
        {"Cola", 0.75, 20},
        {"Root Beer", 0.75, 20},
        {"Lemon-Lime", 0.75, 20},
        {"Grape Soda", 0.80, 20},
        {"Cream Soda", 0.80, 20}
    };

    double totalEarnings = 0.0;

    do {
        displayMenu(drinks, NUM_DRINKS);
        int choice = getUserChoice(NUM_DRINKS);

        if (choice == 0) {
            // User chose to quit
            break;
        } else {
            // Process user's drink choice
            Drink& selectedDrink = drinks[choice - 1];
            double moneyInserted = getMoneyInput();
            processUserChoice(selectedDrink, moneyInserted);

            // Update total earnings
            totalEarnings += selectedDrink.cost;
        }
    } while (true);

    std::cout << "Total earnings: $" << std::fixed << std::setprecision(2) << totalEarnings << std::endl;

    return 0;
}

void displayMenu(const Drink drinks[], int size) {
    std::cout << "\n*** Soft Drink Machine ***\n";
    std::cout << "0. Quit\n";

    for (int i = 0; i < size; ++i) {
        std::cout << i + 1 << ". " << std::setw(12) << std::left << drinks[i].name
                  << "$" << std::fixed << std::setprecision(2) << drinks[i].cost
                  << "  Quantity: " << drinks[i].quantity << "\n";
    }
}

int getUserChoice(int size) {
    int choice;
    std::cout << "Enter your choice (0 to quit): ";
    std::cin >> choice;

    while (std::cin.fail() || choice < 0 || choice > size) {
        std::cin.clear(); // Clear input buffer to restore cin to a usable state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore last input
        std::cout << "Invalid choice. Enter a number between 0 and " << size << ": ";
        std::cin >> choice;
    }

    return choice;
}

double getMoneyInput() {
    double moneyInserted;
    std::cout << "Enter the amount of money to insert (up to $1.00): $";
    std::cin >> moneyInserted;

    while (std::cin.fail() || moneyInserted < 0 || moneyInserted > 1.00) {
        std::cin.clear(); // Clear input buffer to restore cin to a usable state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore last input
        std::cout << "Invalid amount. Enter a value between 0 and $1.00: $";
        std::cin >> moneyInserted;
    }

    return moneyInserted;
}

void processUserChoice(Drink& selectedDrink, double moneyInserted) {
    if (selectedDrink.quantity > 0 && moneyInserted >= selectedDrink.cost) {
        double change = moneyInserted - selectedDrink.cost;

        std::cout << "Dispensing " << selectedDrink.name << ". Change: $" << std::fixed << std::setprecision(2) << change << "\n";
        selectedDrink.quantity--;
    } else if (selectedDrink.quantity == 0) {
        std::cout << "Sorry, " << selectedDrink.name << " is sold out.\n";
    } else {
        std::cout << "Insufficient funds. Please insert more money.\n";
    }
}
