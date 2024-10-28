#include "student.h"
// main.cpp
#include <iostream>

int main() {
    // Create a student using the default constructor
    Student student1;

    // Set basic student information using setters
    student1.setName("Alice");
    student1.setRollNumber(101);

    // Set subject-related information using setters
    student1.setNumSubjects(3);
    student1.setSubjectNames({"Math", "Physics", "History"});
    student1.setSubjectGrades({'A', 'B', 'C'});

    // Display student information using getters
    std::cout << "Student Name: " << student1.getName() << std::endl;
    std::cout << "Roll Number: " << student1.getRollNumber() << std::endl;

    // Display subject-related information using getters
    std::cout << "Number of Subjects: " << student1.getNumSubjects() << std::endl;
    std::cout << "Subject Names: ";
    // alternate without auto and autoincrement
    for (const auto& subject : student1.getSubjectNames()) {
        std::cout << subject << " ";
    }
    std::cout << std::endl;
    //Alternative loop
    //const std::vector<string>& subNames = student1.getSubjectNames();
	//for (size_t i = 0; i < subNames.size(); ++i) {
    	//std::cout << grades[i] << " ";
	//}


    std::cout << "Subject Grades: ";
    for (const auto& grade : student1.getSubjectGrades()) {
        std::cout << grade << " ";
    }
    std::cout << std::endl;

    //Alternative loop
    //const std::vector<char>& grades = student1.getSubjectGrades();
	//for (size_t i = 0; i < grades.size(); ++i) {
    	//std::cout << grades[i] << " ";
	//}


    // Calculate and display overall grade
    char overallGrade = student1.calculateOverallGrade();
    std::cout << "Overall Grade: " << overallGrade << std::endl;

    // Create another student using the overloaded constructor
    //Student student2("Bob", 102, 2, {"Chemistry", "English"}, {'B', 'A'});

    // Display the second student's information
    //std::cout << "\nStudent Name: " << student2.getName() << std::endl;
    //std::cout << "Roll Number: " << student2.getRollNumber() << std::endl;

    // Display subject-related information for the second student
    //std::cout << "Number of Subjects: " << student2.getNumSubjects() << std::endl;
    //std::cout << "Subject Names: ";
    //for (const auto& subject : student2.getSubjectNames()) {
    //    std::cout << subject << " ";
    //}
    //std::cout << std::endl;

    //std::cout << "Subject Grades: ";
    //for (const auto& grade : student2.getSubjectGrades()) {
    //    std::cout << grade << " ";
    //}
    //std::cout << std::endl;

    // Calculate and display overall grade for the second student
    //overallGrade = student2.calculateOverallGrade();
    //std::cout << "Overall Grade: " << overallGrade << std::endl;

    return 0;
}
