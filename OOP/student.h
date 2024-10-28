#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {

private:
    // Data members for basic student information
    string name;
    int rollNumber;

    // Data members for subject-related information
    int numSubjects;
    vector<string> subjectNames; // an array of strings
    vector<char> subjectGrades;

public:
    // Default constructor
    Student();  // only declared, not defined

    // Overloaded constructor with basic student information
    Student(string studentName, int roll);

    // Overloaded constructor with basic student and subject information
    Student(string studentName, int roll, int numSub, const vector<string>& subNames);

    // Getter methods for basic student information
    string getName() const;
    int getRollNumber() const;

    // Getter methods for subject-related information
    int getNumSubjects() const;
    vector<string> getSubjectNames() const;
    vector<char> getSubjectGrades() const;

    // Setter methods for basic student information
    void setName(string studentName);
    void setRollNumber(int roll);

    // Setter methods for subject-related information
    void setNumSubjects(int numSub);
    void setSubjectNames(const vector<string>&& subNames);
    void setSubjectGrades(const vector<char>&& subGrades);

    // Method to calculate overall grade based on subject grades
    char calculateOverallGrade() const;
};
#endif