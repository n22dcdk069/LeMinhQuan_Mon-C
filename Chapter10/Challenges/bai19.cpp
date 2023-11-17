#include <iostream>
#include <iomanip>
#include <string>

std::string spellOutAmount(double amount) {
    // Define words for numbers
    const std::string units[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    const std::string teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    const std::string tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    // Function to spell out a number less than 1000
    auto spellOutLessThan1000 = [&](int num) -> std::string {
        std::string result;

        if (num >= 100) {
            result += units[num / 100] + " hundred ";
            num %= 100;
        }

        if (num >= 20) {
            result += tens[num / 10] + " ";
            num %= 10;
        } else if (num >= 11 && num <= 19) {
            result += teens[num - 10] + " ";
            return result;
        }

        result += units[num] + " ";
        return result;
    };

    std::string result;

    // Calculate dollars and cents
    int dollars = static_cast<int>(amount);
    int cents = static_cast<int>((amount - dollars) * 100);

    // Spell out dollars
    if (dollars >= 1000) {
        result += spellOutLessThan1000(dollars / 1000) + "thousand ";
        dollars %= 1000;
    }

    result += spellOutLessThan1000(dollars) + "dollars ";

    // Spell out cents
    result += "and " + spellOutLessThan1000(cents) + "cents";

    return result;
}

int main() {
    // Get user input
    std::string date, payeeName;
    double amount;

    // Input validation for the amount
    do {
        std::cout << "Enter the date (mm/dd/yyyy): ";
        std::getline(std::cin, date);

        std::cout << "Enter the payee's name: ";
        std::getline(std::cin, payeeName);

        std::cout << "Enter the amount of the check (up to $10,000): $";
        std::cin >> amount;

        if (std::cin.fail() || amount < 0 || amount > 10000) {
            std::cin.clear(); // clear input buffer to restore cin to a usable state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore last input
            std::cout << "Invalid input. Please enter a non-negative amount up to $10,000.\n";
        } else {
            break;
        }
    } while (true);

    // Display the simulated paycheck
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Date: " << date << std::endl;
    std::cout << "Pay to the Order of: " << payeeName << " $" << amount << std::endl;
    std::cout << spellOutAmount(amount) << std::endl;

    return 0;
}
