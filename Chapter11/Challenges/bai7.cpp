#include <iostream>
#include <string>

// Define the structure for customer account data
struct CustomerAccount {
    std::string name;
    std::string address;
    std::string cityStateZip;
    std::string phoneNumber;
    double accountBalance;
    std::string dateLastPayment;
};

const int MAX_ACCOUNTS = 10;

// Function prototypes
void displayMenu();
void enterData(CustomerAccount accounts[], int& currentSize);
void changeContents(CustomerAccount accounts[], int currentSize);
void displayData(const CustomerAccount accounts[], int currentSize);

int main() {
    CustomerAccount accounts[MAX_ACCOUNTS];
    int currentSize = 0;
    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                enterData(accounts, currentSize);
                break;
            case 2:
                changeContents(accounts, currentSize);
                break;
            case 3:
                displayData(accounts, currentSize);
                break;
            case 4:
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    std::cout << "\n*** Customer Account Management ***\n";
    std::cout << "1. Enter Data\n";
    std::cout << "2. Change Contents\n";
    std::cout << "3. Display Data\n";
    std::cout << "4. Exit\n";
}

void enterData(CustomerAccount accounts[], int& currentSize) {
    if (currentSize < MAX_ACCOUNTS) {
        CustomerAccount newAccount;
        std::cout << "Enter data for a new account:\n";

        std::cout << "Name: ";
        std::cin.ignore(); // Clear the input buffer
        std::getline(std::cin, newAccount.name);

        std::cout << "Address: ";
        std::getline(std::cin, newAccount.address);

        std::cout << "City, State, and ZIP: ";
        std::getline(std::cin, newAccount.cityStateZip);

        std::cout << "Telephone Number: ";
        std::getline(std::cin, newAccount.phoneNumber);

        do {
            std::cout << "Account Balance: $";
            std::cin >> newAccount.accountBalance;
        } while (newAccount.accountBalance < 0);

        std::cout << "Date of Last Payment: ";
        std::cin.ignore(); // Clear the input buffer
        std::getline(std::cin, newAccount.dateLastPayment);

        accounts[currentSize] = newAccount;
        currentSize++;

        std::cout << "Account added successfully!\n";
    } else {
        std::cout << "Cannot add more accounts. The maximum limit is reached.\n";
    }
}

void changeContents(CustomerAccount accounts[], int currentSize) {
    if (currentSize > 0) {
        int accountIndex;
        std::cout << "Enter the index of the account to change contents (0-" << currentSize - 1 << "): ";
        std::cin >> accountIndex;

        if (accountIndex >= 0 && accountIndex < currentSize) {
            std::cout << "Enter new data for the account:\n";

            std::cout << "Name: ";
            std::cin.ignore(); // Clear the input buffer
            std::getline(std::cin, accounts[accountIndex].name);

            std::cout << "Address: ";
            std::getline(std::cin, accounts[accountIndex].address);

            std::cout << "City, State, and ZIP: ";
            std::getline(std::cin, accounts[accountIndex].cityStateZip);

            std::cout << "Telephone Number: ";
            std::getline(std::cin, accounts[accountIndex].phoneNumber);

            do {
                std::cout << "Account Balance: $";
                std::cin >> accounts[accountIndex].accountBalance;
            } while (accounts[accountIndex].accountBalance < 0);

            std::cout << "Date of Last Payment: ";
            std::cin.ignore(); // Clear the input buffer
            std::getline(std::cin, accounts[accountIndex].dateLastPayment);

            std::cout << "Account contents changed successfully!\n";
        } else {
            std::cout << "Invalid account index. Please enter a valid index.\n";
        }
    } else {
        std::cout << "No accounts available. Please enter data for accounts first.\n";
    }
}

void displayData(const CustomerAccount accounts[], int currentSize) {
    if (currentSize > 0) {
        std::cout << "\n*** Customer Account Information ***\n";
        for (int i = 0; i < currentSize; ++i) {
            std::cout << "Account " << i << ":\n";
            std::cout << "Name: " << accounts[i].name << "\n";
            std::cout << "Address: " << accounts[i].address << "\n";
            std::cout << "City, State, and ZIP: " << accounts[i].cityStateZip << "\n";
            std::cout << "Telephone Number: " << accounts[i].phoneNumber << "\n";
            std::cout << "Account Balance: $" << accounts[i].accountBalance << "\n";
            std::cout << "Date of Last Payment: " << accounts[i].dateLastPayment << "\n";
            std::cout << "-----------------------------\n";
        }
    } else {
        std::cout << "No accounts available. Please enter data for accounts first.\n";
    }
}
