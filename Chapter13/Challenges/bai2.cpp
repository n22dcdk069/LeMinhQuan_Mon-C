#include <iostream>
#include <string>

class Employee {
private:
    std::string name;
    int idNumber;
    std::string department;
    std::string position;

public:
    // Constructor with all parameters
    Employee(std::string empName, int empIdNumber, std::string empDepartment, std::string empPosition)
        : name(empName), idNumber(empIdNumber), department(empDepartment), position(empPosition) {}

    // Constructor with name and ID number (department and position are set to empty strings)
    Employee(std::string empName, int empIdNumber)
        : name(empName), idNumber(empIdNumber), department(""), position("") {}

    // Default constructor
    Employee()
        : name(""), idNumber(0), department(""), position("") {}

    // Mutator functions
    void setName(std::string empName) {
        name = empName;
    }

    void setIdNumber(int empIdNumber) {
        idNumber = empIdNumber;
    }

    void setDepartment(std::string empDepartment) {
        department = empDepartment;
    }

    void setPosition(std::string empPosition) {
        position = empPosition;
    }

    // Accessor functions
    std::string getName() const {
        return name;
    }

    int getIdNumber() const {
        return idNumber;
    }

    std::string getDepartment() const {
        return department;
    }

    std::string getPosition() const {
        return position;
    }
};

int main() {
    // Create three Employee objects
    Employee employee1("Susan Meyers", 47899, "Accounting", "Vice President");
    Employee employee2("Mark Jones", 39119, "IT", "Programmer");
    Employee employee3("Joy Rogers", 81774, "Manufacturing", "Engineer");

    // Display employee information
    std::cout << "Employee 1 Information:\n";
    std::cout << "Name: " << employee1.getName() << "\nID Number: " << employee1.getIdNumber()
              << "\nDepartment: " << employee1.getDepartment() << "\nPosition: " << employee1.getPosition() << "\n\n";

    std::cout << "Employee 2 Information:\n";
    std::cout << "Name: " << employee2.getName() << "\nID Number: " << employee2.getIdNumber()
              << "\nDepartment: " << employee2.getDepartment() << "\nPosition: " << employee2.getPosition() << "\n\n";

    std::cout << "Employee 3 Information:\n";
    std::cout << "Name: " << employee3.getName() << "\nID Number: " << employee3.getIdNumber()
              << "\nDepartment: " << employee3.getDepartment() << "\nPosition: " << employee3.getPosition() << "\n";

    return 0;
}
