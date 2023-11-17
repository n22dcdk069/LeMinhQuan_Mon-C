#include <iostream>
#include <string>

// Define the structure for speaker data
struct Speaker {
    std::string name;
    std::string phoneNumber;
    std::string speakingTopic;
    double feeRequired;
};

const int MAX_SPEAKERS = 10;

// Function prototypes
void displayMenu();
void enterData(Speaker speakers[], int& currentSize);
void changeContents(Speaker speakers[], int currentSize);
void displayData(const Speaker speakers[], int currentSize);

int main() {
    Speaker speakers[MAX_SPEAKERS];
    int currentSize = 0;
    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                enterData(speakers, currentSize);
                break;
            case 2:
                changeContents(speakers, currentSize);
                break;
            case 3:
                displayData(speakers, currentSize);
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
    std::cout << "\n*** Speakers Bureau Management ***\n";
    std::cout << "1. Enter Data\n";
    std::cout << "2. Change Contents\n";
    std::cout << "3. Display Data\n";
    std::cout << "4. Exit\n";
}

void enterData(Speaker speakers[], int& currentSize) {
    if (currentSize < MAX_SPEAKERS) {
        Speaker newSpeaker;
        std::cout << "Enter data for a new speaker:\n";

        std::cout << "Name: ";
        std::cin.ignore(); // Clear the input buffer
        std::getline(std::cin, newSpeaker.name);

        std::cout << "Telephone Number: ";
        std::getline(std::cin, newSpeaker.phoneNumber);

        std::cout << "Speaking Topic: ";
        std::getline(std::cin, newSpeaker.speakingTopic);

        do {
            std::cout << "Fee Required: $";
            std::cin >> newSpeaker.feeRequired;
        } while (newSpeaker.feeRequired < 0);

        speakers[currentSize] = newSpeaker;
        currentSize++;

        std::cout << "Speaker added successfully!\n";
    } else {
        std::cout << "Cannot add more speakers. The maximum limit is reached.\n";
    }
}

void changeContents(Speaker speakers[], int currentSize) {
    if (currentSize > 0) {
        int speakerIndex;
        std::cout << "Enter the index of the speaker to change contents (0-" << currentSize - 1 << "): ";
        std::cin >> speakerIndex;

        if (speakerIndex >= 0 && speakerIndex < currentSize) {
            std::cout << "Enter new data for the speaker:\n";

            std::cout << "Name: ";
            std::cin.ignore(); // Clear the input buffer
            std::getline(std::cin, speakers[speakerIndex].name);

            std::cout << "Telephone Number: ";
            std::getline(std::cin, speakers[speakerIndex].phoneNumber);

            std::cout << "Speaking Topic: ";
            std::getline(std::cin, speakers[speakerIndex].speakingTopic);

            do {
                std::cout << "Fee Required: $";
                std::cin >> speakers[speakerIndex].feeRequired;
            } while (speakers[speakerIndex].feeRequired < 0);

            std::cout << "Speaker contents changed successfully!\n";
        } else {
            std::cout << "Invalid speaker index. Please enter a valid index.\n";
        }
    } else {
        std::cout << "No speakers available. Please enter data for speakers first.\n";
    }
}

void displayData(const Speaker speakers[], int currentSize) {
    if (currentSize > 0) {
        std::cout << "\n*** Speakers Information ***\n";
        for (int i = 0; i < currentSize; ++i) {
            std::cout << "Speaker " << i << ":\n";
            std::cout << "Name: " << speakers[i].name << "\n";
            std::cout << "Telephone Number: " << speakers[i].phoneNumber << "\n";
            std::cout << "Speaking Topic: " << speakers[i].speakingTopic << "\n";
            std::cout << "Fee Required: $" << speakers[i].feeRequired << "\n";
            std::cout << "-----------------------------\n";
        }
    } else {
        std::cout << "No speakers available. Please enter data for speakers first.\n";
    }
}
