#include <iostream>
#include <iomanip>
#include <string>

const int MAX_TESTS = 5; // Maximum number of test scores

// Structure to store student data
struct Student {
    std::string name;
    int idNum;
    int* tests; // Pointer to an array of test scores
    double average;
    char grade;
};

// Function to dynamically allocate memory for test scores
void allocateTestScores(Student& student, int numTests) {
    student.tests = new int[numTests];
}

// Function to input data for a specific student
void inputStudentData(Student& student, int numTests) {
    std::cout << "Enter student name: ";
    std::getline(std::cin, student.name);

    std::cout << "Enter student ID number: ";
    std::cin >> student.idNum;

    // Dynamically allocate memory for test scores
    allocateTestScores(student, numTests);

    // Input test scores
    std::cout << "Enter test scores for " << student.name << ":\n";
    for (int i = 0; i < numTests; ++i) {
        do {
            std::cout << "Test " << i + 1 << ": ";
            std::cin >> student.tests[i];
            if (student.tests[i] < 0) {
                std::cout << "Please enter a non-negative value for test score.\n";
            }
        } while (student.tests[i] < 0);
    }
}

// Function to calculate average test score
void calculateAverage(Student& student, int numTests) {
    double total = 0;
    for (int i = 0; i < numTests; ++i) {
        total += student.tests[i];
    }
    student.average = total / numTests;
}

// Function to assign course grade based on the grading scale
void assignGrade(Student& student) {
    if (student.average >= 91) {
        student.grade = 'A';
    } else if (student.average >= 81) {
        student.grade = 'B';
    } else if (student.average >= 71) {
        student.grade = 'C';
    } else if (student.average >= 61) {
        student.grade = 'D';
    } else {
        student.grade = 'F';
    }
}

// Function to display student information
void displayStudentInfo(const Student students[], int numStudents, int numTests) {
    std::cout << std::setw(20) << "Student Name" << std::setw(15) << "ID Number" << std::setw(15) << "Average Score" << std::setw(15) << "Course Grade" << std::endl;
    std::cout << std::string(65, '-') << std::endl;

    for (int i = 0; i < numStudents; ++i) {
        std::cout << std::setw(20) << students[i].name
                  << std::setw(15) << students[i].idNum
                  << std::setw(15) << students[i].average
                  << std::setw(15) << students[i].grade << std::endl;
    }
}

// Function to deallocate memory for test scores
void deallocateTestScores(Student& student) {
    delete[] student.tests;
}

int main() {
    int numStudents, numTests;

    // Input the number of test scores and students
    std::cout << "Enter the number of test scores: ";
    std::cin >> numTests;

    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    // Create an array of structures to hold student data
    Student* students = new Student[numStudents];

    // Input data for each student
    for (int i = 0; i < numStudents; ++i) {
        std::cin.ignore(); // Clear the newline character from the previous input
        std::cout << "\nEnter data for Student " << i + 1 << ":\n";
        inputStudentData(students[i], numTests);
        calculateAverage(students[i], numTests);
        assignGrade(students[i]);
    }

    // Display student information
    std::cout << "\nStudent Information:\n";
    displayStudentInfo(students, numStudents, numTests);

    // Deallocate memory for test scores
    for (int i = 0; i < numStudents; ++i) {
        deallocateTestScores(students[i]);
    }

    // Deallocate memory for the array of structures
    delete[] students;

    return 0;
}
