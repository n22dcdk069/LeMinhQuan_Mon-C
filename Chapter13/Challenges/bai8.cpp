#include <iostream>

class TestScores {
private:
    double test1;
    double test2;
    double test3;

public:
    // Constructor
    TestScores(double t1, double t2, double t3) : test1(t1), test2(t2), test3(t3) {}

    // Mutator functions
    void setTest1(double t1) {
        test1 = t1;
    }

    void setTest2(double t2) {
        test2 = t2;
    }

    void setTest3(double t3) {
        test3 = t3;
    }

    // Accessor functions
    double getTest1() const {
        return test1;
    }

    double getTest2() const {
        return test2;
    }

    double getTest3() const {
        return test3;
    }

    // Member function to calculate and return the average of test scores
    double calculateAverage() const {
        return (test1 + test2 + test3) / 3.0;
    }
};

int main() {
    double score1, score2, score3;

    // Get user input for test scores
    std::cout << "Enter Test Score 1: ";
    std::cin >> score1;

    std::cout << "Enter Test Score 2: ";
    std::cin >> score2;

    std::cout << "Enter Test Score 3: ";
    std::cin >> score3;

    // Create an instance of the TestScores class
    TestScores myTestScores(score1, score2, score3);

    // Display the entered test scores and their average
    std::cout << "\nTest Scores:\n";
    std::cout << "Test 1: " << myTestScores.getTest1() << std::endl;
    std::cout << "Test 2: " << myTestScores.getTest2() << std::endl;
    std::cout << "Test 3: " << myTestScores.getTest3() << std::endl;

    std::cout << "\nAverage Test Score: " << myTestScores.calculateAverage() << std::endl;

    return 0;
}
