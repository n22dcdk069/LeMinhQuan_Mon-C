#include <iostream>
#include <iomanip>
#include <string>

const int NUM_CUSTOMERS = 5;

// Structure to store customer account data
struct CustomerAccount {
    std::string customerName;
    int accountNumber;
    double balance;
};

// Function to input data for a specific customer account
void inputCustomerData(CustomerAccount& customer) {
    std::cout << "Enter customer's name: ";
    std::getline(std::cin, customer.customerName);

    std::cout << "Enter account number: ";
    std::cin >> customer.accountNumber;

    std::cout << "Enter balance: ";
    std::cin >> customer.balance;
}

// Function to display customer account information
void displayCustomerInfo(const CustomerAccount customers[], int numCustomers) {
    std::cout << std::setw(20) << "Customer Name" << std::setw(15) << "Account Number" << std::setw(15) << "Balance" << std::endl;
    std::cout << std::string(50, '-') << std::endl;

    for (int i = 0; i < numCustomers; ++i) {
        std::cout << std::setw(20) << customers[i].customerName
                  << std::setw(15) << customers[i].accountNumber
                  << std::setw(15) << customers[i].balance << std::endl;
    }
}

// Function to search for a customer account based on a partial name match
void searchByName(const CustomerAccount customers[], int numCustomers, const std::string& partialName) {
    bool found = false;

    std::cout << "\nSearch Results for '" << partialName << "':\n";
    std::cout << std::setw(20) << "Customer Name" << std::setw(15) << "Account Number" << std::setw(15) << "Balance" << std::endl;
    std::cout << std::string(50, '-') << std::endl;

    for (int i = 0; i < numCustomers; ++i) {
        size_t foundPos = customers[i].customerName.find(partialName);
        if (foundPos != std::string::npos) {
            std::cout << std::setw(20) << customers[i].customerName
                      << std::setw(15) << customers[i].accountNumber
                      << std::setw(15) << customers[i].balance << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No accounts match the entered partial name.\n";
    }
}

int main() {
    CustomerAccount accounts[NUM_CUSTOMERS];

    // Input data for each customer account
    for (int i = 0; i < NUM_CUSTOMERS; ++i) {
        std::cout << "\nEnter data for Customer " << i + 1 << ":\n";
        inputCustomerData(accounts[i]);
    }

    // Display customer account information
    std::cout << "\nCustomer Account Information:\n";
    displayCustomerInfo(accounts, NUM_CUSTOMERS);

    // Ask the user to search for a customer by partial name
    std::string partialName;
    std::cout << "\nEnter partial name to search for: ";
    std::getline(std::cin, partialName);

    // Search for customer accounts based on partial name match
    searchByName(accounts, NUM_CUSTOMERS, partialName);

    return 0;
}
