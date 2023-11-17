#include <iostream>
#include <string>

class Question {
private:
    std::string questionText;
    std::string answers[4];
    int correctAnswer;

public:
    // Constructor
    Question(const std::string& question, const std::string& ans1, const std::string& ans2,
             const std::string& ans3, const std::string& ans4, int correct)
        : questionText(question), correctAnswer(correct) {
        answers[0] = ans1;
        answers[1] = ans2;
        answers[2] = ans3;
        answers[3] = ans4;
    }

    // Accessor functions
    std::string getQuestion() const {
        return questionText;
    }

    std::string getAnswer(int index) const {
        if (index >= 0 && index < 4) {
            return answers[index];
        } else {
            std::cerr << "Invalid answer index.\n";
            exit(1); // Exit program with an error code
        }
    }

    int getCorrectAnswer() const {
        return correctAnswer;
    }
};

class TriviaGame {
private:
    static const int NUM_QUESTIONS = 10;
    Question questions[NUM_QUESTIONS];
    int playerScores[2];

public:
    // Constructor
    TriviaGame() : playerScores{0, 0} {
        // Populate the array with trivia questions
        questions[0] = Question("What is the capital of France?", "Berlin", "Paris", "Madrid", "Rome", 2);
        // Add more questions here...

        // Populate the array with your own trivia questions
        // ...

        // Add more questions here...
    }

    // Member function to play the game
    void playGame() {
        for (int currentPlayer = 0; currentPlayer < 2; ++currentPlayer) {
            std::cout << "Player " << currentPlayer + 1 << "'s turn:\n";

            for (int i = 0; i < NUM_QUESTIONS; ++i) {
                std::cout << "\nQuestion " << i + 1 << ": " << questions[i].getQuestion() << std::endl;

                // Display possible answers
                for (int j = 0; j < 4; ++j) {
                    std::cout << j + 1 << ". " << questions[i].getAnswer(j) << std::endl;
                }

                // Get player's answer
                int playerAnswer;
                std::cout << "Your answer (1-4): ";
                std::cin >> playerAnswer;

                // Check if the answer is correct
                if (playerAnswer == questions[i].getCorrectAnswer()) {
                    std::cout << "Correct!\n";
                    playerScores[currentPlayer]++;
                } else {
                    std::cout << "Incorrect. The correct answer is: " << questions[i].getCorrectAnswer() << ".\n";
                }
            }

            std::cout << "\nPlayer " << currentPlayer + 1 << "'s score: " << playerScores[currentPlayer] << "\n\n";
        }

        // Determine the winner
        if (playerScores[0] > playerScores[1]) {
            std::cout << "Player 1 is the winner!\n";
        } else if (playerScores[0] < playerScores[1]) {
            std::cout << "Player 2 is the winner!\n";
        } else {
            std::cout << "It's a tie!\n";
        }
    }
};

int main() {
    TriviaGame trivia;
    trivia.playGame();

    return 0;
}
