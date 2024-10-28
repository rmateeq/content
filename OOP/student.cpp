#include "student.h"

// Default constructor
Student::Student() : rollNumber(0), numSubjects(0) {
    // Default values for basic student information
    name = "Unknown";
}

// Overloaded constructor with basic student information
Student::Student(string studentName, int roll) : rollNumber(roll), numSubjects(0) {
    name = studentName;
}

// Overloaded constructor with basic student and subject information
Student::Student(string studentName, int roll, int numSub, const vector<string>& subNames)
    : rollNumber(roll), numSubjects(numSub), subjectNames(subNames) {
    name = studentName;
}

// Getter methods for basic student information
string Student::getName() const {
    return name;
}

int Student::getRollNumber() const {
    return rollNumber;
}

// Getter methods for subject-related information
int Student::getNumSubjects() const {
    return numSubjects;
}

vector<string> Student::getSubjectNames() const {
    return subjectNames;
}

vector<char> Student::getSubjectGrades() const {
    return subjectGrades;
}

// Setter methods for basic student information
void Student::setName(string studentName) {
    name = studentName;
}

void Student::setRollNumber(int roll) {
    rollNumber = roll;
}

// Setter methods for subject-related information
void Student::setNumSubjects(int numSub) {
    numSubjects = numSub;
}

void Student::setSubjectNames(const vector<std::string>&& subNames) {
    subjectNames = subNames;
}

void Student::setSubjectGrades(const vector<char>&& subGrades) {
    subjectGrades = subGrades;
}

// Method to calculate overall grade based on subject grades
char Student::calculateOverallGrade() const {
    if (subjectGrades.empty()) {
        return 'N'; // Not enough data to calculate the overall grade
    }

    int totalMarks = 0;
    for (char grade : subjectGrades) {
        switch (grade) {
            case 'A':
                totalMarks += 90;
                break;
            case 'B':
                totalMarks += 80;
                break;
            case 'C':
                totalMarks += 70;
                break;
            case 'D':
                totalMarks += 60;
                break;
            case 'F':
                totalMarks += 50;
                break;
            default:
                totalMarks += 0;
        }
    }
    // Alternative with if else
    // const std::vector<char>& subjectGrades = student1.getSubjectGrades();
    // for (size_t i = 0; i < subjectGrades.size(); ++i) {
    //     char grade = subjectGrades[i];

    //     if (grade == 'A') {
    //         totalMarks += 90;
    //     } else if (grade == 'B') {
    //         totalMarks += 80;
    //     } else if (grade == 'C') {
    //         totalMarks += 70;
    //     } else if (grade == 'D') {
    //         totalMarks += 60;
    //     } else if (grade == 'F') {
    //         totalMarks += 50;
    //     } else {
    //         totalMarks += 0;
    //     }
    // }



    // Calculate the average and map it to a grade
    int averageMarks = totalMarks / subjectGrades.size();
    if (averageMarks >= 90) {
        return 'A';
    } else if (averageMarks >= 80) {
        return 'B';
    } else if (averageMarks >= 70) {
        return 'C';
    } else if (averageMarks >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}
