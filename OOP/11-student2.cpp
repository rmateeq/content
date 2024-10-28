#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    double gpa;

public:
    //default constructor
    Student() {
        name = "unknown";
        age = 0;
    }
    // Constructor for initializing student details
    Student(string n, int a) {
        name = n;
        age = a;
    }
    Student(string n, int a, double g) : name(n), age(a), gpa(g) {}

    // Mutator methods
    void setName(string n) {
        name = n;
    }

    void setAge(int a) {
        if (a > 0) {
            age = a;
        }
    }

    void setGPA(double g) {
        if (g >= 0 && g <= 4.0) {
            gpa = g;
        }
    }

    // Accessor methods
    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    double getGPA() const {
        return gpa;
    }

    // Member function to display student information
    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "GPA: " << gpa << endl;
    }
};

int main() {
    // Creating objects of the Student class
    //Student student1("Alice Johnson", 20, 3.8);
    //Student student2("Bob Smith", 22, 3.5);
    Student student1;
    Student student2("Bob Smith", 22);
    Student student3("Bob Smith", 22, 3.5);

    // Using accessor methods to retrieve and display student information
    cout << "Student 1 Information:" << endl;
    student1.displayInfo();
    cout << "Student 2 Information:" << endl;
    student2.displayInfo();
    cout << "Student 3 Information:" << endl;
    student3.displayInfo();
    //cout << "Name: " << student1.getName() << endl;
    //cout << "Age: " << student1.getAge() << endl;
    //cout << "GPA: " << student1.getGPA() << endl;
    //cout << endl;

    // Using mutator methods to modify student information
    //student2.setName("Robert Smith");
    //student2.setAge(23);
    //student2.setGPA(3.7);

    // Using member function to display modified student information
    //cout << "Student 2 Modified Information:" << endl;
    //student2.displayInfo();

    return 0;
}
