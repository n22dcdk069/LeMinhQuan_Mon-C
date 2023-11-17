#include <iostream>
#include <iomanip>
#include <string>

const int NUM_SPEAKERS = 5;

// Structure to store speaker information
struct Speaker {
    std::string speakerName;
    std::string speakingTopic;
    int phoneNumber;
    double speakingFee;
};

// Function to input data for a specific speaker
void inputSpeakerData(Speaker& speaker) {
    std::cout << "Enter speaker's name: ";
    std::getline(std::cin, speaker.speakerName);

    std::cout << "Enter speaking topic: ";
    std::getline(std::cin, speaker.speakingTopic);

    std::cout << "Enter phone number: ";
    std::cin >> speaker.phoneNumber;

    std::cout << "Enter speaking fee: $";
    std::cin >> speaker.speakingFee;
}

// Function to display speaker information
void displaySpeakerInfo(const Speaker speakers[], int numSpeakers) {
    std::cout << std::setw(20) << "Speaker Name" << std::setw(25) << "Speaking Topic" << std::setw(15) << "Phone Number" << std::setw(15) << "Speaking Fee" << std::endl;
    std::cout << std::string(75, '-') << std::endl;

    for (int i = 0; i < numSpeakers; ++i) {
        std::cout << std::setw(20) << speakers[i].speakerName
                  << std::setw(25) << speakers[i].speakingTopic
                  << std::setw(15) << speakers[i].phoneNumber
                  << std::setw(15) << speakers[i].speakingFee << std::endl;
    }
}

// Function to search for a speaker based on a keyword in the Speaking Topic field
void searchByTopic(const Speaker speakers[], int numSpeakers, const std::string& keyword) {
    bool found = false;

    std::cout << "\nSearch Results for '" << keyword << "' in Speaking Topic:\n";
    std::cout << std::setw(20) << "Speaker Name" << std::setw(25) << "Speaking Topic" << std::setw(15) << "Phone Number" << std::setw(15) << "Speaking Fee" << std::endl;
    std::cout << std::string(75, '-') << std::endl;

    for (int i = 0; i < numSpeakers; ++i) {
        size_t foundPos = speakers[i].speakingTopic.find(keyword);
        if (foundPos != std::string::npos) {
            std::cout << std::setw(20) << speakers[i].speakerName
                      << std::setw(25) << speakers[i].speakingTopic
                      << std::setw(15) << speakers[i].phoneNumber
                      << std::setw(15) << speakers[i].speakingFee << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No speakers match the entered keyword in the Speaking Topic.\n";
    }
}

int main() {
    Speaker speakers[NUM_SPEAKERS];

    // Input data for each speaker
    for (int i = 0; i < NUM_SPEAKERS; ++i) {
        std::cout << "\nEnter data for Speaker " << i + 1 << ":\n";
        inputSpeakerData(speakers[i]);
    }

    // Display speaker information
    std::cout << "\nSpeaker Information:\n";
    displaySpeakerInfo(speakers, NUM_SPEAKERS);

    // Ask the user to search for a speaker by topic
    std::string keyword;
    std::cout << "\nEnter keyword to search for in Speaking Topic: ";
    std::getline(std::cin, keyword);

    // Search for speakers based on keyword in the Speaking Topic
    searchByTopic(speakers, NUM_SPEAKERS, keyword);

    return 0;
}
