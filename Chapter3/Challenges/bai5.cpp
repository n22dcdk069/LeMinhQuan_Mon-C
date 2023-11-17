#include <iostream>
using namespace std;

int main() {
    // Variables to store the number of males and females
    int numMales, numFemales;

    // Get user input for the number of males
    cout << "Enter the number of males in the class: ";
    cin >> numMales;

    // Get user input for the number of females
    cout << "Enter the number of females in the class: ";
    cin >> numFemales;

    // Calculate the total number of students and the percentages
    int totalStudents = numMales + numFemales;
    double percentMales = (static_cast<double>(numMales) / totalStudents) * 100;
    double percentFemales = (static_cast<double>(numFemales) / totalStudents) * 100;

    // Display the percentages with two decimal places
    cout << "Percentage of males: " << percentMales << "%" << endl;
    cout << "Percentage of females: " << percentFemales << "%" << endl;

    return 0;
}