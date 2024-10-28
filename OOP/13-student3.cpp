#include <iostream>
using namespace std;

class Student {
public:
    // Default constructor
    Student() : name("Unknown"), age(0) {}

    // Parameterized constructor
    Student(const string& n, int a) : name(n), age(a) {}

    // Display student information
    void displayInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

private:
    string name;
    int age;
};

int main() {
    int numStudents;
    // User input: Number of students
    cout << "Enter the number of students: ";
    cin >> numStudents;

    // Dynamically allocate memory for an array of student objects
    Student* studentArray = new Student[numStudents];

    // User input: Details for each student
    for (int i = 0; i < numStudents; ++i) {
        string name;
        int age;

        cout << "Enter the name of student " << i + 1 << ": ";
        cin >> name;

        cout << "Enter the age of student " << i + 1 << ": ";
        cin >> age;

        // Initialize each student object in the array
        studentArray[i] = Student(name, age);
    }
    // Display information for each student
    cout << "\nStudent Information:\n";
    for (int i = 0; i < numStudents; ++i) {
        studentArray[i].displayInfo();
    }

    // Release dynamically allocated memory
    delete[] studentArray;

    return 0;
}