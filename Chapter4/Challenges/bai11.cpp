#include <iostream>
#include <cstdlib>  // For rand() and srand() functions
#include <ctime>    // For time() function

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Generate two random numbers between 100 and 999
    int num1 = rand() % 900 + 100;
    int num2 = rand() % 900 + 100;

    // Display the addition problem
    std::cout << "  " << num1 << std::endl;
    std::cout << "+ " << num2 << std::endl;
    std::cout << "-------" << std::endl;

    // Get the student's answer
    int studentAnswer;
    std::cout << "Enter your answer: ";
    std::cin >> studentAnswer;

    // Calculate the correct answer
    int correctAnswer = num1 + num2;

    // Check if the answer is correct and provide feedback
    if (studentAnswer == correctAnswer) {
        std::cout << "Congratulations! Your answer is correct." << std::endl;
    } else {
        std::cout << "Sorry, the correct answer is: " << correctAnswer << std::endl;
    }

    return 0;
}
